#include<iostream>
#include"card.h"
#include"deck.h"
#include"hand.h"
#include"player.h"
#include"game.h"

using namespace std;
int main(){
	
	int playagain = 1;
	while(playagain==1){
		Game start = Game();
		start.deal_card();
		start.print_game();
		do{
			start.start_turn();
			start.print_game();
		}
		while(!start.game_result());
		do{
			cout << "Want to play again?(enter 0 to exit, enter 1 to play again: "; 
			cin >> playagain;
		}
		while(playagain!=0 && playagain!=1);
	}
	return 0;
}

