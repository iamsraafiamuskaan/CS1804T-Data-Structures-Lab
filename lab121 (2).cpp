#include <iostream>
using namespace std;

#define MAX 100

class GraphMatrix{
    int adj[MAX][MAX];
    int vertices;

public:
    GraphMatrix(int v){
        vertices = v;
        for(int i=0;i<vertices;i++)
            for(int j = 0; j<vertices;j++)
                adj[i][j] = 0;
    }

    void insertEdge(int u, int v){
        if (u>= vertices || v >= vertices || u< 0 || v< 0){
            cout << "Invalid vertex!\n";
            return;
        }
        adj[u][v]=1;
        adj[v][u]=1;
    }

    void delEdge(int u, int v){
        if (u>= vertices || v >= vertices || u< 0 || v< 0){
            cout << "Invalid vertex!\n";
            return;
        }
        adj[u][v]=0;
        adj[v][u]=0;
    }

    void search(int u, int v){
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            cout << "Invalid vertex!\n";
            return;
        }
        if (adj[u][v])
            cout<< "Edge exists.";
        else
            cout << "Edge does not exist.";
    }

    void display(){
        for(int i=0;i<vertices;i++){
            for(int j = 0; j<vertices;j++){
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    int v,choice, u,w;
    cout << "Enter number of vertices:";
    cin >> v;

    GraphMatrix g(v);

    do{
        cout << "1.INSERT:\n";
        cout << "2.DELETE:\n";
        cout << "3.SEARCH:\n";
        cout << "4.DISPLAY:\n";
        cout << "5.EXIT\n";
        cout << "Enter the choice:\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter edge(u v):\n";
                cin >> u >> w;
                g.insertEdge(u,w);
                break;
            case 2:
                cout << "Enter key to remove:\n";
                cin >> u >> w;
                g.delEdge(u,w);
                break;
            case 3:
                cout << "Enter key to search:\n";
                cin >> u >> w;
                g.search(u,w);
                break;
            case 4:
                g.display();
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }while (choice!= 5);
    return 0;
}