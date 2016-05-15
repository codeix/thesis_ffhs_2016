#!/usr/bin/env python3

import time
import serial
import threading


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


def main():
    pt = PeakTech2015()
    pt.set_buffer()
    import pdb;pdb.set_trace()
    pt.get_values()


if __name__ == '__main__':
    main()
