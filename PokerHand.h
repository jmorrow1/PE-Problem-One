/* 
 * File:   PokerHand.h
 * Author: James Morrow <jmorrow1@unca.edu>
 *
 * Created on February 18, 2015, 11:58 PM
 */
#include <string>

#ifndef POKERHAND_H
#define	POKERHAND_H

class PokerHand {
public:
    PokerHand(std::string);
    int getScore(void); 
    int getCardRank(int); 
    int getHandRank(void); 
private:
    int rank(char); 
    void sort(int[5]);
    std::string hand; 
    int ranks[5];   
    int score; 
    int handRank; 
};

#endif	/* POKERHAND_H */

