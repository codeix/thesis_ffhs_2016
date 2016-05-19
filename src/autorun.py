#!/usr/bin/env python3

import os
import time
import serial
import paramiko
import threading
import configparser
from collections import defaultdict



BENCHPATH = 'cat /proc/benchmark/%s'
READ_TIME_INTERVAL = 0


class PeakTech2015(object):

    ser = None
    value_buffer = None
    thread = None
    halt = False

    def __init__(self):

        self.ser = serial.Serial(
            port='/dev/ttyUSB1',
            baudrate=2400,
            parity=serial.PARITY_ODD,
            stopbits=serial.STOPBITS_TWO,
            bytesize=serial.SEVENBITS
        )
        self.thread = threading.Thread(target=self.reader)
        self.thread.start()

    def set_buffer(self):
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
                self.value_buffer.append(value)
                time.sleep(READ_TIME_INTERVAL)


class Board(object):

    ssh = None

    def __init__(self):
        self.ssh = paramiko.SSHClient()
        self.ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        self.ssh.connect('192.168.1.100', username='pi')

    def benchmark(self, bench):
        cmd = BENCHPATH % bench
        ssh_stdin, ssh_stdout, ssh_stderr = self.ssh.exec_command(cmd)
        return ssh_stdout.readline().strip()

    def close(self):
        self.ssh.close()


def main():
    pt = PeakTech2015()
    board = Board()
    config = configparser.RawConfigParser(dict_type=lambda: defaultdict(list))
    config.read('raspberry/benchmark_data.ini')
    for sec in config.sections():
        pt.set_buffer()
        time = board.benchmark(sec)
        values = pt.get_values()
        print('command: %s/%s ==> %s' % (sec, time, values))

    pt.close()
    board.close()


if __name__ == '__main__':
    main()
