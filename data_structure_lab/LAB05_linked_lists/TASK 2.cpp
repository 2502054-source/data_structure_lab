#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name) {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

class ImageGallery {
private:
    Node* head;
    Node* tail;

public:
    ImageGallery() {
        head = NULL;
        tail = NULL;
    }

    void addImage(string name) {
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

        cout << "Images (First -> Last):\n";

        while (current != NULL) {
            cout << current->image << endl;
            current = current->next;
        }
    }

    void displayBackward() {
        Node* current = tail;

        cout << "\nImages (Last -> First):\n";

        while (current != NULL) {
            cout << current->image << endl;
            current = current->prev;
        }
    }
};

int main() {
    ImageGallery gallery;

    gallery.addImage("Nature.jpg");
    gallery.addImage("Mountain.jpg");
    gallery.addImage("Beach.jpg");
    gallery.addImage("City.jpg");
    gallery.addImage("Sunset.jpg");

    gallery.displayForward();
    gallery.displayBackward();

    return 0;
}

