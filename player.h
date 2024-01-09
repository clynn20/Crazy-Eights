#ifndef PLAYER_H
#define PLAYER_H
#include"hand.h"
#include"card.h"

using namespace std;

class Player{
	private:
		Hand hand;
		string name;
	public:
		Player();
		Player(const Hand&,string);
		void set_name(string);
		void set_hand(const Hand&);
		string get_name();
		~Player();
		Hand& get_hand();
		void add_card(Card&);
		void remove_card(int,int);
		int ask_suit();
		bool check_h_card(int,int);

};
#endif

