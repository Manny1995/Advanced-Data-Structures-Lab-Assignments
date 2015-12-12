//
//  ComputerPlayer.cpp
//  LabAssignment7
//
//  Created by Immanuel Amirtharaj on 2/15/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include "ComputerPlayer.h"
#include "time.h"


// Sets the last guess to the current guess, and then makes a guess using the opponent's last guess and rand
int ComputerPlayer::getGuess()
{
    if (lastGuess == -1)
    {
        srand(time(NULL));
        currentGuess = rand() % 99;
   
    }
    lastGuess = currentGuess;
    
    if (opponentGuessTooHigh)
    {
        currentGuess = (opponentGuess/2);
    }
    else
    {
        currentGuess = (((99-opponentGuess)/2) + opponentGuess);
    }

    return currentGuess;
}

// Takes in a boolean which determines if the user's guess was too high and then saves it for future use.
void ComputerPlayer::lastWasTooHigh(bool tooHigh)
{

    lastGuessTooHigh = tooHigh;
}

// Takes in the opponent's guess and a boolean determining if it is too high and then stores it to predits its next guess
void ComputerPlayer::opponentsGuess(int guess, bool tooHigh)
{
    
    opponentGuess = guess;
    opponentGuessTooHigh = tooHigh;
}

// Resets the ComputerPlayer class to its default settings
void ComputerPlayer::reset()
{
    currentGuess = -1;
    lastGuess = -1;
}
