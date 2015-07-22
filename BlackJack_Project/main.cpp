/* 
 * File:   main.cpp
 * Author: Anthony Vantino
 * Created on July 19, 2015, 11:10 AM
 * Purpose: Eventually play a full version of blackjack
 */
 
//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
 
using namespace std;
 
//Global Constants
 
//Function Prototypes
void blckJck(void);
void winner(int, int);
int deal(int);
void hit(int&);
int random(int, int);
void houseHt(int&);
 
//Execution begins here
int main(int argv,char *argc[]){
    
    srand(time(NULL));
    
    //Declare Variables
    int i = 0;  //Counter
 
    //Play Blackjack
   char keepPly = 'n'; //loop control variable
       do{
            blckJck();
            cout << "Do you want to play another hand (y/n)?"<<endl;
            cin >> keepPly;
            cin.ignore();
    }while(keepPly == 'Y' || keepPly == 'y');
    return 0;
}
 
/****************************************************
 *                   BlackJack                      *
 ****************************************************
 * Purpose: To play blackjack
 * Input:
 *      hit -> draw another card
 *      stand -> do not take another card
 * Output:
 *      Hit -> hit player hand
 *      houseHt -> Hit house hand if below 16
 *      Winner -> Winner of the round, who has the bigger hand.
 */
void blckJck (void){
    //Deal Cards
    cout<<"\n\n\n\n\nStart of Round: "<<endl<<endl;
    cout<<"You were dealt."<<endl;
    int player = deal(1) + deal(1);
    cout<<" = "<<player<<endl<<endl;
    cout<<"The House was dealt."<<endl;
    int house = deal(1) + deal(1);
    cout<<" = "<<house<<endl<<endl;
 
    //Ask Player if he would like to hit
    hit(player);
    cout<<endl;
 
    //If House needs to hit or not
    houseHt(house);
    cout<<endl;
 
    //show who won....
    winner(player, house);
}
 
/****************************************************
 *                   Winner                         *
 ****************************************************
 * Purpose: Display winner
 * Input:
 * 
 * Output:
 *      Winner -> Winner of the round, who has the bigger hand.
 */
void winner(int plyScre, int hosScre){
//Compare the scores to see who won
    if((plyScre > hosScre) && (plyScre <= 21)){
      cout<<"You have the bigger hand. You Win!"<<endl<<endl;
    } else if(hosScre == plyScre){
        cout<<"You and the House Pushed. Try Again."<<endl<<endl;
    }else if(hosScre > plyScre && hosScre <= 21){
        cout<<"House has the bigger hand. Try Again."<<endl<<endl;
    }
}
 
/****************************************************
 *                   BlackJack                      *
 ****************************************************
 * Purpose: To play blackjack
 * Input:
 *      hit -> draw another card
 *      stand -> do not take another card
 * Output:
 *      Winner -> Winner of the round, who has the bigger hand.
 */
int deal(int numCrds){
//This function deals the cards
int totVal = 0;
int value = 0;
for (int i = 0; i <= numCrds; i++){  
    int cards = i; 
    while(cards--){  
        value = random(0,10); 
        cout<<value<<" "; 
	totVal += value;
	}	
}
return totVal;
}
 
/****************************************************
 *                   houseHt                        *
 ****************************************************
 * Purpose: To hit the house hand if needed
 * Input:
 * 
 * Output:
 *      house -> House Hand plus hosScre
 */
void houseHt(int &hosScre){
    int house = hosScre;
    if (hosScre < 16){
        house = hosScre + deal(1);
        cout<<"The House takes a card "<<endl<<endl;
    };       
}

/****************************************************
 *                   Hit                            *
 ****************************************************
 * Purpose: Add onto hand previously dealt
 * Input:
 *      wantCrd -> yes or no if player needs a card
 * Output:
 *      plyScre -> Add player hand with plyScre for hand total
 */
void hit(int &plyScre){
int cardCnt = 0;
char wantCrd = ('y','n');
int player = 0;
player = plyScre;
cout<<"Would you like another card? (y/n)"<<endl; 
    cin>>wantCrd;
    cin.ignore();
    while (wantCrd == 'Y' || wantCrd == 'y' && plyScre < 21){
	if ((player > 0 ) && (player <= 21))
        player += random(0,10);
        cout<<"Your total is = " <<player<<endl<<endl;
            cout<<"Do you want another card?"<<endl;
            cin>>wantCrd;
            cin.ignore();
            //cout<<"You take a card. \n\nYour new total = "<<player + deal(1)<<endl<<endl;
                if (wantCrd == 'Y' || wantCrd == 'y')
                    cout<<"You take a card. \n\nYour new total = "
                            <<player + deal(1)<<endl<<endl; // adds plyScre to hosCrd()
		if (wantCrd == 'n' || wantCrd == 'N')
                    cout<<"You decide to stand. "<<endl<<endl;
    }
}
 
/****************************************************
 *                   random                         *
 ****************************************************
 * Purpose: To generate random number depending on limit
 * Input:
 *      
 * Output:
 *      return -> random number generator with up limit to lower limit
 */
int random(int lowLim, int upLim){
//returns a random number within the given boundary
return 1 + rand() % (upLim - lowLim + 1);
}