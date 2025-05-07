#include <iostream>
using namespace std;

class Graph {
    int **AM, num;
    string *data;

public:
    Graph(int n) {
        num = n;
        AM = new int *[n];
        for (int i = 0; i < n; i++)
            AM[i] = new int[n];
        data = new string[n];

        cout << "Enter names of all cities:\n";
        for (int i = 0; i < n; i++) {
            cout << "City " << i + 1 << ": ";
            cin >> data[i];
        }

        cout << "\nEnter the cost to connect cities. Enter 0 if no direct connection.\n";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    AM[i][j] = 0; // No self-loops
                } else {
                    cout << "Cost to connect " << data[i] << " to " << data[j] << ": ";
                    cin >> AM[i][j];
                    AM[j][i] = AM[i][j]; // Symmetric for undirected graph
                }
            }
        }

        // Replace 0 with a large number for non-connections (except diagonal)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (AM[i][j] == 0 && i != j)
                    AM[i][j] = 999999; // Large value to represent no connection
    }

    void prims() {
        cout << "\nMinimum Spanning Tree using Prim's Algorithm:\n";
        int *visited = new int[num]();
        int *distance = new int[num];
        int *from = new int[num]();
        int cost = 0;

        visited[0] = 1;
        for (int i = 0; i < num; i++)
            distance[i] = AM[0][i];

        for (int count = num - 1; count > 0; count--) {
            int min = 999999, v = -1;

            for (int j = 1; j < num; j++) {
                if (!visited[j] && distance[j] < min) {
                    min = distance[j];
                    v = j;
                }
            }

            if (v == -1) break;

            int u = from[v];
            cout << data[u] << " ==> " << data[v] << "  (cost: " << AM[u][v] << ")\n";
            cost += AM[u][v];
            visited[v] = 1;

            for (int j = 0; j < num; j++) {
                if (!visited[j] && AM[v][j] < distance[j]) {
                    distance[j] = AM[v][j];
                    from[j] = v;
                }
            }
        }

        cout << "Total Cost of MST: " << cost << endl;

        delete[] visited;
        delete[] distance;
        delete[] from;
    }
};

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    Graph gr(n);

    int choice;
    do {
        cout << "\nMENU:\n";
        cout << "1. Find Minimum Spanning Tree (Prim's Algorithm)\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                gr.prims();
                break;
            case 2:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);
}