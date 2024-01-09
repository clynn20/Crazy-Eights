#ifndef HAND_H
#define HAND_H
#include<iostream>
#include<string>
#include"card.h"
using namespace std;
class Hand{
	private:
		Card* cards;
		int n_cards;//nums of cards in hand
	public:
		Hand();
		Hand(Card*&,int);
//		Hand(const Hand&);
//		Hand& operator=(const Hand&);
		~Hand();
		Card*& get_cards();
		int get_n_cards();
		void add_card(Card&);
		void remove_card(int,int);
		void print_hand();
		int get_rank(int);
		int get_suit(int);
		

};
#endif

