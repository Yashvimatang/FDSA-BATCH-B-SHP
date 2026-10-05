#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* front = NULL;
node* rear = NULL;
void enqueue(int p){
    node* n = new node();
    n->data = p;
    n->next = NULL;
    if(rear == NULL){ //saje linked list khale aaye tj he use thiye 
        front=rear=n;
        rear->next= front;
    }
    else{
        rear->next = n;
        rear=n;
        rear->next=front;
    }
}
void dequeue(){
    node* temp = front;
    if(front == NULL){
        cout<<"There is no patient yet!";
    }
    else if(front == rear){ // jade single patient aayo ve 
        front = rear = NULL;
        delete temp;
    } 
    else{
        front = front->next;
        rear->next = front;
        delete temp;
    }
}
void peek(){
if(front==NULL){
    cout<<"There is no patient yet!";
}
else{
    cout<<"Current patient to be attended :"<<front->data;
}
}
void display(){
if(front==NULL){
    cout<<"There is no patient yet!";
}
node* temp = front;
do{
    cout<< temp->data <<" <- ";
    temp=temp->next;
}while(temp != front);
cout<<"(back to front)"<<endl;
}
int main(){
    int choice;
    int patient;

    while(true){
        cout<<endl;
        cout<<"1. Add patient"<<endl; //enqueue
        cout<<"2. Attend patient"<<endl; //dequeue
        cout<<"3. Current patient"<<endl;
        cout<<"4. Display all patients"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == 1){
    cout<<"Enter patient number: ";
    cin>>patient;
    enqueue(patient);
    }
    else if(choice == 2){
    dequeue();
    cout<<endl;
    peek();
    }
    else if(choice == 3){
    peek();
    cout<<endl;
    }
    else if(choice == 4){
    display();
    cout<<endl;
    }
    else if(choice == 5){
    cout<<"Thank you for visiting our hostipal !";
    break;
    }
    else{
    cout<<"Please enter a valid choice!";
    }
}
    return 0;
}