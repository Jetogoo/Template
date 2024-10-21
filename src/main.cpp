#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct gameConfig{
  string myName;
  int maxNum;
  int minNum;
};

class Game {
private:
    int guesses;
    int ranNumber;
    gameConfig config;

public:
    Game(gameConfig gameConfig) {
       

        config = gameConfig;
        guesses = 0;
        srand(time(NULL));
        ranNumber = (rand() % config.maxNum) + config.minNum;
    }


    void display() {
        cout << "Guesses: " << guesses << endl;
        cout << ranNumber << endl;
    }

    void playGame() {
        int guess;

        cout << "Welcome to the Guessing Game " << config.myName << "!" << endl;
        cout << "You have 10 guesses" << endl;

        do {
            cout << "Enter your guess (1-100): ";
            cin >> guess;
            while (guess > config.maxNum || guess < config.minNum){
                cout << "Incorrect input, try agian." << endl;
                cin >> guess;
            }
            guesses++;

            if (guess < ranNumber) {
                cout << "Too low!" << endl;
            } else if (guess > ranNumber) {
                cout << "Too high!" << endl;
            }
        } while (guess != ranNumber && guesses < 10);
        if (guess == ranNumber){
            cout << "Congrats " << config.myName << ", you guessed the number " << ranNumber << " in " << guesses << " attempts!" << endl;
        } else if (guesses <= 10){
            cout << "Sorry " << config.myName << ", you ran out of guesses! The number was " << ranNumber << endl;
        }

    }


};

int main(){
    gameConfig config;
    config.minNum = 1;
    config.maxNum = 100;

    cout << "Enter your name: ";
    cin >> config.myName;

    Game player(config);
   
    player.playGame();

   
    return 0;
}