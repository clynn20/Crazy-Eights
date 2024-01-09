#ifndef GAME_H
#define GAME_H
#include"card.h"

using namespace std;
class Game{
	private:
		Deck cards;
		Player player[2];
		Card topcard;
		int playerturn;
		
	public:
		Game();
		~Game();
		Deck& get_cards();
		Player* get_player();
		Card& get_topcard();
		int get_playerturn();
		void set_card(Deck&);
		void set_player(const Player (&p)[2]);
		void set_topcard(Card&);
		bool game_result();
		void print_game();
		void show_topcard();
		void deal_card();
		void change_turn();
		void start_turn();
		int get_cardnum();
		int get_random_cardnum();
		bool card_valid(int);
		void place_card(int);
};
#endif

