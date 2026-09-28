#include<iostream>
using namespace std;
char stack[100];
int top = -1;
void push(char ch){
    top++;
    stack[top] = ch;
}
char pop(){
    char ch = stack[top];
    top--;
    return ch;
}
bool isoperator(char ch){
       if(ch == '+'|| ch =='-' || ch == '*' || ch == '/'){
        return true;
    
    }else{
        return false;
    } 
}
int precedence(char ch){
     if(ch == '+' || ch == '-'){
        return 1;
    }if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}
int main(){
    string infix;
    string postfix = "";
    cout<<"Enter infix arithmetic expression:";
    cin>>infix;
    for(int i=0;i<infix.length();i++){
        char ch = infix[i];
        if((ch>='0' && ch<='9')|| (ch>='a' && ch<='z') ||(ch>='A' && ch<='Z')){
            postfix += ch;
            postfix = postfix + " ";
        }
        if(ch == '('){
            push(ch);
        }else if (ch ==')'){
            while(top != -1 && stack[top] != '('){
                postfix+= pop();
                 postfix = postfix + " ";
                if(top != -1){
                    pop();
                }
            }
        }else if(isoperator(ch)){
            while(top != -1 && stack[top]!= '(' &&  precedence(stack[top]) >= precedence(ch)){
                postfix += pop();
                 postfix = postfix + " ";
            }
            push(ch);
        }
    }
    while (top != -1){
        postfix += pop();
         postfix = postfix + " ";
    }
    cout<<"Infix expression : "<<infix<<endl;
    cout<<"Postfix expression : "<<postfix;
    return 0;
}