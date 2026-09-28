#include <iostream>
#include <string.h>

using namespace std;

// Node structure
struct Node
{
    char productID[20];
    Node* next;
};

// Add product at the end
void addProduct(Node*& head, const char id[])
{
    Node* newNode = new Node;

    strcpy(newNode->productID, id);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display all products
void displayCart(Node* head)
{
    if (head == NULL)
    {
        cout << "Shopping Cart is empty." << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->productID;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

// Remove product using Product ID
void removeProduct(Node*& head, const char id[])
{
    if (head == NULL)
    {
        cout << "Shopping Cart is empty." << endl;
        return;
    }

    // If the first product is being removed
    if (strcmp(head->productID, id) == 0)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        cout << "Product " << id << " removed." << endl;
        return;
    }

    Node* temp = head;

    // Find the product
    while (temp->next != NULL &&
           strcmp(temp->next->productID, id) != 0)
    {
        temp = temp->next;
    }

    // Product found
    if (temp->next != NULL)
    {
        Node* deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;

        cout << "Product " << id << " removed." << endl;
    }
    else
    {
        cout << "Product " << id << " not found." << endl;
    }
}

int main()
{
    Node* head = NULL;

    // Add products
    addProduct(head, "P101");
    addProduct(head, "P205");
    addProduct(head, "P310");
    addProduct(head, "P415");

    // Display shopping cart
    cout << "Shopping Cart: ";
    displayCart(head);

    // Remove a product
    char productID[20];

    cout << "Remove Product: ";
    cin >> productID;

    removeProduct(head, productID);

    // Display updated cart
    cout << "Updated Cart: ";
    displayCart(head);

    return 0;
}

