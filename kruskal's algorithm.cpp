#include <iostream>
using namespace std;

#define SIZE 20
#define INF 9999

class Graph {
    int n;
    int cost[SIZE][SIZE];
    bool selected[SIZE];

public:
    void createGraph() {
        cout << "Enter number of substations: ";
        cin >> n;

        cout << "Enter adjacency matrix:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cost[i][j];

                if (cost[i][j] == 0)
                    cost[i][j] = INF;
            }
        }
    }

    void prim() {
        for (int i = 0; i < n; i++)
            selected[i] = false;

        selected[0] = true;

        int count = 0;
        int total = 0;

        cout << "\nMinimum Spanning Tree:\n";

        while (count < n - 1) {
            int min = INF;
            int x = -1;
            int y = -1;

            for (int i = 0; i < n; i++) {
                if (selected[i]) {
                    for (int j = 0; j < n; j++) {
                        if (!selected[j] && cost[i][j] < min) {
                            min = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

            if (x != -1 && y != -1) {
                cout << x << " -- "
                     << y << " = "
                     << min << endl;

                selected[y] = true;
                total += min;
                count++;
            }
        }

        cout << "Minimum Wiring Cost = " << total << endl;
    }
};

int main() {
    Graph g;

    g.createGraph();
    g.prim();

    return 0;
}

