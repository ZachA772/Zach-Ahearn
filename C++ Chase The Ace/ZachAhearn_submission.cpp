//Zach Ahearn
//K00282339
#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <algorithm> // for std::shuffle

using namespace std;

//Unique feature index
//First feature - line 17
//Second feature - line 222
//Third feature - line 499


//FIRST UNIQUE FEATURE
//This Function will help the computer decide whether it keeps it's card or swaps with the deck
int computer_decide()
{
    int numArray[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    static auto rng = default_random_engine { random_device{}() }; // create a static random engine object
    shuffle(begin(numArray), end(numArray), rng); // shuffles the array
    return numArray[0]; // This will return the first element
}

//This Function will shuffle the playing deck
int shuffle_deck()
{
    int numArray[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    static auto rng = default_random_engine { random_device{}() }; // create a static random engine object
    shuffle(begin(numArray), end(numArray), rng); // shuffles the array
    return numArray[0]; // This will return the first element of the array after the shuffle
}

//This Function will shuffle the card suit
string shuffle_suit()
{
    string cardSuits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    static auto rng = default_random_engine { random_device{}() }; // create a static random engine object
    std::shuffle(begin(cardSuits), end(cardSuits), rng); // shuffle the array
    return cardSuits[0]; // return the first element
}


//This function will display the rules
void display_rules()
{
    cout<<"These are the rules of Chase The Ace" << endl;
    cout<<"1. The goal is to have the highest value card, the person with the lowest value loses." << endl;
    cout<<"2. Each Player has 3 lives, lives are lost upon round loss, game ends once all lives are depleted." << endl;
    cout<<"3. Each player is dealt 1 card and can look at their own card." << endl;
    cout<<"4. The first player to start is whoever comes after the dealer." << endl;
    cout<<"5. The player's turn has a choice to stay with their own card, or blindly swap with the next person." << endl;
    cout<<"6. This continues with every player until it is the dealer's turn, where the dealers can stick with their card, or blindly swaps with the deck." << endl;
    cout<<"7. All players card are revealed at the end of the round, the lowest card loses a life." << endl;
    cout<<"8. The Ace is the main card wanted as it has the highest value and trumps all other cards" << endl;
    cout<<"9. If 2 players have the same card value, 'red' cards like Diamonds and Hearts take priority and beat 'black' cards." << endl;
    cout<<"10. In this game, the computer will always be the shuffler and can only swap with the deck, if it so choses." << endl;
}

//This function will display the leadeboard
void leaderboard()
{
    cout<<"k00298432: 64 wins" << endl;
    cout<<"k00294532: 45 wins" << endl;
    cout<<"k00298441: 32 wins" << endl;
    cout<<"k00247432: 24 wins" << endl;
    cout<<"k00282532: 16 wins" << endl;
    cout<<"k00219332: 9 wins" << endl;
}

int main() {
    int menuInput;
    
    cout<<"WELCOME TO CHASE THE ACE" << endl;
    do{
    cout<<"----Main Menu----" << endl;
    cout<<"1. Start Game" << endl;
    cout<<"2. Rules" << endl;
    cout<<"3. Leaderboard" << endl;
    cout<<"4. Quit Game" << endl;
    
    cout<<"Choose corresponding number to select menu option:" << endl;
    cin >> menuInput;
    switch (menuInput) {
        case 1:
            cout << "Starting game..." << endl;
            break;
        case 2:
            cout << "Displaying Rules" << endl;
            display_rules();
            break;
        case 3:
            cout << "Displaying Leaderboard" << endl;
            leaderboard();
            break;
        case 4:
            cout << "Exiting game..." << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
    }
    }while(menuInput != 1);
    
    int p1Lives = 3;
    int p2Lives = 3;
    int computerLives = 3;
    
    /*
    cout << "Your card value is " << p1card << endl;
    cout << "Your card value is " << p2card << endl;
    cout << "Your card value is " << computercard << endl;
    */

   
    do{
         //This variable is to allow players to swap cards by temporary assigning card values to this variable
        int tempSwap = 0;
        string tempSuit = " ";
        
        //Variable of cards value
        int p1card = 0;
        int p2card = 0;
        int computercard = 0;
        
        //Variable of cards suit
        string p1suit;
        string p2suit;
        string computersuit;
        
        //Variable that displays the card
        string p1cardName;
        string p2cardName;
        string computercardName;
                
        //Loop to ensure card dealt are different
        do {
            p1card = shuffle_deck();
            p2card = shuffle_deck();
            computercard = shuffle_deck();
        
            p1suit = shuffle_suit();
            p2suit = shuffle_suit();
            computersuit = shuffle_suit();
            }while ((p1card == p2card && p1suit == p2suit) || 
        (p1card == computercard && p1suit == computersuit) || 
        (p2card == computercard && p2suit == computersuit));

        
        //Player 1 Turn -----------------------------------------------------------------------------
        
        //Assinging card value to name of card
        if(p1card == 2)
        {
            p1cardName = "2";
        } 
        else if(p1card == 3) 
        {
            p1cardName = "3";
        } 
        else if(p1card == 4) 
        {
            p1cardName = "4";
        } 
        else if (p1card == 5) 
        {
            p1cardName = "5";
        }
        else if (p1card == 6) 
        {
            p1cardName = "6";
        }
        else if (p1card == 7) 
        {
            p1cardName = "7";
        }
        else if (p1card == 8) 
        {
            p1cardName = "8";
        }
        else if (p1card == 9) 
        {
            p1cardName = "9";
        }
        else if (p1card == 10) 
        {
            p1cardName = "10";
        }
        else if (p1card == 11) 
        {
            p1cardName = "Jack";
        }
        else if (p1card == 12) 
        {
            p1cardName = "Queen";
        }
        else if (p1card == 13) 
        {
            p1cardName = "King";
        }
        else if (p1card == 14) 
        {
            p1cardName = "Ace";
        }
        
        cout << "---------------" << endl;
        cout << "Player 1's Turn" << endl;
        cout << "---------------" << endl;
   
        cout  << p1cardName << " of " << p1suit << " is your card"<< endl;
    
        char p1Input; 
        cout << "Enter 'k' to keep card or 's' to swap card with next player"<< endl;
        cin >> p1Input;
    
        if(p1Input == 'k')
        {
            cout << "You keep your card" << endl;
        }
        //SECOND UNIQUE FEATURE
        else if(p1Input == 's')
        {
            cout << "You swap your card" << endl;
            tempSwap = p1card; //Assigning temporary card to p1card
            p1card = p2card; //making p1card = p2card
            p2card = tempSwap; //p2card equaling temp card so the 2 cards have now swapped value
            
            //Same process for the suit swap
            tempSuit = p1suit;
            p1suit = p2suit;
            p2suit = tempSuit;
            
            //Reassigning new card value to card name
            if(p1card == 2)
            {
                p1cardName = "2";
            } 
            else if(p1card == 3) 
            {
                p1cardName = "3";
            } 
            else if(p1card == 4) 
            {
                p1cardName = "4";
            } 
            else if (p1card == 5) 
            {
                p1cardName = "5";
            }
            else if (p1card == 6) 
            {
                p1cardName = "6";
            }
            else if (p1card == 7) 
            {
                p1cardName = "7";
            }
            else if (p1card == 8) 
            {
                p1cardName = "8";
            }
            else if (p1card == 9) 
            {
                p1cardName = "9";
            }
            else if (p1card == 10) 
            {
                p1cardName = "10";
            }
            else if (p1card == 11) 
            {
                p1cardName = "Jack";
            }
            else if (p1card == 12) 
            {
                p1cardName = "Queen";
            }
            else if (p1card == 13) 
            {
                p1cardName = "King";
            }
            else if (p1card == 14) 
            {
                p1cardName = "Ace";
            }
            
            cout  << p1cardName << " of " << p1suit << " is your new card"<< endl;
        }
    
        //Player 2 Turn ----------------------------------------------------------------------------
        
        if (p2card == 2)
        {
            p2cardName = "2";
        } 
        else if (p2card == 3) 
        {
            p2cardName = "3";
        } 
        else if (p2card == 4) 
        {
            p2cardName = "4";
        } 
        else if (p2card == 5) 
        {
            p2cardName = "5";
        }
        else if (p2card == 6) 
        {
            p2cardName = "6";
        }
        else if (p2card == 7) 
        {
            p2cardName = "7";
        }
        else if (p2card == 8) 
        {
            p2cardName = "8";
        }
        else if (p2card == 9) 
        {
            p2cardName = "9";
        }
        else if (p2card == 10) 
        {
            p2cardName = "10";
        }
        else if (p2card == 11) 
        {
            p2cardName = "Jack";
        }
        else if (p2card == 12) 
        {
            p2cardName = "Queen";
        }
        else if (p2card == 13) 
        {
            p2cardName = "King";
        }
        else if (p2card == 14) 
        {
            p2cardName = "Ace";
        }

        
        cout << "---------------" << endl;
        cout << "Player 2's Turn" << endl;
        cout << "---------------" << endl;
   
        cout  << p2cardName << " of " << p2suit << " is your card"<< endl;
    
        char p2Input; 
        cout << "Enter 'k' to keep card or 's' to swap card with next player"<< endl;
        cin >> p2Input;
    
        if(p2Input == 'k')
        {
            cout << "You keep your card" << endl;
        }
        else if(p2Input == 's')
        {
            cout << "You swap your card" << endl;
            tempSwap = p2card;
            p2card = computercard;
            computercard = tempSwap;
            
            tempSuit = p2suit;
            p2suit = computersuit;
            computersuit = tempSuit;
            
            if (p2card == 2)
            {
                p2cardName = "2";
            } 
            else if (p2card == 3) 
            {
                p2cardName = "3";
            } 
            else if (p2card == 4) 
            {
                p2cardName = "4";
            } 
            else if (p2card == 5) 
            {
                p2cardName = "5";
            }
            else if (p2card == 6) 
            {
                p2cardName = "6";
            }
            else if (p2card == 7) 
            {
                p2cardName = "7";
            }
            else if (p2card == 8) 
            {
                p2cardName = "8";
            }
            else if (p2card == 9) 
            {
                p2cardName = "9";
            }
            else if (p2card == 10) 
            {
                p2cardName = "10";
            }
            else if (p2card == 11) 
            {
                p2cardName = "Jack";
            }
            else if (p2card == 12) 
            {
                p2cardName = "Queen";
            }
            else if (p2card == 13) 
            {
                p2cardName = "King";
            }
            else if (p2card == 14) 
            {
                p2cardName = "Ace";
            }
            
            cout  << p2cardName << " of " << p2suit << " is your new card"<< endl;
        }
        
        //Computer's Turn ------------------------------------------------------------------------
        
       
        
        if (computercard == 2)
        {
        computercardName = "2";
        }
        else if (computercard == 3)
        {
        computercardName = "3";
        }
        else if (computercard == 4)
        {
        computercardName = "4";
        }
        else if (computercard == 5)
        {
        computercardName = "5";
        }
        else if (computercard == 6)
        {
        computercardName = "6";
        }
        else if (computercard == 7)
        {
        computercardName = "7";
        }
        else if (computercard == 8)
        {
        computercardName = "8";
        }
        else if (computercard == 9)
        {
        computercardName = "9";
        }
        else if (computercard == 10)
        {
        computercardName = "10";
        }
        else if (computercard == 11)
        {
        computercardName = "Jack";
        }
        else if (computercard == 12)
        {
        computercardName = "Queen";
        }
        else if (computercard == 13)
        {
        computercardName = "King";
        }
        else if (computercard == 14)
        {
        computercardName = "Ace";
        }
        
        cout << "---------------" << endl;
        cout << "Computer's Turn" << endl;
        cout << "---------------" << endl;
        int computerDecision = computer_decide();
         
         
        /*
        cout << "DEBUG: " << computercard << computersuit << endl;
        */

        //Having the computer decide whether to swap their card based on a number between 1 and 8
        //If card is below 5, computer will always swap
        bool noDuplicates = false;
        //THIRD UNIQUE FEATURE
        if(computercard <= 5)
        {
            cout << "Computer decides to swap their card" << endl;
            noDuplicates = true;
        }
        //Computer picks random number, the higher the card value, the less likely computer is to switch their card
        else if(computercard = 6)
        {
            if(computerDecision > 4)
            {
                 cout << "Computer decides to swap their card" << endl;
                 noDuplicates = true;
            }
            else
            {
                cout << "Computer decides to keep their card" << endl;
            }
        }
        else if(computercard = 7)
        {
            if(computerDecision > 5)
            {
                 cout << "Computer decides to swap their card" << endl;
                 noDuplicates = true;
            }
            else
            {
                cout << "Computer decides to keep their card" << endl;
            }
        }
        else if(computercard = 8)
        {
            if(computerDecision > 6)
            {
                 cout << "Computer decides to swap their card" << endl;
                 noDuplicates = true;
            }
            else
            {
                cout << "Computer decides to keep their card" << endl;
            }
        }
        else if(computercard = 9)
        {
            if(computerDecision > 7)
            {
                 cout << "Computer decides to swap their card" << endl;
                 noDuplicates = true;
            }
            else
            {
                cout << "Computer decides to keep their card" << endl;
            }
        }
        else if(computercard > 9)
        {
            cout << "Computer decides to keep their card" << endl;
        }
        
        int newcompcard = computercard;
        string newcompsuit = computersuit;
        if(noDuplicates == true)
        {
            noDuplicates = false;
            do{
                newcompcard = shuffle_deck();
                newcompsuit = shuffle_suit();
            }while((newcompcard == p1card && newcompsuit == p1suit) || 
        (newcompcard == p2card && newcompsuit == p2suit));
        
        computercard = newcompcard;
        computersuit = newcompsuit;
        }
        
        if (computercard == 2)
            {
                computercardName = "2";
            }
            else if (computercard == 3)
            {
                computercardName = "3";
            }
            else if (computercard == 4)
            {
                computercardName = "4";
            }
            else if (computercard == 5)
            {
                computercardName = "5";
            }
            else if (computercard == 6)
            {
                computercardName = "6";
            }
            else if (computercard == 7)
            {
                computercardName = "7";
            }
            else if (computercard == 8)
            {
                computercardName = "8";
            }
            else if (computercard == 9)
            {
                computercardName = "9";
            }
            else if (computercard == 10)
            {
                computercardName = "10";
            }
            else if (computercard == 11)
            {
                computercardName = "Jack";
            }
            else if (computercard == 12)
            {
                computercardName = "Queen";
            }
            else if (computercard == 13)
            {
                computercardName = "King";
            }
            else if (computercard == 14)
            {
                computercardName = "Ace";
            }
        cout << "--------------------------" << endl;
        cout << "EVERYONE REVEAL YOUR CARDS" << endl;
        cout << "--------------------------" << endl;
        
        cout << "Player 1's card is: " << p1cardName << " of " << p1suit << endl;
        cout << "Player 2's card is: " << p2cardName << " of " << p2suit << endl;
        cout << "Computer's card is: " << computercardName << " of " << computersuit << endl;
        
        //Defines whether the players card is red or black---------------------------------------
        if((p1suit == "Hearts")||(p1suit == "Diamonds"))
        {
            p1suit = "red";
        }
        else
        {
            p1suit = "black";
        }
        
        if((p2suit == "Hearts")||(p2suit == "Diamonds"))
        {
            p2suit = "red";
        }
        else
        {
            p2suit = "black";
        }
        
        if((computersuit == "Hearts")||(computersuit == "Diamonds"))
        {
            computersuit = "red";
        }
        else
        {
            computersuit = "black";
        }
        /*
        cout << "DEBUG: " << p1card << p1suit << endl;
        cout << "DEBUG: " << p2card << p2suit << endl;
        cout << "DEBUG: " << computercard << computersuit << endl;
        */
        //----------------------------------------------------
        
        //Checking for the winner
        if((p1card <= p2card)&&(p1card <= computercard))
        {
            if((p1card == p2card)&&(p1suit == "black")&&(p2suit == "red"))
            {
                cout << "Player 1 loses this round and loses a life!" << endl;
                p1Lives = p1Lives - 1;
            }
            else if((p1card == computercard)&&(p1suit == "black")&&(computersuit == "red"))
            {
                cout << "Player 1 loses this round and loses a life!" << endl;
                p1Lives = p1Lives - 1;
            }
            else if((p1card < p2card)&&(p1card < computercard))
            {
                cout << "Player 1 loses this round and loses a life!" << endl;
                p1Lives = p1Lives - 1;
            }
        }
        else if((p2card <= p1card)&&(p2card <= computercard))
        {
            if((p2card == p1card)&&(p2suit == "black")&&(p1suit == "red"))
            {
                cout << "Player 2 loses this round and loses a life!" << endl;
                p2Lives = p2Lives - 1;
            }
            else if((p2card == computercard)&&(p2suit == "black")&&(computersuit == "red"))
            {
                cout << "Player 2 loses this round and loses a life!" << endl;
                p2Lives = p2Lives - 1;
            }
            else if((p2card < p1card)&&(p2card < computercard))
            {
                cout << "Player 2 loses this round and loses a life!" << endl;
                p2Lives = p2Lives - 1;
            }
        }
        else if((computercard <= p2card)&&(computercard <= p1card))
        {
            if((computercard == p2card)&&(computersuit == "black")&&(p2suit == "red"))
            {
                cout << "Computer loses this round and loses a life!" << endl;
                computerLives = computerLives - 1;
            }
            else if((computercard == p1card)&&(computersuit == "black")&&(p1suit == "red"))
            {
                cout << "Computer loses this round and loses a life!" << endl;
                computerLives = computerLives - 1;
            }
            else if((computercard < p1card)&&(computercard < p2card))
            {
                cout << "Computer loses this round and loses a life!" << endl;
                computerLives = computerLives - 1;
            }
        }
        else{
            cout << "There is a tie! Let the game continue!" << endl;
        }
        
        //Display Current Player Lives
        cout << "Player 1 has : " << p1Lives << " lives remaining" << endl;
        cout << "Player 2 has : " << p2Lives << " lives remaining" << endl;
        cout << "Computer has : " << computerLives << " lives remaining" << endl;
        
    }while((p1Lives > 0) && (p2Lives > 0) && (computerLives > 0));

    
    cout << "--------" << endl;
    cout << "GAME END" << endl;
    cout << "--------" << endl;
    if(p1Lives == 0)
    {
        cout << "Player 1 Loses!" << endl;
        cout << "Player 2's remaining lives are: " << p2Lives << endl;
        cout << "Computer's remaining lives are: " << computerLives << endl;
        if(p2Lives > computerLives)
        {
            cout << "Player 2 has the most lives so they win the game!" << endl;
        }
        else if(p2Lives < computerLives)
        {
            cout << "Computer has the most lives so they win the game!" << endl;
        }
        else if(p2Lives == computerLives)
        {
            cout << "The remaining player's lives are equal so the game DRAWS!" << endl;
        }
    }
    else if(p2Lives == 0)
    {
        cout << "Player 2 Loses!" << endl;
        cout << "Player 1's remaining lives are: " << p1Lives << endl;
        cout << "Computer's remaining lives are: " << computerLives << endl;
        if(p1Lives > computerLives)
        {
            cout << "Player 1 has the most lives so they win the game!" << endl;
        }
        else if(p1Lives < computerLives)
        {
            cout << "Computer has the most lives so they win the game!" << endl;
        }
        else if(p1Lives == computerLives)
        {
            cout << "The remaining player's lives are equal so the game DRAWS!" << endl;
        }
    }
    else if(computerLives == 0)
    {
        cout << "Computer Loses!" << endl;
        cout << "Player 1's remaining lives are: " << p1Lives << endl;
        cout << "Player 2's remaining lives are: " << p2Lives << endl;
        if(p1Lives > p2Lives)
        {
            cout << "Player 1 has the most lives so they win the game!" << endl;
        }
        else if(p1Lives < p2Lives)
        {
            cout << "Player 2 has the most lives so they win the game!" << endl;
        }
        else if(p1Lives == p2Lives)
        {
            cout << "The remaining player's lives are equal so the game DRAWS!" << endl;
        }
    }
    
    char returnInput;
    //Loop to let user decide to return to main menu or quit
    do{
    cout<<"Do you wish to return to Main Menu?" << endl;
    
    cout<<"Enter 'r' to return to main menu or 'q' to quit game" << endl;
    cin >> returnInput;
    switch (returnInput) {
        case 'r':
            cout << "Restarting game..." << endl;
            main();
            break;
        case 'q':
            cout << "Exiting game..." << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
    }
    }while(returnInput != 'r');
    
}