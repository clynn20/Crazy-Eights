#include<iostream>
#include<cstdlib>
#include"card.h"
#include"deck.h"
#include"player.h"
#include"game.h"

using namespace std;
//default constructor
Game::Game(){
	cards = Deck();
	cards.shuffle();
	show_topcard();
	player[0] = Player(Hand(),"player");
	player[1] = Player(Hand(),"computer");
	playerturn=0;
}
//destructor
Game::~Game(){
	cout <<"See you next time!" << endl;
}
//access to player
Player* Game::get_player(){
	return 	player;
}
// access to deck
Deck& Game::get_cards(){
	return cards;
}
// access to topcard
Card& Game::get_topcard(){
	return topcard;
}
// show the player turn
int Game::get_playerturn(){
	return playerturn;
}
// set card
void Game::set_card(Deck& newcards){
	cards = newcards;
}
//set player
void Game::set_player(const Player (&p)[2]){
	player[0]= p[0];
	player[1]= p[1];
}
// set top card 
void Game::set_topcard(Card& newtopcard){
	topcard.set_rank(newtopcard.get_rank());
	topcard.set_rank(newtopcard.get_suit());
}
// print out game result
bool Game::game_result(){
	int deckleft = cards.get_n_cards();
	int p0cards = player[0].get_hand().get_n_cards();
	int p1cards = player[1].get_hand().get_n_cards();
	if(deckleft==0){
		if(p0cards>p1cards){
			cout << "computer win" << endl;
		}
		else if(p0cards<p1cards){
			cout << "player win" << endl;
		}
		return true;
	}
	else if(deckleft!=0){
		if(p0cards==0){
			cout <<"player win" << endl;
			return true;
		}
		else if(p1cards==0){
			cout <<"computer win" << endl;
			return true;
		}
	}
	return false;
}
// print game status
void Game::print_game(){
	if(topcard.get_rank()!=-1){
		cout << "*************************************" << endl;
		cout <<"Top card on pile now: " << topcard.suit_str() << " " << topcard.rank_str()<<endl;
		cout << "*************************************" << endl;
	}
	if(playerturn==0){
		Hand &p0hand = player[0].get_hand();
		p0hand.print_hand();
	}
}
// print the topcard
void Game::show_topcard(){
	Card* pile = cards.get_cards();
	for(int i=0;i<52;i++){
		if(pile[i].is_valid()){
		topcard = pile[i];
		pile[i].reset_card();
		break;
		}
	}
}
// deal 7 card to each player hand
void Game::deal_card(){
	Hand &p0hand = player[0].get_hand();
	Hand &p1hand = player[1].get_hand();
	for(int i=0;i<7;i++){
		cards.deal_card(p0hand);
		cards.deal_card(p1hand);
	}
}
// check player's card and change player turn after place card
void Game::start_turn(){
	int card_num=0;
	if(!player[playerturn].check_h_card(topcard.get_rank(),topcard.get_suit())){
		if(playerturn==0){
			do{
			cout <<"No match card in hand, draw one card" << endl;
			Hand &hand = player[0].get_hand();
			cards.deal_card(hand);
			hand.print_hand();
			}
			while(!player[0].check_h_card(topcard.get_rank(),topcard.get_suit()));
		}
		else if(playerturn==1){
			do{
			Hand &hand = player[playerturn].get_hand();
			cards.deal_card(hand);
			}
			while(!player[1].check_h_card(topcard.get_rank(),topcard.get_suit()));
		}
	}
	else if(player[playerturn].check_h_card(topcard.get_rank(),topcard.get_suit())){
		if(playerturn==0){
			card_num = get_cardnum();
			place_card(card_num);
			change_turn();
		}
		else if(playerturn==1){
			card_num=get_random_cardnum();
			place_card(card_num); 
			change_turn();
		}
	}
}
// change playerturn
void Game::change_turn(){
	if(playerturn==0){
		playerturn = 1;
	}
	else {
		playerturn = 0;
	}
}
// check if hand card is match to suit or rank in topcard
bool Game::card_valid(int cardnum){
	Hand& hand= player[playerturn].get_hand();
	if(cardnum<0||cardnum>(hand.get_n_cards()-1)){
		return false;
	}
	int pattern = topcard.get_suit();
	int num = topcard.get_rank();
	int card_num = hand.get_rank(cardnum);
	int card_pattern = hand.get_suit(cardnum);
	if(pattern == card_pattern||num == card_num||card_num==8){
		return true;
	}
	else
		return false;
}
// get the number of card player want to place
int Game::get_cardnum(){
	int num;
	int cardnum=0;
	while(1){
		cout << "Enter the number for the card you want to place: ";
		cin >> num;
		cardnum = num-1;
		if(!card_valid(cardnum)){
			cout << "Invalid card number." << endl;
		}
		else 
			break;
	}
	return cardnum;
}
// get computer number of card to place
int Game::get_random_cardnum(){
	int cardnum=0;
	while(1){
		if(card_valid(cardnum)){
			return cardnum;
		}
		cardnum++;
	}
}
// place out the card  as new topcard and remove hand card
void Game::place_card(int cardnum){
	Hand& hand = player[playerturn].get_hand();
	Card *&cards = hand.get_cards();
	int num = cards[cardnum].get_rank();
	int pattern = cards[cardnum].get_suit();
	if(playerturn==0){
		cout << "**Player place: " << cards[cardnum].suit_str() <<" " << cards[cardnum].rank_str()<<endl;
	}
	else if(playerturn==1){
		cout << "**Computer place: " << cards[cardnum].suit_str() << " " << cards[cardnum].rank_str()<<endl;
	}
	topcard.set_rank(num);
	topcard.set_suit(pattern);
	hand.remove_card(num,pattern);
	if(num==8){
		int newsuit = player[playerturn].ask_suit();
		topcard.set_rank(-1);
		topcard.set_suit(newsuit);
	}
}
	


	
