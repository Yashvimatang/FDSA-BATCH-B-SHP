#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
node *headSingly = NULL;
node *headDoubly = NULL;
void insertFrontSingly(int value){
    node *newnode = new node();
    newnode->data = value;
    if (headSingly == NULL){
        headSingly = newnode;
        newnode->next = headSingly;
        return;
    }
    node *temp = headSingly;
    while (temp->next != headSingly){
        temp = temp->next;
    }
    newnode->next = headSingly;
    temp->next = newnode;
    headSingly = newnode;
}
void insertEndSingly(int value){
    node *newnode = new node();
    newnode->data = value;
    if (headSingly == NULL){
        headSingly = newnode;
        newnode->next = headSingly;
        return;
    }
    node *temp = headSingly;
    while (temp->next != headSingly){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = headSingly;
}
void insertPositionSingly(int value, int position){
    if (position <= 0){
        cout << "Invalid position!" << endl;
        return;
    }
    if (headSingly == NULL){
        if (position == 1){
            insertEndSingly(value);
        }
        else{
            cout << "Invalid position!" << endl;
        }
        return;
    }
    if (position == 1){
        insertFrontSingly(value);
        return;
    }
    node *temp = headSingly;
    for (int i = 1; i < position - 1; i++){
        temp = temp->next;
        if (temp == headSingly){
            cout << "Invalid position!" << endl;
            return;
        }
    }
    node *newnode = new node();
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteSingly(int value){
    if (headSingly == NULL){
        cout << "Circle is empty!" << endl;
        return;
    }
    node *temp = headSingly;
    node *previous = NULL;
    do{
        if (temp->data == value){
            break;
        }
        previous = temp;
        temp = temp->next;

    } while (temp != headSingly);
    if (temp->data != value){
        cout << "Student not found!" << endl;
        return;
    }
    if (temp == headSingly && temp->next == headSingly){
        headSingly = NULL;
        delete temp;
        return;
    }
    if (temp == headSingly)
    {
        node *last = headSingly;
        while (last->next != headSingly){
            last = last->next;
        }
        headSingly = headSingly->next;
        last->next = headSingly;
        delete temp;
        return;
    }
    previous->next = temp->next;
    delete temp;
}
void displaySingly(){
    if (headSingly == NULL){
        cout << "Circle is empty!" << endl;
        return;
    }
    node *temp = headSingly;
    do{
        cout << temp->data;
        temp = temp->next;
        if (temp != headSingly){
            cout << " -> ";
        }
    } while (temp != headSingly);
    cout << " -> (back to first)" << endl;
}
void insertEndDoubly(int value){
    node *newnode = new node();
    newnode->data = value;
    if (headDoubly == NULL){
        headDoubly = newnode;
        newnode->next = headDoubly;
        newnode->prev = headDoubly;
        return;
    }
    node *temp = headDoubly;
    while (temp->next != headDoubly){
        temp = temp->next;
    }
    newnode->next = headDoubly;
    newnode->prev = temp;
    temp->next = newnode;
    headDoubly->prev = newnode;
}
void insertPositionDoubly(int value, int position){
    if (position <= 0){
        cout << "Invalid position!" << endl;
        return;
    }
    if (headDoubly == NULL){
        if (position == 1){
            insertEndDoubly(value);
        }else{
            cout << "Invalid position!" << endl;
        }
        return;
    }
    if (position == 1)
    {
        node *newnode = new node();
        newnode->data = value;
        node *temp = headDoubly;
        while (temp->next != headDoubly){
            temp = temp->next;
        }
        newnode->next = headDoubly;
        newnode->prev = temp;
        temp->next = newnode;
        headDoubly->prev = newnode;
        headDoubly = newnode;
        return;
    }
    node *temp = headDoubly;
    for (int i = 1; i < position - 1; i++){
        temp = temp->next;
        if (temp == headDoubly){
            cout << "Invalid position!" << endl;
            return;
        }
    }
    node *newnode = new node();
    newnode->data = value;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}
void deleteDoubly(int value){
    if (headDoubly == NULL){
        cout << "Circle is empty!" << endl;
        return;
    }
    node *temp = headDoubly;
    do{
        if (temp->data == value){
            break;
        }
        temp = temp->next;
    } while (temp != headDoubly);
    if (temp->data != value){
        cout << "Student not found!" << endl;
        return;
    }
    if (temp->next == temp){
        headDoubly = NULL;
        delete temp;
        return;
    }
    if (temp == headDoubly){
        headDoubly = headDoubly->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
void displayDoubly(){
    if (headDoubly == NULL){
        cout << "Circle is empty!" << endl;
        return;
    }
    node *temp = headDoubly;
    do{
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != headDoubly);
    cout << "(back to first)" << endl;
}
int main(){
    int listChoice;
    int choice;
    int value;
    int position;
    while (true)
    {
        cout << "\n====================================CIRCULAR LINKED LIST==================================" << endl;
        cout << "1. Singly Circular Linked List" << endl;
        cout << "2. Doubly Circular Linked List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> listChoice;
        if (listChoice == 1){
            while (true){
                cout << "\n----- SINGLY CIRCULAR LINKED LIST -----" << endl;
                cout << "1. Insert at front" << endl;
                cout << "2. Insert at end" << endl;
                cout << "3. Insert at position" << endl;
                cout << "4. Delete student" << endl;
                cout << "5. Display circle" << endl;
                cout << "6. Back to main menu" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                if (choice == 1){
                    cout << "Enter student number: ";
                    cin >> value;
                    insertFrontSingly(value);
                    cout << "Circle after insertion: ";
                    displaySingly();
                }
                else if (choice == 2){
                    cout << "Enter student number: ";
                    cin >> value;
                    insertEndSingly(value);
                    cout << "Circle after insertion: ";
                    displaySingly();
                }
                else if (choice == 3){
                    cout << "Enter student number: ";
                    cin >> value;
                    cout << "Enter position: ";
                    cin >> position;
                    insertPositionSingly(value, position);
                    cout << "Circle after insertion: ";
                    displaySingly();
                }
                else if (choice == 4){
                    cout << "Enter student number to delete: ";
                    cin >> value;
                    deleteSingly(value);
                    cout << "Circle after deletion: ";
                    displaySingly();
                }else if (choice == 5){
                    cout << "Current circle: ";
                    displaySingly();
                }
                else if (choice == 6){
                    break;
                }
                else{
                    cout << "Invalid choice!" << endl;
                }
            }
        }else if (listChoice == 2){
            while (true){
                cout << "\n----- DOUBLY CIRCULAR -----" << endl;
                cout << "1. Insert at end" << endl;
                cout << "2. Insert at position" << endl;
                cout << "3. Delete student" << endl;
                cout << "4. Display circle" << endl;
                cout << "5. Back to main menu" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                if (choice == 1){
                    cout << "Enter student number: ";
                    cin >> value;
                    insertEndDoubly(value);
                    cout << "Circle after insertion: ";
                    displayDoubly();
                }
                else if (choice == 2){
                    cout << "Enter student number: ";
                    cin >> value;
                    cout << "Enter position: ";
                    cin >> position;
                    insertPositionDoubly(value, position);
                    cout << "Circle after insertion: ";
                    displayDoubly();
                }
                else if (choice == 3){
                    cout << "Enter student number to delete: ";
                    cin >> value;
                    deleteDoubly(value);
                    cout << "Circle after deletion: ";
                    displayDoubly();
                }else if (choice == 4){
                    cout << "Current circle: ";
                    displayDoubly();
                }
                else if (choice == 5){
                    break;
                }else{
                    cout << "Invalid choice!" << endl;
                }
            }
        }else if (listChoice == 3){
            cout << "Program ended." << endl;
            break;
        }else{
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}