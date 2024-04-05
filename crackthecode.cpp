#include <iostream>
using namespace std;

bool checkPlayerChoice(int playerChoice) {
    if (playerChoice == 1 || playerChoice == 2)
    {
        return true;
    }
    else {
        return false;
    }
}

bool checkDigits(int guess) {
    int count = 0;
    while(guess != 0) {
      guess = guess / 10;
      count++;
   }
   if (count == 4)
   {
    return true;
   }
   else {
    return false;
   }
}

void checkGuess(int guess, int code, bool gameOver) { //count how many tries
    int guessArray[4];
    int codeArray[4];
    for (int i = 0; i < 4; i++) //transfer code & guess into array
    {
        guessArray[i] = guess % 10;
        codeArray[i] = code % 10;

        guess /= 10;
        code /= 10;
    }
    int occurence = 0;
    for (int i = 0; i < 4; i++) //comparing number positions
    {
        if (guessArray[i] == codeArray[i])
        {
            ++occurence;
        }
    }
    if (occurence == 4) //if all number occur in right position gameOver = true
    {
        cout << "Congratualitions you cracked the code! All numbers are in the right position.";
        gameOver = true;
    }
    else {
        if (occurence == 0) 
        {
            cout << "No numbers are in the right position" << endl;
        }
        else if (occurence == 1)
        {
            cout << occurence << " number is in the right position." << endl;
        }
        else {
            cout << occurence << " numbers are in the right position." << endl;
        }
    }
}

void PlayervCPU(bool gameOver) { //runs until game is complete
    srand( time(NULL) );
    int code = rand() % 10000;
    int guess;

    cout << "You chose option 1: Player vs. CPU" << endl;
    cout << "You will now have to crack the CPU'S 4 digit code" << endl;
    cout << "Guess a 4 digit number: ";

    while (!gameOver) //while loop to ask for guesses until code is found
    {   
        cin >> guess;
        if (checkDigits(guess)) {
            checkGuess(guess, code, gameOver);
            if (gameOver == true)
            {
                break;
            }
        }
        else {
            cout << guess << " is not a 4 digit code, try again." << endl;
            cout << "Guess a 4 digit number: ";
        }
    }
    
}

void PlayervPlayer() {
    
}

int main() {
    bool gameOver = false;
    int playerChoice;
    
    //while loop - if gameOver is not true (false) game will continue
    while (!gameOver)
    {
        cout << "Welcome to Crack the Code!" << endl;
        cout << "1. Player vs. CPU\n2. Player vs. Player" << endl;
        cout << "Select which mode you would like to play: ";
        cin >> playerChoice;
        if (checkPlayerChoice(playerChoice)) //if playerChocie is elligble = switch case to access either game mode
        {
            switch (playerChoice) //no default needed only runs if playerChoice is option 1 or 2
            {
            case 1: //PlayervCPU function
                PlayervCPU(gameOver);
                break;
            case 2: //PlayervPlayer function
                /* code */
                break;
            }
        }
        else { //reruns checkPlayerChoice fucntion until true
            while (true)
            {
                cout << playerChoice << " is not an option. Please try again." << endl;
                cout << "1. Player vs. CPU\n2. Player vs. Player" << endl;
                cin >> playerChoice;
                if (checkPlayerChoice(playerChoice)) {
                    switch (playerChoice) //no default needed only runs if playerChoice is option 1 or 2
                    {
                    case 1: //PlayervCPU function
                        PlayervCPU(gameOver);
                        break;
                    case 2: //PlayervPlayer function
                        /* code */
                        gameOver = true;
                        break;
                    }
                    break;
                }
            }
            
        }
        break;
    }
    
}