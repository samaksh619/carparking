#include <bits/stdc++.h>
using namespace std;

class ParkingSystem {
    int capacity;                 // total slots
    vector<int> slots;            // -1 means empty, otherwise car number
    queue<int> waiting;           // waiting queue of car numbers

public:
    ParkingSystem(int cap) {
        capacity = cap;
        slots.assign(capacity, -1);
    }

    void parkCar(int carNo) {
        // Check for empty slot
        for (int i = 0; i < capacity; i++) {
            if (slots[i] == -1) {
                slots[i] = carNo;
                cout << "Car " << carNo << " parked at slot " << i + 1 << ".\n";
                return;
            }
        }
        // No empty slot → add to waiting queue
        waiting.push(carNo);
        cout << "Parking full. Car " << carNo << " added to waiting queue.\n";
    }

    void removeCar(int carNo) {
        // Find the car in slots
        for (int i = 0; i < capacity; i++) {
            if (slots[i] == carNo) {
                cout << "Car " << carNo << " removed from slot " << i + 1 << ".\n";
                slots[i] = -1;

                // If someone is waiting, give them this slot
                if (!waiting.empty()) {
                    int nextCar = waiting.front();
                    waiting.pop();
                    slots[i] = nextCar;
                    cout << "Car " << nextCar << " from waiting queue "
                         << "parked at slot " << i + 1 << ".\n";
                }
                return;
            }
        }
        cout << "Car " << carNo << " not found in parking.\n";
    }

    void displayStatus() {
        cout << "\n--- Parking Slots ---\n";
        for (int i = 0; i < capacity; i++) {
            if (slots[i] == -1)
                cout << "Slot " << i + 1 << ": [Empty]\n";
            else
                cout << "Slot " << i + 1 << ": Car " << slots[i] << "\n";
        }

        cout << "\n--- Waiting Queue ---\n";
        if (waiting.empty()) {
            cout << "No cars in waiting.\n";
        } else {
            queue<int> temp = waiting;
            cout << "Cars waiting: ";
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << "\n";
        }
        cout << "----------------------\n\n";
    }
};

int main() {
    int capacity;
    cout << "Enter parking capacity (number of slots): ";
    cin >> capacity;

    ParkingSystem ps(capacity);

    while (true) {
        cout << "\n1. Park Car\n";
        cout << "2. Remove Car\n";
        cout << "3. Display Status\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int carNo;
            cout << "Enter car number: ";
            cin >> carNo;
            ps.parkCar(carNo);
        } else if (choice == 2) {
            int carNo;
            cout << "Enter car number to remove: ";
            cin >> carNo;
            ps.removeCar(carNo);
        } else if (choice == 3) {
            ps.displayStatus();
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
