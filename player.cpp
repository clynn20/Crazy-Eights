#include<iostream>
#include<cstdlib>
#include"card.h"
#include"hand.h"
#include"player.h"

using namespace std;
//default constructor
Player::Player(){
	hand = Hand();
	name = "non";
}
//constructor with parameters
Player::Player(const Hand &init_hand, string str){
	hand = init_hand;
	name = str;
}
//get player name
string Player::get_name(){
	return name;
}
//destructor
Player::~Player(){
//	cout<<"player destructor"<< endl;
}
// access to hand
Hand& Player::get_hand(){	
	return hand;
}
//set hand
void Player::set_hand(const Hand& new_hand){
	hand = new_hand;
}
//set name
void Player::set_name(string str){
	name = str;
}
//add card to hand
void Player::add_card(Card &newcard){
	hand.add_card(newcard);
}
//remove card from hand
void Player::remove_card(int num,int pattern){
	hand.remove_card(num,pattern);
}
//ask suit after player play eight
int Player::ask_suit(){
	srand(time(NULL));
	string suitstr;
	cout << name << " play NO.8 " <<  name << " should choose a suit to play" << endl; 
	if(name=="computer"){
		int suitnum = rand()%4;
		switch(suitnum){
			case 0:
				cout<<"computer choose Club" << endl;
				break;
			case 1:
				cout <<"computer choose Diamond" << endl;
				break;
			case 2: 
				cout <<"computer choose Heart" << endl;
				break;
			case 3:
				cout <<"computer choose Spade" << endl;
				break;
			}
		return suitnum;
	}
	else if(name=="player"){
		while(suitstr !="1" && suitstr !="2" && suitstr!="3" && suitstr!="4"){
			cout << "choose a suit: 1.Club 2.Diamond 3.Heart 4.Spade: " ;
			getline(cin,suitstr);
		}
	}
	int suit_num = atoi(suitstr.c_str())-1;
	return suit_num;

}
// check if hand card have rank or suit equal to top card or if hand card have rank eight 
bool Player::check_h_card(int num, int pattern){
	Card*& cards = hand.get_cards();
	for(int i=0;i<hand.get_n_cards();i++){
		if(cards[i].get_rank()==num||cards[i].get_suit()==pattern||(cards[i].get_rank()==8 && cards[i].get_suit()!=pattern)){
			return true;
		}
	}
	return false;
}
	
		

