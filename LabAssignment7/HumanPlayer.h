//
//  HumanPlayer.h
//  LabAssignment7
//
//  Created by Immanuel Amirtharaj on 2/15/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#ifndef __LabAssignment7__HumanPlayer__
#define __LabAssignment7__HumanPlayer__

#include "Player.h"
#include <stdio.h>
#include <iostream>
using namespace std;

class HumanPlayer : public Player
{
    public:
        int getGuess();
        // Returns the players next guess, an integer between
        // 0 and 99 (inclusive)
        void lastWasTooHigh(bool tooHigh);
        // Called to inform the player that their last guess
        // was too high (if the tooHigh argument is true) or
        // too low (if the tooHigh argument is false)
        void opponentsGuess(int guess, bool tooHigh);
        // Called to tell the player what the opponent's last
        // guess was, and whether it was too high or too low.
        void reset();
        // Called to reset the player at the end of the game.
        // Any stored state about the last guess should be cleared.
    
        HumanPlayer();
    
    
    
    int currentGuess;
   
    
};

#endif /* defined(__LabAssignment7__HumanPlayer__) */
