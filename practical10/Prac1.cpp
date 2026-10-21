#include <iostream>
using namespace std;

int parking[10];

void initialize()
{
    for (int i = 0; i < 10; i++)
    {
        parking[i] = -1;
    }
}

void parkVehicle(int registration)
{
    int index = registration % 10;

    while (parking[index] != -1)
    {
        index = (index + 1) % 10;
    }

    parking[index] = registration;

    cout << "Vehicle " << registration
         << " parked at slot " << index << endl;
}

void display()
{
    cout << "\nFinal Parking Lot:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "Slot " << i << ": ";

        if (parking[i] == -1)
            cout << "Empty";
        else
            cout << parking[i];

        cout << endl;
    }
}

int main()
{
    initialize();

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int registration;

        cout << "Enter registration number: ";
        cin >> registration;

        parkVehicle(registration);
    }

    display();

    return 0;
}