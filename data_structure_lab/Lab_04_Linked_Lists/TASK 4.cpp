#include <iostream>

using namespace std;

// Node structure
struct Node
{
    int rollNumber;
    Node* next;
};

// Add a student at the end
void addStudent(Node*& head, int rollNumber)
{
    Node* newNode = new Node;

    newNode->rollNumber = rollNumber;
    newNode->next = NULL;

    // If the list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Move to the last node
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Add the new student
    temp->next = newNode;
}

// Insert a student at the beginning
void insertAtBeginning(Node*& head, int rollNumber)
{
    Node* newNode = new Node;

    newNode->rollNumber = rollNumber;
    newNode->next = head;

    head = newNode;
}

// Search for a student
void searchStudent(Node* head, int rollNumber)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->rollNumber == rollNumber)
        {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student Not Found" << endl;
}

// Display all students
void displayStudents(Node* head)
{
    if (head == NULL)
    {
        cout << "No students enrolled." << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->rollNumber;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    // Create an empty linked list
    Node* head = NULL;

    // Initially: 22 -> 35 -> 41 -> 56
    addStudent(head, 22);
    addStudent(head, 35);
    addStudent(head, 41);
    addStudent(head, 56);

    cout << "Initially: ";
    displayStudents(head);

    // Insert 18 at the beginning
    insertAtBeginning(head, 18);

    cout << "After insertion: ";
    displayStudents(head);

    // Search for a student
    int rollNumber;

    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    searchStudent(head, rollNumber);

    return 0;
}

