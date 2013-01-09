#!/usr/bin/python
import csv
import sys
grades = {}
student_numbers = {}
input = file(sys.argv[1])
num_of_students = 0

input.next(),
for line in input:
  line = line.strip()
  array = line.split(',')
  try:
    grades[array[2]] += 1
  except KeyError:
    grades[array[2]] = 1;
  try:
    student_numbers[array[2]] += str(array[0])+", "
  except KeyError:
    student_numbers[array[2]] = str(array[0])+", "
    
for k in grades. iterkeys():
  print "grade:" + str(k)+", num of students:"+str(grades[k]) + ", students codes:" + student_numbers[k]