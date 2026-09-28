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

// Display all registered students
void displayStudents(Node* head)
{
    if (head == NULL)
    {
        cout << "No students registered." << endl;
        return;
    }

    cout << "Registered Students: ";

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

int main()
{
    // Create an empty linked list
    Node* head = NULL;

    // Add students
    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    // Display students
    displayStudents(head);

    // Search for a student
    int rollNumber;

    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    searchStudent(head, rollNumber);

    return 0;
}


