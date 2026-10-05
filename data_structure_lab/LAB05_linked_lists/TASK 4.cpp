#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void addSong(string name) {
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

    void displayOnce() {
        Node* current = head;

        cout << "Playlist:\n";

        if (head != NULL) {
            do {
                cout << current->song << endl;
                current = current->next;
            } while (current != head);
        }
    }

    void playTwoRounds() {
        Node* current = head;

        cout << "\nPlaying playlist for 2 rounds:\n";

        for (int i = 0; i < 10; i++) {
            cout << "Playing: " << current->song << endl;
            current = current->next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");
    playlist.addSong("Song D");
    playlist.addSong("Song E");

    playlist.displayOnce();

    playlist.playTwoRounds();

    return 0;
}

