#include<iostream>
#include"hand.h"
#include"card.h"

using namespace std;
// constructor
Hand::Hand(){
	n_cards=0;
	cards = NULL;
}

//constructor 
Hand::Hand(Card*& oldcard, int oldncards){
	cards = new Card[oldncards];
	for(int i=0;i<oldncards;i++){
		cards[i].set_rank(oldcard[i].get_rank());
		cards[i].set_suit(oldcard[i].get_suit());
	}
	n_cards = oldncards;
}
//destructor
Hand::~Hand(){
//	cout << "Hand destructor" << endl;
	Card **ptr = &cards;
	delete []*ptr;
	*ptr = NULL;
}

//addcard 
void Hand::add_card(Card &newcard){
	Card** ptr = &cards;
	Card *newcards = new Card[n_cards+1];
	for(int i=0;i<n_cards;i++){
		//copy value in old array to new array
		newcards[i].set_rank((*ptr)[i].get_rank());
		newcards[i].set_suit((*ptr)[i].get_suit());
	}
	//add new card to new array
	newcards[n_cards].set_rank(newcard.get_rank());
	newcards[n_cards].set_suit(newcard.get_suit());
	delete[]*ptr;//delete old array
	*ptr = NULL;
	*ptr = newcards;//point to new array
	n_cards++;
}
// print card in hand
void Hand::print_hand(){
	cout << "-----Number of cards in your hand:" << n_cards << "-----" << endl;
	for(int i=0;i<n_cards;i++){
		int y = i;
		cout << y+1 <<"." <<  cards[i].suit_str() << " " << cards[i].rank_str() << endl;
	}
	cout << "------------------------------------------" << endl;
}	
// access to card
Card*& Hand::get_cards(){
	return cards;
}
// get the number of card in hand
int Hand::get_n_cards(){
	return n_cards;
}
//remove one card
void Hand::remove_card(int num, int pattern){
	int cardcopy=0;
	int index=0;
	Card **ptr = &cards;
	Card *newcards = new Card[n_cards-1];//new array
	bool cardreset = false;
	for(int i=0;i<n_cards;i++){//card want to remove
		if(cards[i].get_rank()==num && cards[i].get_suit()==pattern){
			cards[i].reset_card();
			cardreset = true;
			break;
		}
	}
	while(index<n_cards){
		if(cards[index].is_valid()){
			//copy value in old array to new array
			newcards[cardcopy].set_rank((*ptr)[index].get_rank());
			newcards[cardcopy].set_suit((*ptr)[index].get_suit());
			cardcopy++;
		}
		index++;				
	}
	delete[] *ptr;
	*ptr = NULL;
	*ptr = newcards;
	n_cards--;
}	
//get rank in cards
int Hand::get_rank(int index){
	return cards[index].get_rank();
}
//get suit in cards
int Hand::get_suit(int index){
	return cards[index].get_suit();
}




