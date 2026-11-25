#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index = key % SIZE;

        if (table[index] == -1) {
            table[index] = key;
        }
        else {
            int i = (index + 1) % SIZE;

            while (i != index && table[i] != -1)
                i = (i + 1) % SIZE;

            if (i == index) {
                cout << "Hash Table is Full!" << endl;
                return;
            }

            table[i] = key;
        }
    }

    void display() {
        cout << "\nHash Table:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int n, key;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys:\n";

    for (int i = 0; i < n; i++) {
        cin >> key;
        ht.insert(key);
    }

    ht.display();

    return 0;
}
