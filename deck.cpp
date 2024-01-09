#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"card.h"
#include"deck.h"
#include"hand.h"
using namespace std;
// constructor, fill in card array with rank and suit 
Deck::Deck(){
	n_cards = 52;
	for(int i=0;i<13;i++){
		cards[i].set_suit(0);
		cards[i].set_rank(i+1);
	}
	for(int i=13;i<26;i++){
		cards[i].set_suit(1);
		cards[i].set_rank(i-12);
	}
	for(int i=26;i<39;i++){
		cards[i].set_suit(2);
		cards[i].set_rank(i-25);
	}
	for(int i=39;i<52;i++){
		cards[i].set_suit(3);
		cards[i].set_rank(i-38);
	}
}
//destructor
Deck::~Deck(){
//	cout<<"deck destructor" << endl;
}
//print card array 
void Deck::print_deck(){
	for(int i=0;i<52;i++){
		cout<<cards[i].suit_str()<<" "<< cards[i].rank_str()<< endl;
	}
}
// shuffle card array 
void Deck::shuffle(){
	int a,b;
	Card temp;
	srand(time(NULL));
	for(int i=0;i<100;i++){
		a = rand()%52;
		b = rand()%52;
		do{
			a = rand()%52;
			b = rand()%52;
		}
		while(a==b);
		temp = cards[a];
		cards[a]=cards[b];
		cards[b]=temp;
	}
}
// deal one card to hand
void Deck::deal_card(Hand &hand){
		int index =0;
		for(int i=0;i<52;i++){
			if(cards[i].is_valid()){
				index=i;
				break;
			}
		}
		hand.add_card(cards[index]);
		cards[index].reset_card();
		n_cards--;
}
// get remaining card number in deck
int Deck::get_n_cards(){
	return n_cards;
}
// access to card
Card* Deck::get_cards(){
	return cards;
}

