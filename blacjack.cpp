#include <iostream>
#include <stdlib.h> 
#include <time.h>  
using namespace std;

int card1,totaldealercard;
int counter = 0;
string hitorstand;
int cardlist[10];

bool playerturn = true;
void dealcard(){
    cardlist[counter]  =  rand() % 11 + 1;
    counter++;
    
}

void totalcardfunc(){
     card1 = 0;
    for(int i = 0; i < counter; i++){
        card1  +=cardlist[i];
    }
    cout << card1 << endl;
}


 
int main() {
    cout << "Welcome to BlackJack, press ENTER to start the game.";
    cin.get();
    srand (time(NULL)); //random seed initialization
    dealcard();
    dealcard();

    cout << "Your fist two cards total out to be ";
    totalcardfunc();
    while(playerturn == true){
        cout << "Would you like to hit or stand? (Type 'HIT' to hit, Type 'STAND' to stand)" << endl;
        cin >> hitorstand;
        if(hitorstand == "HIT"){
            dealcard();
            totalcardfunc();
            if(card1 > 21){
                cout << "You have busted out, you went over 21, you lose" << endl;
                exit(0);
            }
        }
        if(hitorstand == "STAND"){
            playerturn = false;
        }
    }
    
    totaldealercard =  rand() % 17 + 14;
    
    cout << "Dealers hand  is " << totaldealercard << endl;
    
    if(totaldealercard > 21){
        cout << "Dealer has struck out, you win!" << endl;
    }
    else if(totaldealercard > card1){
        cout << "dealer has a higher hand, dealer wins" << endl;
        
    }
    else if(totaldealercard == card1){
        cout <<"same hand, tie game" << endl;
    }
    
    else{
        cout << "you have a higher hand, you win!" << endl;
    }
    
    
   
        
    

}