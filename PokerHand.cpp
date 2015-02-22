/* 
 * File:   PokerHand.cpp
 * Author: James Morrow <jmorrow1@unca.edu>
 * 
 * Created on February 18, 2015, 11:58 PM
 */

/*
hand scores--->

High Card = 0
One Pair = 1
Two Pairs = 2
Three of a Kind = 3
Straight = 4
Flush = 5
Full House = 6
Four of a Kind = 7
Straight Flush = 8
Royal Flush = 9
*/

#include <iostream>
#include "PokerHand.h"

PokerHand::PokerHand(std::string hand) {
    this->hand = hand;    
    
    //check for flush
    bool flush=false;
    if (hand.at(1) == hand.at(4) && 
            hand.at(1) == hand.at(7) && 
            hand.at(1) == hand.at(10) && 
            hand.at(1) == hand.at(13)) {
        flush = true; 
        
    }
    
    //check for straight
    bool straight=false; 
    bool royal=false;
    int i; 
    for (i=0; i<5; i++) {
        ranks[i] = rank(hand.at(i*3)); 
    }
    sort(ranks); 

    for (i=0; i<4; i++) {
        if (ranks[i] != ranks[i+1]-1) {
            break; 
        }
        if (i == 3) {
            straight = true; 
            if (ranks[4] == 14) {
                royal = true; 
            }
        }
    }
    
    //check for n-of-a-kind
    bool onePair=false;
    bool twoPair=false;
    bool threeOfAKind=false;
    bool fourOfAKind=false;
    bool fullHouse=false;
    int streak=1; 
    for (i=0; i<4; i++) {       
        if (ranks[i] == ranks[i+1]) {
            streak++; 
        }
        if (ranks[i] != ranks[i+1] || i == 3) {          
            if (streak == 2) {
                if (onePair) {
                    twoPair = true;
                    if (ranks[i] > handRank) handRank = ranks[i]; 
                }
                else if (threeOfAKind) {
                    fullHouse = true; 
                    if (ranks[i] > handRank) handRank = ranks[i]; 
                }
                else {
                    onePair = true; 
                    handRank = ranks[i]; 
                }
            }
            else if (streak == 3) {
                if (onePair) {
                    fullHouse = true; 
                    if (ranks[i] > handRank) handRank = ranks[i]; 
                }
                else {
                    threeOfAKind = true; 
                    handRank = ranks[i]; 
                }
            }
            else if (streak == 4) {
                fourOfAKind = true;
                handRank = ranks[i]; 
            }
            streak = 1; 
        }
    }
    
    if (royal && flush) {
        score = 9; 
        handRank = ranks[4];         
    }
    else if (straight && flush) {
        score = 8; 
        handRank = ranks[4];        
    }
    else if (fourOfAKind) {
        score = 7; 
        
    }
    else if (fullHouse) {
        score = 6; 
        
    }
    else if (flush) {
        score = 5; 
        handRank = ranks[4];      
        
    }
    else if (straight) {
        score = 4; 
        handRank = ranks[4]; 
    }
    else if (threeOfAKind) {
        score = 3;          
    }
    else if (twoPair) {
        score = 2; 
    }
    else if (onePair) {
        score = 1; 
    }
    else {
        score = 0; 
    }
    
}

int PokerHand::rank(char c) {
    switch(c) {
        case '2' : return 2; 
        case '3' : return 3; 
        case '4' : return 4; 
        case '5' : return 5; 
        case '6' : return 6; 
        case '7' : return 7; 
        case '8' : return 8; 
        case '9' : return 9; 
        case 'T' : return 10; 
        case 'J' : return 11; 
        case 'Q' : return 12; 
        case 'K' : return 13; 
        case 'A' : return 14; 
        default : return 0; 
    }
}

//sorts an array assuming an array length of 5
void PokerHand::sort(int array[5]) {
    int i;
    for (i=0; i<5; i++) {
        int j;
        for (j=i+1; j<5; j++) {
            if (array[j] < array[i]) {
                int array_j = array[j]; 
                array[j] = array[i];  
                array[i] = array_j; 
            }
        }
    }
}

//returns the score of the hand given the key at the top of the file
int PokerHand::getScore() {
    return score; 
}

int PokerHand::getHandRank() {
    return handRank; 
}

//returns the rank of the nth lowest card 
//(i.e. if highCardScore(0) is called and the lowest card in the hand is the 7 of spades,
//it returns a 7)
int PokerHand::getCardRank(int n) {
    return ranks[n]; 
}