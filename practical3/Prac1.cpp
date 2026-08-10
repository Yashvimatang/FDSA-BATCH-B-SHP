#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of marks(which are wrote on the studnet sheet):";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks " << i + 1 << " :";
        cin >> arr[i];
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    int choice;
    cout << "1.By bubble sort" << endl;
    cout << "2.By selection sort" << endl;
    cout << "3.By insertion sort" << endl;
    cout << "Enter choice:";
    cin >> choice;
    if (choice == 1) {
        cout << endl;
        cout << "The sorting process is done using bubble sort" << endl;

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
        cout << endl;
        cout << "The sorted marks of student sheets(in ascending order) by bubble sort are:";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else if (choice == 2){
        cout << endl;
        cout << "The sorting process is done using selection sort" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        cout << "The sorted marks of student sheets(in ascending order) by selection sort are: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else if (choice == 3){
        cout << endl;
        cout << "The sorting process is done using insertion sort" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
                else
                {
                    break;
                }
            }
        }
        cout << endl;
                cout << "The sorted marks of student sheets(in ascending order) by insertion sort are: " << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
    }
        else
        {
            cout << "Please enter a valid choice(1-3)";
        }
        return 0;
    }