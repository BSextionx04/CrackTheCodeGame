#include <iostream>
#include <vector>

using namespace std;

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

void checkGuess(int guess, int code, bool& gameStatus) {
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
    for (int i = 0; i < 4; i++) //find occurence
    {
        if (guessArray[i] == codeArray[i])
        {
            ++occurence;
        }
    }
    if (occurence == 4) //if all number occur in right position gameOver = true
    {
        cout << "\nCongratulations you cracked the code!\nAll numbers are in the right position!" << endl;
        gameStatus = true;
    }
    else {
        if (occurence == 0) 
        {
            cout << "No numbers are in the right position." << endl << endl;
        }
        else if (occurence == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                if (guessArray[i] == codeArray[i])
                {
                    cout << guessArray[i] << " is in the right position.\n" << endl;
                }
            }
        }
        else if (occurence == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                if (guessArray[i] == codeArray[i])
                {
                    int count = 0;
                    if (count == 0)
                    {
                        cout << guessArray[i] << " and ";
                    }
                    else {
                        cout << guessArray[i];
                    }
                    ++count;
                }
            }
            cout << " are in the right position.\n" << endl;
        }   
        else if (occurence == 3)
        {
            for (int i = 0; i < 4; i++)
            {
                if (guessArray[i] == codeArray[i])
                {
                    int count = 0;
                    if (count == 0)
                    {
                        cout << guessArray[i] << ", ";
                    }
                    else if (count == 1)
                    {
                        cout << guessArray[i] << ", and ";;
                    }
                    else {
                        cout << guessArray[i];
                    }
                    ++count;
                }
            }
            cout << " are in the right position.\n" << endl;
        }
    }
}

void PlayervCPU(bool& gameOver) { //runs until game is complete
    srand( time(NULL) );
    int code = rand() % 9000 + 1000;
    int guess;
    int tries = 0;

    cout << "The CPU has entered in a 4 digit code" << endl;
    cout << "You will now have to crack the CPU'S code\n" << endl;
    cout << "Guess a 4 digit number: ";

    while (!gameOver) //while loop to ask for guesses until code is found
    {   
        cin >> guess;
        if (checkDigits(guess)) {
            checkGuess(guess, code, gameOver);
            if (!gameOver)
            {
                cout << "Guess a 4 digit number: ";
            }
            else {
                break;
            }
        }
        else {
            cout << guess << " is not a 4 digit code, try again.\n" << endl;
            cout << "Guess a 4 digit number: ";
        }
        ++tries;
    }
    cout << "\nIt took you " << tries << " tries to crack the code." << endl;
}
    

int main() {
    bool gameOver = false;
    int playerChoice;
    
    //while loop - if gameOver is not true (false) game will continue
    while (!gameOver)
    {
        cout << "Welcome to Crack the Code!\n" << endl;
        PlayervCPU(gameOver);
    }
    
}