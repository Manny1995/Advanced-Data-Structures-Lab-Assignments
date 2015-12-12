//
//  HumanPlayer.cpp
//  LabAssignment7
//
//  Created by Immanuel Amirtharaj on 2/15/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include "HumanPlayer.h"

// Takes in the user's guess via standard input
int HumanPlayer::getGuess()
{
    
    cout << "Enter your guess: ";
    
    cin >> currentGuess;
    
    return currentGuess;
}

// Takes in a boolean which determines if the user's guess was too high and then informs it to the user.
void HumanPlayer::lastWasTooHigh(bool tooHigh)
{
    
    if (tooHigh == true)
    {
        cout << "You're guess was too high!" << endl;
    }
    
    else
    {
        cout << "You're guess was too low!" << endl;
    }
}
// Takes in the opponent's guess and a boolean determining if it is too high  and then informs the user if it was too high or not.
void HumanPlayer::opponentsGuess(int guess, bool tooHigh)
{
    if (tooHigh == true)
    {
        cout << "You're opponent's last guess was " << guess << "and it was too high!" << endl;
    }
    
    else
    {
        cout << "You're opponent's last guess was " << guess << "and it was too low!" << endl;
    }
}

// Resets the HumanPlayer class to its default settings
void HumanPlayer::reset()
{
    currentGuess = -1;
}

HumanPlayer::HumanPlayer()
{
    currentGuess = -1;
   
}
