#!/usr/bin/python
import csv
import sys

input = file(sys.argv[1])
numOfSt = 0
avrg = 0

print input.next(),

for line in input:
  array = line.split(',')
  avrg = avrg + int(array[2])
  numOfSt += 1
  print line,
avrg = float(avrg)/numOfSt
print avrg
  
