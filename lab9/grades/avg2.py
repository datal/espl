#!/usr/bin/python
import csv
import sys
grades = {}

input = file(sys.argv[1])
num_of_students = 0
input.next(),

for line in input:
  array = line.split(',')
  try:
    grades[array[2]] += 1
  except KeyError:
    grades[array[2]] = 1;
    
for grade,num in grades.iteritems():
  print "grade:" + str(grade.strip())+", num of students:"+str(num)