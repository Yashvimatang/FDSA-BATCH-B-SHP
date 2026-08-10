#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of books: ";
    cin >> n;
    int books[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter Book ID " << i + 1 << ": ";
        cin>>books[i];
    }
    cout<<endl;
    cout<<"Books borrowed more than once are:";
    cout<<endl;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(books[i] == books[j]){
                count++;
            }
        }
        int printed = 0;
        for(int k = 0; k < i; k++){
            if(books[i] == books[k]){
                printed = 1;
                break;
            }
        }
        if(count > 1 && printed == 0){
            cout << books[i] << " ";
        }
    }

    return 0;
}