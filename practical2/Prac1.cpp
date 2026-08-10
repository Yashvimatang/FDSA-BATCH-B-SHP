#include <iostream>
using namespace std;
int Serachingbyhelper(string plate[], int n, string target, int index){
    if(index == n)
        return -1;
    if(plate[index] == target)
        return index;
    return Serachingbyhelper(plate, n, target, index + 1);
}
int main(){
    int n;
    cout<<"Enter number of plates: ";
    cin>>n;
    string plates[n];
    for(int i = 0; i < n; i++) {
        cout<<"Enter plate " << i + 1 << ": ";
        cin>>plates[i];
    }
    cout<<endl;
    string target;
    cout<<"Enter the target plate: ";
    cin>>target;
    int choice;
    cout<<endl;
    cout<<"Who will search?" << endl;
    cout<<"1. Security Guard (Iterative)" << endl;
    cout<<"2. Helper (Recursive)" << endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice == 1){
        int position = -1;
        for(int i = 0; i < n; i++){
            if(plates[i] == target){
                position = i;
                break;
            }
        }
        if(position != -1){
            cout<<"Plate found at position: "<<position + 1;
        }
        else{
            cout<<"Plate not found";
        }
    }
    else if(choice == 2){
        int position = Serachingbyhelper(plates, n, target, 0);
        if(position != -1) {
            cout<<"Plate found at position: " << position + 1;
        }
        else{
            cout<<"Plate not found";
        }
    }
    else
    {
        cout<<"Invalid choice";
    }

    return 0;
}