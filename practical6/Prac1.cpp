#include<iostream>
using namespace std;
int n;
int top = -1;
int stack[100];
void push(int value){
   if(top == n-1){
   cout<<"Stack overflows!";
   return ;
   }
   top++;
   stack[top] = value;
   cout<<"Current top tray in the stack is:"<<stack[top]<<endl;
}
void pop(){
  int deletevalue;
  if(top == -1){
    cout<<"Stack is underflow!!";
    return;
  }else{
    deletevalue = stack[top];
    top--;
    cout<<"Taken tray is:"<<deletevalue<<endl;
  }
}
void peek(){
 if(top == -1){
  cout<<"Stack is underflow!!";
    return;
 }else{
   cout<<"Current top tray in the stack is:"<<stack[top]<<endl;
 }
}
void display(){
   if(top == -1){
  cout<<"Stack is underflow!!";
    return;
 }else{
  cout<<"Tray in the stack are as followed:";
  for(int i=top;i>=0;i--){
    cout<<stack[i]<<" ";
  }
  cout<<endl;
 }    
}
int main(){
    cout<<"Enter tray capacity:";
    cin>>n;
    int c;
    int traynum;
    while (true)
    {   
        cout<<endl;
        cout<<"1.Place tray(push)"<<endl;
        cout<<"2.Remove tray(pop)"<<endl;
        cout<<"3.Display first tray(peek)"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter choice:";
        cin>>c;
        if(c==1){
          cout<<"Enter tray number:";
          cin>>traynum;
          if(top == n-1){
            cout<<"The tray stack is full";
          }else{
            push(traynum);
          }
        }else if(c==2){
          if(top == -1){
            cout<<"Tray stack is empty!";
          }else{
            pop();
            if(top == -1){
                cout<<"Tray stack is empty now.";
            }else{
                cout<<"Current top tray is:"<<stack[top];
            }
          }
        }else if(c==3){
          if(top == -1){
            cout<<"Tray stack is empty!";
          }else{
            peek();
          }
        }else if(c==4){
          if(top == -1){
            cout<<"Tray stack is empty!";
          }else{
            display();
          }
        }else if(c==5){
          cout<<"Thanks for visting our cafeteria";
            break;
        }
    }
    return 0;
}
