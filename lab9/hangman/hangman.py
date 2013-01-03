#!/usr/bin/python
import random
import sys

#while():
  # pick a new word from the library
lines = open(sys.argv[1]).read().splitlines()
randLine = random.choice(lines)
print(randLine)

arrayWord = []
for i in range(0, len(randLine)):
  print(_)
  arrayWord.append(i)
  
  