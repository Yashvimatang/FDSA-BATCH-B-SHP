#include<iostream>
using namespace std;
int main(){
    string s;
    string w = "";
    string l = "";
    cout<<"Enter a sentence:";
    getline(cin,s);
    cout<<s<<endl;
    s=s+" ";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
          w+=s[i];
        }else{
            if(w.length()> l.length()){
                l=w;
            }
            w = "";
        }
    }
    cout<<"Longest word:"<<l<<endl;
    cout<<"Length: "<<l.length()<<endl;
    return 0;
}
