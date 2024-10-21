#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum gameState {
    WON, LOST, PLAYING
};

class Game {
private:
    string name;
    int guesses;
    int ranNumber;

public:
      // Constructor that takes user input
    Game() {
        cout << "Enter name: ";
        cin >> name;

        guesses = 0;
        srand(time(NULL));
        ranNumber = (rand() % 100) + 1;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Guesses: " << guesses << endl;
        cout << ranNumber << endl;
    }


};

int main(){
    cout << "Hello world" << endl;
    Game player;

    player.display();

    return 0;
}