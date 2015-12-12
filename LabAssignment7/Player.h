//
//  Player.h
//  LabAssignment7
//
//  Created by Immanuel Amirtharaj on 2/15/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#ifndef __LabAssignment7__Player__
#define __LabAssignment7__Player__

#include <stdio.h>

class Player { public:
   // Player();
   // virtual ~Player();
    virtual int getGuess() = 0;
    // Returns the players next guess, an integer between
    // 0 and 99 (inclusive)
    virtual void lastWasTooHigh(bool tooHigh) = 0;
    // Called to inform the player that their last guess
    // was too high (if the tooHigh argument is true) or
    // too low (if the tooHigh argument is false)
    virtual void opponentsGuess(int guess, bool tooHigh) = 0;
    // Called to tell the player what the opponent's last
    // guess was, and whether it was too high or too low.
    virtual void reset() = 0;
    // Called to reset the player at the end of the game.
    // Any stored state about the last guess should be cleared.
    
};

#endif /* defined(__LabAssignment7__Player__) */
