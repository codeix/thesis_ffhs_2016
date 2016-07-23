#!/usr/bin/env python3

import os
import re
import sys
import csv
import shutil
import statistics
import configparser
from collections import defaultdict
from collections import OrderedDict
from tempfile import NamedTemporaryFile


REGEX_TIME = re.compile(r'\\def\\exectime\{\{"([0-9]*)".*"([0-9]*)".*"([0-9]*)"')

def save_latex(val):
    return str(val).replace('_', '\_')

def round(val, r=3):
    """ override default round function
    """
    return ('{:,.%sf}' % r).format(val).replace(',', '`')


def calculate(index, title, config, datafolder):

    filename = os.path.join(datafolder, 'data%i.csv' % index)
    with open(filename, 'r') as csvFile:
        reader = csv.reader(csvFile, delimiter=',')


        re = dict()
        for rowindex, row in enumerate(reader):
            if rowindex:
                for t in range(3):
                    if row[t*2]:
                        li = re.setdefault(t, list())
                        if float(row[t*2]) > 5000:
                            li.append(float(row[t*2+1]))

        with open('%s.tex' % filename[:-4], '+a') as texfile:
            texfile.write('\\def\\variance{{%s}}%%\n' % ', '.join([ '"%s"' % round(statistics.pvariance(re[i]), 3) for i in range(3)]))
            texfile.write('\\def\\median{{%s}}%%\n' % ', '.join([ '"%s"' % round(statistics.median(re[i]), 3) for i in range(3)]))
            texfile.write('\\def\\average{{%s}}%%\n' % ', '.join([ '"%s"' % round(statistics.mean(re[i]), 3) for i in range(3)]))
            texfile.write('\\def\\benchmark{%s}%%\n' % save_latex(title))
            texfile.write('\\def\\description{%s}%%\n' % save_latex(config['desc']))

        exectimes = None
        with open('%s.tex' % filename[:-4], 'r') as texfile:
            for line in texfile:
                linematch = REGEX_TIME.match(line)
                if linematch:
                    exectimes = linematch.groups()
                    exectimes = [float(i) for i in exectimes]

        medt = statistics.median(exectimes)
        medbm = statistics.median(sum(re.values(),[]))
        data = dict(pos=str(index + 1),
                    name=title,
                    bm1=round(statistics.median(re[0]), 1),
                    bm2=round(statistics.median(re[1]), 1),
                    bm3=round(statistics.median(re[2]), 1),
                    t1=round(exectimes[0], 0),
                    t2=round(exectimes[1], 0),
                    t3=round(exectimes[2], 0),
                    medbm=medbm,
                    medt=medt,
                    power=None,
                    energy=None
                    )
        return data



def table(filename, data):
    with open(filename, '+w') as csvfile:
        fieldnames = (('pos',''),('name','BM Name'),('bm1','BM1 (mA)'),('bm2','BM2 (mA)'),
                      ('bm3','BM3 (mA)'),('t1','T1 (ms)'),('t2','T2 (ms)'),('t3','T3 (ms)'),
                      ('medbm','Med BM (mA)'),('medt','Med T (s)'),('power','Power (mW)'),
                      ('energy','Energy* (mW/h)'))
        writer = csv.DictWriter(csvfile, fieldnames=[i[1] for i in fieldnames])
        writer.writeheader()
        for row in data:
            convrow = dict()
            for k, v in row.items():
                if isinstance(v, (int, float)):
                    v = save_latex(v)
                convrow[dict(fieldnames)[k]] = save_latex(v)
            writer.writerow(convrow)

def main():

    if len(sys.argv) != 5:
        print('Usage: builddata.py <benchmark_data.ini> <datafolder> <tablefile> <voltage>\n')
        sys.exit(1)

    voltage = float(sys.argv[4])
    tablefile = sys.argv[3]
    datafolder = sys.argv[2]
    benchmark_data = sys.argv[1]
 
    config = configparser.RawConfigParser(dict_type=lambda: defaultdict(list))
    config.read(benchmark_data)
    oc=configparser.ConfigParser(dict_type=OrderedDict)
    oc.read(benchmark_data)
    
    table_data = list()
    for index, sec in enumerate(oc.sections()):
        data = calculate(index, sec, config[sec], datafolder)
        data['power'] = round(data['medbm'] * voltage, 3)
        data['energy'] = round(((data['medbm']/1000*voltage)/1000)/(3600/(data['medt']/1000)/1000000), 3)
        data['medt'] = round(data['medt'], 0)
        table_data.append(data)
    table(tablefile, table_data)

if __name__ == '__main__':
    main()

