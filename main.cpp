#include <iostream>
#include <string> //Needed to use strings
#include <cstdlib> //Needed to use random numbers (using -> pseudo-random number generation (deterministic random bit generator))
#include <ctime>
using namespace std;
void drawLine(int n, char symbol);
void NewRules();
void logo();

int main()
{
    system("color 0D"); //0 = Black (background) ; D = Light Purple (Text)
    string playerName;
    float balance; //hold player's balance amount
    float bettingAmount;  //Money betting
    int guess; //picking a number
    int max_choice;  //holds the number either 5, 15, 25
    int dice; //hold computer generated number
    int bet_multiplier;  //the betting amount you chose times either 2(Easy), 5(meidum), 10(hard)
    char difficulty; //for easy, medium, or hard
    char choice;  //to play again
    bool valid_choice; //if wrong input, loops again until it gets either e, m, or h FIRST!!!
    bool running = true;   //to stop or keep playing

    srand(time(0)); // Sets the random number generator’s seed value (pseudo-random number generation)

    logo(); //saves me space :) function

    cout << "\n\nEnter Your Name: ";
    cin >> playerName;
    cout << "\nEnter Deposit amount to play game: $";
    cin >> balance;

    while(running == true){
        system("cls");
        cout << "\n\nYour current balance is $" << balance << "\n";

        // Get player's betting amount
        do {
            cout << playerName << ", enter money to bet: $";
            cin >> bettingAmount;
            if(bettingAmount > balance) {
                cout << "Your betting amount is more than your current balance\n";
                cout << "\nRe-enter data\n ";
            }
        }while(bettingAmount > balance);

        // Get player's numbers with easy, medium, or hard vvvv
        NewRules();    //calling funtion
        valid_choice = false;    //looping the options if they mistype (e,m, or h)
        while(valid_choice == false) {
            cout << "Choose Difficulty: (E)asy, (M)edium, or (H)ard: ";
            cin >> difficulty;
            switch (char(tolower(difficulty))) {
                case 'e':
                    valid_choice = true;
                    max_choice = 5;
                    bet_multiplier = 2;
                    break;
                case 'm':
                    valid_choice = true;
                    max_choice = 15;
                    bet_multiplier = 5;
                    break;
                case 'h':
                    valid_choice = true;
                    max_choice = 25;
                    bet_multiplier = 10;
                    break;
                default:
                    cout << "\nPlease enter a correct choice.\n";
                    break;
            }
            //also able to do easy, medium, and hard with this since it only takes the first letter.vvvv
            cin.seekg(0, ios::end);  //moving cin buffer (0,1,2,3,4,5...) to end of line
            cin.clear();    //clears everything behind the cursor (cursor = pointers)
        }

        do{
            cout << "Guess your number to between 1 to " << max_choice << ":";  //max choice being with 5, 15, 25.
            cin >> guess;
            if(guess <= 0 || guess > max_choice){
                cout << "Please check a correct number choice!! Should be between 1 to " << max_choice << "\n"
                     <<"\nRe-enter data\n ";
                }
        }while(guess <= 0 || guess > max_choice);

        dice = rand()%max_choice + 1; //Will hold the randomly generated integer between 1 and whatever number from the e, m, or h choice.
        cout << "\nThe winning number was: " << dice <<"\n";

        if(dice == guess)
        {
            cout << "\nGood Luck!! You won $" << bettingAmount * bet_multiplier; //bet multiplier being 2, 5, 10.
            balance = balance + bettingAmount * bet_multiplier; //if player wins amount goes higher
        }
        else
        {
            cout << "Bad Luck... You lost $"<< bettingAmount <<"\n";
            balance = balance - bettingAmount;  //player loses amount goes lower :(
        }

        cout << "\n"<<playerName<<", You have $" << balance << "\n"; //amount located
        if(balance == 0)
        {
            cout << "You have no money to play.:(";
            break; //makes sure the game ends.
        }

        cout << "\n\nDo you wish to play again (y/n)? ";
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){  //to either keep playing (looping again) or stop playing (no loop)
            running = true;
        }
        else{
            running = false;
        }
    }

    cout << "\n\n";
    drawLine(70,'=');
    cout << "\nThanks for playing game. Your balance amount is $" << balance << "\n\n";  //Work if they don't choose y
    drawLine(70,'=');

    return 0;
}

void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
void NewRules()
{
    system("cls");
    cout << "\n\n";
    drawLine(60,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(60,'-');
    cout << "\n\t1. Choose any from either (E)asy, (M)edium, or (H)ard.\n";
    cout << "\t2. If you win on easy, you'll get 2 times the money you bet!!\n";
    cout << "\t3. If you win on medium, you'll get 5 times the money you bet!!\n";
    cout << "\t4. If you win on hard, you'll get 10 times the money you bet!!\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount...\n\n";
    drawLine(60,'-');
}
void logo(){
    drawLine(45,'~');
    drawLine(45,'~');
    cout << "\n\t\tCASINO GAME\n\n";
    cout << "\tFinal Project for COP 2006\n";
    drawLine(45,'~');
    drawLine(45,'~');
}
