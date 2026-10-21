#include<iostream>
using namespace std;
struct node{
    string data;
    node* next;
};
node* head =   NULL;
struct node* createpage(string page){
    node* newnode = new node();
    if(newnode == NULL){
      cout<<"Memory allocation failed";
      return 0;   
    }
    newnode->data = page;
    newnode->next = NULL;
    return newnode;
}
void push(string page){
     struct node* newnode;
    newnode = createpage(page);
    if(newnode == NULL){
        return;
    }
    newnode->next = head;
    head = newnode;
    cout<<"Current opened page is "<<newnode->data;
}
void pop(){
    node* temp = new node();
    string removedpage;
    if(head == NULL){
        cout<<"Stack is empty";
        return;
    }
    temp = head;
    removedpage = head->data;
    head = head->next;
    delete(temp);
    cout<<"Removed page is "<<removedpage;
    cout<<endl; 
    if (head == NULL) {
        cout<<"No history left."<<endl;
    }
    else {
        cout<<"Current opened page is: "<<head->data<< endl;
    }
}
int main(){
    int choice;
    string page;
    do{
        cout<<endl;
        cout<<"======Browser history========";
        cout<<endl;
        cout<<"1.Visit page"<<endl;//Inshort new page te veya se
        cout<<"2.Back"<<endl; //inshort new page jo vo huj close kare vedha se1
        cout<<"3.Exit"<<endl;
        cout<<"Enter choice:";
        cin>>choice;
       if(choice == 1){
          cout<<"Enter page name: ";
            cin>>page;
            push(page);
       }else if (choice == 2){
          pop();
       }else if (choice == 3){
          cout<<"Browser closed."<<endl;
       }else{
            cout<<"Invalid choice."<<endl;
       }
    }while(choice != 3);
    return 0;
}