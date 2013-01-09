#!/usr/bin/python
import sys
import csv
import random
lines = open( sys.argv[1], "r" ).readlines()
numberOfGames = 0
letterGuess = ""
while ( letterGuess != "quit" ):
  print ""
  print "*** New Game ***"
  numberOfGames = numberOfGames + 1
  newWord = random.choice(lines)
  user_guess = ['_'] * len(newWord)
  number_of_guess = 5
  counter = len(newWord)
  while ( number_of_guess > 0 ):
    
    print ""
    letterGuess = raw_input("Enter Letter: ")
  
    while ( len(letterGuess) != 1 and letterGuess != "quit"):
      print "Uh oh: You can only guess a single letter at a time"
      letterGuess = raw_input("Enter Letter: ")
    
    
    if ( letterGuess == "quit" ):
      break
    print "Your Guess is: ", letterGuess
    success = 0
    for i in range( 0, len(newWord) ):
      if newWord[i] == letterGuess:
	user_guess[i] = letterGuess
	success = 1
	counter = counter - 1
    
    # Check the letter we guess
    if success == 0:
      # If we guess a rong letter
      number_of_guess = number_of_guess - 1
      print "Nope " + letterGuess + "does not appear in the word!"
    else:
      # If we guess letter that does appear
      print "Great! The letter " + letterGuess + " appears in the word!"

      
    print "Steps from gallows: " + str(number_of_guess) + " , Word so far: ",
    for i in range( 0, len(newWord) ):
      print user_guess[i],
    
    # If we finish guessing the word, move on to the next one
    if (counter == 0):
      print ""
      print "****** You got it *******"
      break
      
    # If we run out of guess
    if (number_of_guess == 0):
      print ""
      print "** Uh oh: you've run out of steps. You're on the platform.. and <SNAP!>"
      print "** The word you were trying to guess was: " + newWord
      break    
