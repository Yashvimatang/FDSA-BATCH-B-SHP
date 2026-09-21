#include <iostream>
using namespace std;
struct node
{
    string data;
    node *next;
    node *prev;
};
node *head = NULL;
void insertfirst(string song)
{
    node *newnode = new node();
    newnode->data = song;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}
void insertlast(string song)
{
    node *newnode = new node();
    newnode->data = song;
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void insertAfter(string presong, string newsong)
{
    node *temp = head;
    while (temp != NULL && temp->data != presong)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "The pre song not found";
        return;
    }
    node *newnode = new node();
    newnode->data = newsong;
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}
void deletefirst()
{
    if (head == NULL)
    {
        cout << "The playlist is compelety empty";
        return;
    }

    node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;
}
int countsong()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int choice;
    string presong;
    string newsong;
    while (true)
    {
        cout << endl;
        cout << "------MUSIC PLAYLIST------"<<endl;
        cout << "1. Add song at beginning" << endl;
        cout << "2. Add song at end" << endl;
        cout << "3. Insert song after a specific song" << endl;
        cout << "4. Remove first song" << endl;
        cout << "5. Count songs" << endl;
        cout << "6. Display playlist" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "Enter the song to be added:";
            cin >> newsong;
            insertfirst(newsong);
        }
        else if (choice == 2)
        {
            cout << "Enter the song to be added:";
            cin >> newsong;
            insertlast(newsong);
        }
        else if (choice == 3)
        {
            cout << "Enter the specific song to be added:";
            cin >> presong;
            cout << "Enter the song to be added:";
            cin >> newsong;
            insertAfter(presong,newsong);
        }
        else if (choice == 4)
        {
            deletefirst();
        }
        else if (choice == 5)
        {
           cout<<" Total number of songs are: "<< countsong();
        }
        else if (choice == 6)
        {
            display();
        }
        else if (choice == 7)
        {
            cout << "Playlist ended." << endl;
            break;
        }
        else
        {
            cout << "Please enter a valid choice";
        }
    }
    return 0;
}
