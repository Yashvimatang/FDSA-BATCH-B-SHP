#include <iostream>
using namespace std;
int graph[100][100];
int n;
void DFS(int start){
    int stack[100];
    int top = -1;
    bool visited[100] = {false};
    top++;
    stack[top] = start;
    cout<<"DFS Traversal: ";
    while (top != -1){
        int current = stack[top];
        top--;
        if (visited[current] == false){
            visited[current] = true;
            cout << current << " ";
            for (int i = n - 1; i >= 0; i--){
                if (graph[current][i] == 1 && visited[i] == false){
                    top++;
                    stack[top] = i;
                }
            }
        }
    }
cout<<endl;
}

void BFS(int start){
    int queue[100];
    int front = 0;
    int rear = -1;
    bool visited[100] = {false};
    rear++;
    queue[rear] = start;
    visited[start] = true;
    cout<<"BFS Traversal: ";

    while (front <= rear){
        int current = queue[front];
        front++;
        cout<<current<<" ";
        for (int i = 0; i < n; i++){
            if (graph[current][i] == 1 && visited[i] == false){
                visited[i] = true;
                rear++;
                queue[rear] = i;
            }
        }
    }
    cout<<endl;
}
int main(){
    int edges;
    int start;
    cout<<"Enter number of buildings: ";
    cin>>n;
    cout<<"Enter number of roads: ";
    cin>>edges;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            graph[i][j] = 0;
        }
    }
    cout << "Enter the roads:" << endl;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout << "Enter starting building: ";
    cin >> start;
    DFS(start);
    BFS(start);
    return 0;
}