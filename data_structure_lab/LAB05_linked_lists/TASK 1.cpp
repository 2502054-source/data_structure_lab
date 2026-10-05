#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    void addWebsite(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        Node* current = head;

        cout << "History (First -> Last):\n";

        while (current != NULL) {
            cout << current->website << endl;
            current = current->next;
        }
    }

    void displayBackward() {
        Node* current = tail;

        cout << "\nHistory (Last -> First):\n";

        while (current != NULL) {
            cout << current->website << endl;
            current = current->prev;
        }
    }
};

int main() {
    BrowserHistory history;

    history.addWebsite("Google.com");
    history.addWebsite("YouTube.com");
    history.addWebsite("Facebook.com");
    history.addWebsite("Wikipedia.org");
    history.addWebsite("GitHub.com");

    history.displayForward();
    history.displayBackward();

    return 0;
}

