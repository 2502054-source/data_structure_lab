#include <iostream>
#include <string>

using namespace std;

// Node structure
struct Node
{
    string patientID;
    Node* next;
};

// Add a patient at the end
void addPatient(Node*& head, string patientID)
{
    Node* newNode = new Node;

    newNode->patientID = patientID;
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

    // Add new patient
    temp->next = newNode;
}

// Display all patients
void displayPatients(Node* head)
{
    if (head == NULL)
    {
        cout << "No patients are waiting." << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->patientID;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

// Remove the first patient
void removeFirstPatient(Node*& head)
{
    if (head == NULL)
    {
        cout << "No patient to serve." << endl;
        return;
    }

    Node* temp = head;

    cout << "Patient " << temp->patientID
         << " is being served." << endl;

    head = head->next;

    delete temp;
}

int main()
{
    // Create an empty linked list
    Node* head = NULL;

    // Add patients
    addPatient(head, "P101");
    addPatient(head, "P102");
    addPatient(head, "P103");
    addPatient(head, "P104");

    // Display waiting patients
    cout << "Waiting Patients: ";
    displayPatients(head);

    // Remove first patient
    removeFirstPatient(head);

    // Display updated queue
    cout << "Updated Queue: ";
    displayPatients(head);

    return 0;
}

