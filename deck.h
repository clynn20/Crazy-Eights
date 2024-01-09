#ifndef DECK_H
#define DECK_H
#include"card.h"
#include"hand.h"
using namespace std;
class Deck{
	private:
		Card cards[52];
		int n_cards;//nums of cards in deck
	public:
		Deck();
		void shuffle();
		void print_deck();
		int get_n_cards();
		void deal_card(Hand&);
		~Deck();
		Card* get_cards();
};
#endif
