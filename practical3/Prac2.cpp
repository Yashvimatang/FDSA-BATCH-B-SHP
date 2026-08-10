#include<iostream>
using namespace std;
int main()
{  
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    int c0=0;
    int c1=0;
    int c2=0;  
    for(int i=0;i<n;i++){
        if(arr[i]== 0) c0++;
        else if (arr[i]==1) c1++;
        else c2++;
    }
    cout<<"Total number of 0's are "<<c0<<endl;
    cout<<"Total number of 1's are "<<c1<<endl;
    cout<<"Total number of 2's are "<<c2<<endl;

     for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    
    cout<<"After sorting all the color codes are:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    return 0;
}