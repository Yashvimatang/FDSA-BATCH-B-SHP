#include<iostream>
using namespace std;
char stack[100];
int top = -1;
int resultStack[100];
int resultTop = -1;
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
void pushResult(int value){
    resultTop++;
    resultStack[resultTop] = value;
}
int popResult(){
    int value = resultStack[resultTop];
    resultTop--;
    return value;
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
    cout<<"Postfix expression : "<<postfix<<endl;
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];
        if (ch == ' '){
            continue;
        }
        if (ch >= '0' && ch <= '9'){
            int number = ch - '0';
            pushResult(number);
        }
        else if (isoperator(ch)){
            int b = popResult();
            int a = popResult();
            int result;
            if (ch == '+'){
                result = a + b;
            }
            else if (ch == '-'){
                result = a - b;
            }
            else if (ch == '*'){
                result = a * b;
            }
            else{
                result = a / b;
            }
            pushResult(result);
        }
    }
    cout<<"Result : "<<popResult()<<endl;
    return 0;
}