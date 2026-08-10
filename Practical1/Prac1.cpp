#include <iostream>
// #include>string>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter string " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "\nYou entered:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int h;
    cout << endl;
    cout << "Enter hours:" << endl;
    cin  >> h;
    h = h % n;
    for(int k=0 ;k <h ;k++){
        string first = arr[0];
        for(int i = 0;i < n-1 ;i++){
            arr[i] =arr[i+1];
        }
        arr[n-1] = first;
    }
    cout<<"After "<<h<<" hours, the strings are:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
