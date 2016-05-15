#!/usr/bin/env python3

import os
import time
import serial
import threading
import configparser
from collections import defaultdict



BENCHPATH = 'cat /proc/benchmark/%s\r\n'
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

    ser = None

    def __init__(self):
        self.ser = serial.Serial(
            port='/dev/ttyUSB0',
            baudrate=115200,
            timeout=1,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            bytesize=serial.EIGHTBITS
        )
        self.ser.write(b'\n')
        self.ser.reset_input_buffer()

    def benchmark(self, bench):
        self.ser.write(b'\n')
        self.ser.reset_input_buffer()
        self.ser.readline()
        self.ser.write((BENCHPATH % bench).encode())
        wait = 10
        for i in range(10):
            out = self.ser.readline().decode().strip()
            if out:
                return out
        raise ReadException('No output from SoC')


class ReadException(Exception):
    pass


def main():
    import pdb;pdb.set_trace()
    pt = PeakTech2015()
    board = Board()
    config = configparser.RawConfigParser(dict_type=lambda: defaultdict(list))
    config.read('raspberry/benchmark_data.ini')
    for sec in config.sections():
        for i in range(5):
            pt.set_buffer()
            try:
                time = board.benchmark(sec)
            except ReadException:
                print('Error command %s' % sec)
                continue
            values = pt.get_values()
            print('command: %s/%s ==> %s' % (sec, time, values))
            break


if __name__ == '__main__':
    main()
