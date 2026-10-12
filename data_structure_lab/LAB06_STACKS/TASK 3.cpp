#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string player;
    Node* next;

    Node(string name) {
        player = name;
        next = NULL;
    }
};

class Game {
private:
    Node* head;
    Node* tail;

public:
    Game() {
        head = NULL;
        tail = NULL;
    }

    void addPlayer(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void displayTurns() {
        Node* current = head;

        cout << "Player Turns:\n";

        if (head != NULL) {
            do {
                cout << current->player << endl;
                current = current->next;
            } while (current != head);
        }
    }

    void showNextTurn() {
        cout << "\nAfter the last player, turn returns to: "
             << head->player << endl;
    }
};

int main() {
    Game game;

    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Usman");
    game.addPlayer("Bilal");
    game.addPlayer("Hamza");

    game.displayTurns();
    game.showNextTurn();

    return 0;
}

