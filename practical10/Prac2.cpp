#include <iostream>
using namespace std;

struct Node
{
    int code;
    Node *next;
};

Node *shelf[10];

void initialize()
{
    for (int i = 0; i < 10; i++)
    {
        shelf[i] = NULL;
    }
}

void insertBook(int code)
{
    int index = code % 10;

    Node *newNode = new Node;

    newNode->code = code;
    newNode->next = shelf[index];

    shelf[index] = newNode;

    cout << "Book " << code
         << " placed on shelf " << index << endl;
}

void display()
{
    cout << "\nFinal Shelves:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "Shelf " << i << ": ";

        Node *temp = shelf[i];

        if (temp == NULL)
        {
            cout << "Empty";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->code << " -> ";
                temp = temp->next;
            }

            cout << "NULL";
        }

        cout << endl;
    }
}

int main()
{
    initialize();

    int n;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int code;

        cout << "Enter book code: ";
        cin >> code;

        insertBook(code);
    }

    display();

    return 0;
}