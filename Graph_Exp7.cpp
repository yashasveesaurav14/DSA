#include <iostream>
using namespace std;

class Graph
{
    int adj[20][20];
    int n;

public:
    Graph()
    {
        n = 0;

        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        if (n <= 0 || n > 20)
        {
            cout << "Invalid number of vertices!\n";
            n = 0;
            return;
        }

        int edges;
        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            if (u >= 0 && u < n && v >= 0 && v < n)
            {
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
            else
            {
                cout << "Invalid edge! Enter vertices between 0 and "
                     << n - 1 << ".\n";
                i--;
            }
        }
    }

    void displayMatrix()
    {
        if (n == 0)
        {
            cout << "\nGraph is not created yet.\n";
            return;
        }

        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start)
    {
        if (n == 0)
        {
            cout << "\nGraph is not created yet.\n";
            return;
        }

        if (start < 0 || start >= n)
        {
            cout << "\nInvalid starting vertex!\n";
            return;
        }

        bool visited[20] = {false};

        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

private:
    void DFSUtil(int vertex, bool visited[])
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[vertex][i] == 1 && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }
};

int main()
{
    Graph g;
    int choice, start;

    do
    {
        cout << "\n===== Graph Menu =====";
        cout << "\n1. Create a Graph";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. DFS Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayMatrix();
            break;

        case 3:
            cout << "\nEnter starting vertex: ";
            cin >> start;
            g.DFS(start);
            break;

        case 4:
            cout << "\nProgram Exited.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
