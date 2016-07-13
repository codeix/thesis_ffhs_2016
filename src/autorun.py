#!/usr/bin/env python3

import os
import sys
import csv
import time
import random
import serial
import paramiko
import itertools
import threading
import statistics
import configparser
from collections import defaultdict
from collections import OrderedDict


BENCHPATH = 'cat /proc/benchmark/%s'
READ_TIME_INTERVAL = 0
REPEAT = 3
BREAK_TIME = 60


class PeakTech2015(object):

    ser = None
    value_buffer = None
    thread = None
    halt = False
    starttime = None

    def __init__(self, port='/dev/ttyUSB0'):

        self.ser = serial.Serial(
            port=port,
            baudrate=2400,
            parity=serial.PARITY_ODD,
            stopbits=serial.STOPBITS_TWO,
            bytesize=serial.SEVENBITS
        )
        self.thread = threading.Thread(target=self.reader)
        self.thread.start()

    def set_buffer(self):
        self.starttime = time.time()
        self.ser.reset_input_buffer()
        self.value_buffer = list()

    def get_values(self):
        b = self.value_buffer
        self.value_buffer = None
        return b

    def close(self):
        self.halt = True
        self.thread.join()
        self.ser.close()

    def reader(self):
        while not self.halt:
            self.ser.reset_input_buffer()
            stream = self.ser.readline()
            if len(stream) != 14:
                time.sleep(1)
                continue
            value = abs(int(stream.decode()[:5]))
            if self.value_buffer is not None:
                value = float(value)/10
                self.value_buffer.append((time.time() - self.starttime, value))
                time.sleep(READ_TIME_INTERVAL)


class Board(object):

    ssh = None

    def __init__(self, host, username):
        self.ssh = paramiko.SSHClient()
        self.ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        self.ssh.connect(host, username=username)

    def benchmark(self, bench):
        cmd = BENCHPATH % bench
        ssh_stdin, ssh_stdout, ssh_stderr = self.ssh.exec_command(cmd)
        return ssh_stdout.readline().strip()

    def close(self):
        self.ssh.close()

def save_latex(val):
    return val.replace('_', '\_')


def write(all_data, order, output):
    for index, benchmark in enumerate(order):
        data = all_data[benchmark]
        with open(os.path.join(output, 'data%i.csv' % index), 'w', newline='') as csvfile:
            fieldnames = list()
            for rep in range(REPEAT):
                fieldnames += ['time%s' % rep, 'amp%s' % rep]
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            writer.writeheader()
            for i in itertools.count(start=0, step=1):
                row = list()
                for rep in range(REPEAT):
                    try:
                        t, a = data[rep]['values'][i]
                        row.append(('time%s' % rep, int(t) * 1000))
                        row.append(('amp%s' % rep, a))
                    except IndexError:
                        pass
                if len(row):
                    writer.writerow(dict(row))
                else:
                    break
        with open(os.path.join(output, 'data%i.tex' % index), 'w') as texfile:
           median_values = list()
           mean_values = list()
           for rep in range(REPEAT):
               values = dict(data[rep]['values']).values()
               mean = statistics.mean(values)
               median = statistics.median(values)
               median_values.append(round(median))
               mean_values.append(round(mean, 2))
           texfile.write('\\def\\median{{%s}}%%\n' % ', '.join(['"%s"' % i for i in median_values]))
           texfile.write('\\def\\average{{%s}}%%\n' % ', '.join(['"%s"' % i for i in mean_values]))
           texfile.write('\\def\\run{{%s}}%%\n' % ', '.join(['"%s"' % (data[i]['run'] + 1) for i in range(REPEAT)]))
           texfile.write('\\def\\exectime{{%s}}%%\n' % ', '.join(['"%s"' % data[i]['time']  for i in range(REPEAT)]))
           texfile.write('\\def\\benchmark{%s}%%\n' % save_latex(benchmark))
           texfile.write('\\def\\description{%s}%%\n' % save_latex(data[0]['config']['desc']))

def main():

    if len(sys.argv) != 6:
        ex1 = '    Example: autorun.py /dev/ttyUSB0 192.168.1.100 pi raspberry/benchmark_data.ini ../results/raspberrydata/\n'
        ex2 = '    Example: autorun.py /dev/ttyUSB0 192.168.1.76 pi galileo/benchmark_data.ini ../results/galileodata/'
        print('Usage: autorun.py <port> <host> <username> <benchmark_data> <output>\n' + ex1 + ex2)
        sys.exit(1)

    port = sys.argv[1]
    host = sys.argv[2]
    username = sys.argv[3]
    benchmark_data = sys.argv[4]
    output = sys.argv[5]
    
    pt = PeakTech2015(port)
    board = Board(host, username)
    config = configparser.RawConfigParser(dict_type=lambda: defaultdict(list))
    config.read(benchmark_data)
    bench = list()
    for i in range(REPEAT):
        bench += config.sections()
    random.shuffle(bench)

    data = dict()
    for index, sec in enumerate(bench):
        pt.set_buffer()
        t = board.benchmark(sec)
        values = pt.get_values()
        data.setdefault(sec, list())
        data[sec].append(dict(time=t, values=values, run=index, config=config[sec]))
        print('command: %s/%s ==> %s' % (sec, t, dict(values).values()))
        time.sleep(BREAK_TIME)

    pt.close()
    board.close()
    oc=configparser.ConfigParser(dict_type=OrderedDict)
    oc.read(benchmark_data)
    write(data, oc.sections(), output)


if __name__ == '__main__':
    main()

