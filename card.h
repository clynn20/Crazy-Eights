#ifndef CARD_H
#define CARD_H

using namespace std;
class Card{
	private:
		int rank;
		int suit;
	public:
		Card();
		Card(int,int);
		void set_suit(int);
		void set_rank(int);
		void reset_card();
		int get_rank();
		int get_suit();
		string suit_str();
		string rank_str();
		bool is_valid();
		~Card();
};
#endif
