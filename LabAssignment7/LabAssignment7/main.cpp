//
//  main.cpp
//  LabAssignment7
//
//  Created by Immanuel Amirtharaj on 2/15/15.
//  Copyright (c) 2015 Immanuel Amirtharaj. All rights reserved.
//

#include <iostream>
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <time.h>       


using namespace std;


/*
 * play() is a game engine which conducts the turn based events of this game.
 * Randomly generates a number between 0 and 99 with the srand function
 * Queries both the human player and the computer player until either one gets the correct answer
 * Displays which player won and tells the number of steps it took
 * Resets both classes for the next round
 */
void play(int player1, int player2)
{
    
    int turns = 1;
    
    int answer = rand()%100;
    
    cout << "Answer: " << answer << endl;
    
    Player *user1;
    Player *user2;
    
    
    if (player1 == 0)
        user1 = new HumanPlayer();
    else
        user1 = new ComputerPlayer();
    
    if (player2 == 0)
        user2 = new HumanPlayer();
    else
        user2 = new ComputerPlayer();
    
    
    
    int userGuess = -1;
    int computerGuess = -1;
    
    while (userGuess != answer && computerGuess != answer)
    {
        userGuess = user1->getGuess();
        
        if (userGuess == answer)
            break;
        
        
        user1->lastWasTooHigh(userGuess > answer);
        user2->opponentsGuess(userGuess, (userGuess>answer));
        
        
        computerGuess = user2->getGuess();
        
        if (computerGuess == answer)
            break;
        
        user2->lastWasTooHigh(computerGuess>answer);
        user1->opponentsGuess(computerGuess, (computerGuess>answer));
        
        turns++;
    }
    
    
    if (userGuess == answer)
        cout << "Player 1 won and it took " << turns << " turns" << endl;
    else
    {
        cout << "Player 2 won and it took " << turns << " turns" << endl;
    }
    
    user1->reset();
    user2->reset();
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int player1, player2;
    
    cout << "Enter type for player 1 (0 for human, 1 for computer): ";
    cin >> player1;
    
    cout << "Enter type for player 2 (0 for human, 1 for computer): ";
    cin >> player2;
    
    srand(time(NULL));
    
    
    play(player1, player2);

    return 0;
}
