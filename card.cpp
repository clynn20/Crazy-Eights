#include<iostream>
#include<string>
#include"card.h"

using namespace std;
//default constructor
Card::Card(){
	suit = 4;
	rank = 0;
}
// constructor with parameter
Card::Card(int num,int pattern){
	suit = pattern;
	rank = num;
}
//destructor
Card::~Card(){
//	cout <<"card destructor"<<endl;
}
//setter
void Card::set_suit(int pattern){
	suit = pattern;
}
//getter
int Card::get_suit(){
	return suit;
}
//setter
void Card::set_rank(int num){
	rank = num;
}
//getter
int Card::get_rank(){
	return rank;
}
//turn int suit to string suit
string Card::suit_str(){
	string s_str;
	for(int i=0;i<52;i++){
		if(suit==0){
			s_str="Club";
		}
		else if(suit==1){
			s_str ="Diamond";
		}
		else if(suit==2){
			s_str = "Heart";
		}
		else if(suit==3){
			s_str = "Spade";
		}
	}
	return s_str;
}
//turn int rank to string rank
string Card::rank_str(){
	string s_rank;
	for(int i =0;i<52;i++){
		if(rank==1){
			s_rank="A";
		}
		else if(rank==2){
			s_rank="2";
		}
		else if(rank==3){
			s_rank="3";
		}
		else if(rank==4){
			s_rank="4";
		}
		else if(rank==5){
			s_rank="5";
		}
		else if(rank==6){
			s_rank="6";
		}
		else if(rank==7){
			s_rank="7";
		}
		else if(rank==8){
			s_rank="8";
		}
		else if(rank==9){
			s_rank="9";
		}
		else if(rank==10){
			s_rank="10";
		}
		else if(rank==11){
			s_rank="J";
		}
		else if(rank==12){
			s_rank="Q";
		}
		else if(rank==13){
			s_rank="K";
		}
	}
	return s_rank;
}
// set card to -1 as flag
void Card::reset_card(){
	rank=-1;
	suit=-1;
}
// check if card is used 
bool Card::is_valid(){
	return !(rank==-1||suit==-1);
}

