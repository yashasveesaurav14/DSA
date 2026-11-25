#include <iostream>
using namespace std;

#define SIZE 10

class ParkingSystem {
    int parking[SIZE];

public:
    ParkingSystem() {
        for (int i = 0; i < SIZE; i++)
            parking[i] = -1;
    }

    void parkVehicle(int vehicleNo) {
        int index = vehicleNo % SIZE;

        if (parking[index] == -1) {
            parking[index] = vehicleNo;

            cout << "Vehicle " << vehicleNo
                 << " parked at slot "
                 << index << endl;
        }
        else {
            int i = (index + 1) % SIZE;

            while (i != index && parking[i] != -1)
                i = (i + 1) % SIZE;

            if (i == index) {
                cout << "Parking is Full!" << endl;
                return;
            }

            parking[i] = vehicleNo;

            cout << "Vehicle " << vehicleNo
                 << " parked at slot "
                 << i << endl;
        }
    }

    void display() {
        cout << "\nParking Slots:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";

            if (parking[i] == -1)
                cout << "Empty";
            else
                cout << parking[i];

            cout << endl;
        }
    }
};

int main() {
    ParkingSystem ps;
    int n, vehicleNo;

    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter vehicle numbers:\n";

    for (int i = 0; i < n; i++) {
        cin >> vehicleNo;
        ps.parkVehicle(vehicleNo);
    }

    ps.display();

    return 0;
}
