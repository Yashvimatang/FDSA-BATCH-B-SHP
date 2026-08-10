#include<iostream>
using namespace std;
int recursiveSearch(int books[], int low, int high, int target){
    if(low > high){
        return -1;
    }
    int mid = (low + high) / 2;
    if(books[mid] == target){
        return mid;
    }else if(target < books[mid]) {
        return recursiveSearch(books, low, mid - 1, target);
    }else{
        return recursiveSearch(books, mid + 1, high, target);
    }
}
int main(){
    int n;
    cout<<"Enter number of book:";
    cin>>n;
    int books[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<":";
        cin>>books[i];
        cout<<endl;
    }
    cout<<"The entered elements are:"<<endl;
    for(int i=0;i<n;i++){
     cout<< books[i];
    }
    cout<<endl;
    int target;
    cout<<"Enter the target code: ";
    cin>>target;
    int choice;
    cout<<"Select searching method"<<endl;
    cout<<"1.Iterative binary search"<<endl;
    cout<<"2.Recursive binary search"<<endl;
    cout<<"Enter choice(1 or 2):"<<endl;
    cin>>choice;
    int position = -1;
    if(choice== 1){
        int low =0;
        int high = n-1;
        while(low<=high){
             int mid = (low+high)/2;
                if(books[mid]== target){
                    position = mid;
                    break;
                }else if(mid< target){
                   low = mid + 1;

                }else{
                   high = mid - 1;
                }
        }
    }else if(choice == 2){
      position = recursiveSearch(books, 0, n - 1, target);
    }else{
        cout<<"Enter a valid choice";
    }
     if(position != -1)
    {
        cout<<"Book found at position:"<<position + 1<<endl;
    }
    else
    {
        cout<<"Book not found"<<endl;
    }
    return 0;
}