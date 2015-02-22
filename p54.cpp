//check for flush
//check for straight (series of consecutive cards)
//check for n-of a kind
//(except for flush+straight, these hands preclude each other). 

//having n-of a kind precludes having a flush, so ...
//1st check for n-of a kind
//if there are no n-of a kinds ...
//check for flush
//check for straight
//if there are no flushes or straights ...
//get highest value card

//when the above procedure reaches an end, assign the hand a score which is like a ranking. 



//settle ties by comparing highest cards

#include <iostream>
#include <fstream>
#include <string>
#include "PokerHand.h"
using namespace std; 

void solveProblem54() {
    ifstream file; 
    string line; 
    int playerOneWinCount=0; 
    int ties=0; 
    PokerHand* hand1;
    PokerHand* hand2;
    file.open("p054_poker.txt"); 
    if (file.is_open()) {
        while (getline(file, line)) {
            std::string str1 = line.substr(0,14);
            hand1 = new PokerHand(str1); 
            std::string str2 = line.substr(15,14); 
            hand2 = new PokerHand(str2);
            if (hand1->getScore() == hand2->getScore()) {
                //settle ties
                //std::cout << "tie : hand 1 = " << str1 << "(score " << hand1->getScore() << "), hand 2 = " << str2 << "(score " << hand2->getScore() << ")\n"; 
                ties++; 
                if (hand1->getHandRank() == hand2->getHandRank()) {
                    
                    for (int i=4; i>=0; i--) {
                        if (hand1->getCardRank(i) > hand2->getCardRank(i)) {
                            playerOneWinCount++; 
                            break; 
                        }
                        else if (hand1->getCardRank(i) < hand2->getCardRank(i)) {
                            break; 
                        }
                    }
                }
                else if (hand1->getHandRank() > hand2->getHandRank()) {
                    playerOneWinCount++; 
                }
            }
            else if (hand1->getScore() > hand2->getScore()) {
                playerOneWinCount++; 
            }
        }
    }
    else {
        cout << "didn't read file" << endl; 
    }
    cout << "player 1 got " << playerOneWinCount << " wins \n"; 
    //cout << "there were " << ties << " ties \n"; 
    file.close() ;
}
