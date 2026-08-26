#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = NULL;
void insertfront(int value)
{
    node *newnode = new node();
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void insertend(int value)
{
    node *newnode = new node();
    newnode->data = value;
    newnode->next = NULL;
    // saje linked list me hekdo j node aye
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    // ye while loop temp ko last node pe point karva dega
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertPosition(int value, int p)
{
    if (p <= 0)
    {
        cout << "Please enter a valid position";
        return;
    }
    if (p == 1)
    {
        insertfront(value);
        return;
    }
    node *newnode = new node();
    newnode->data = value;
    node *temp = head;
    for (int i = 1;i < p - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    // 20->30 me 25 add karna hai toh 20 aur 30 ke link todhne padhge aur 20 ke link me 25 ka address aur 25 ke link me 30 ka address
    newnode->next = temp->next;
    temp->next = newnode;
}
void display()
{
    node *temp = head;
    while (temp != NULL){
        cout << temp->data;
        if (temp->next != NULL){
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int choice;
    int value;
    int position;
    while (true)
    {
        cout << "--- Hospital Patient Queue ---" << endl;
        cout << "1. Add critical patient at front" << endl;
        cout << "2. Add routine patient at end" << endl;
        cout << "3. Insert patient at position" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter patient token :";
            cin >> value;
            insertfront(value);

            cout << "Queue after insertion: ";
            display();
        }
        else if (choice == 2)
        {
            cout << "Enter patient token :";
            cin >> value;
            insertend(value);
            cout << "Queue after insertion: ";
            display();
        }
        else if (choice == 3)
        {
            cout << "Enter patient token :";
            cin >> value;
            cout << "Enter position:";
            cin >> position;
            insertPosition(value, position);
            cout << "Queue after insertion: ";
            display();
        }
        else if (choice == 4)
        {
            cout << "Queue after insertion: ";
            display();
        }
        else if (choice == 5)
        {
            cout << "Program ended.";
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
