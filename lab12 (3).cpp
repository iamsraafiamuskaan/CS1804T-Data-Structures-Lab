#include <iostream>
#include <cstdlib>

class Node {
public:
    Node* next;
    int vertex;
};

class GraphList {
public:
    int vertices;
    Node** adjList;

    GraphList(int v) {
        vertices = v;
        adjList = (Node**)malloc(vertices * sizeof(Node*));
        for (int i = 0; i < vertices; i++) {
            adjList[i] = NULL;
        }
    }

    void insert(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            printf("Invalid vertices\n");
            return;
        }
        Node* newnode1 = (Node*)malloc(sizeof(Node));
        newnode1->vertex = v;
        newnode1->next = adjList[u];
        adjList[u] = newnode1;

        Node* newnode2 = (Node*)malloc(sizeof(Node));
        newnode2->vertex = u;
        newnode2->next = adjList[v];
        adjList[v] = newnode2;

        printf("Successfully Inserted Edge between %d and %d\n", u, v);
    }

    void display() {
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d", i);
            Node* curr = adjList[i];
            while (curr != NULL) {
                printf(" -> %d", curr->vertex);
                curr = curr->next;
            }
            printf("\n");
        }
    }

    void search(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            printf("Invalid vertices\n");
            return;
        }

        Node* curr = adjList[u];
        while (curr != NULL) {
            if (curr->vertex == v) {
                printf("Edge exists between %d and %d\n", u, v);
                return;
            }
            curr = curr->next;
        }
        printf("Sorry! There exists no edge between %d and %d\n", u, v);
    }
    void deleteEdge(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            printf("Invalid vertices\n");
            return;
        }

        Node *curr = adjList[u], *prev = NULL;
        while (curr != NULL && curr->vertex != v) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            printf("No edge found between %d and %d\n", u, v);
        } else {
            if (prev == NULL) {
                adjList[u] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Edge between %d and %d deleted\n", u, v);
        }

        curr = adjList[v];
        prev = NULL;
        while (curr != NULL && curr->vertex != u) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            printf("No edge found between %d and %d\n", v, u);
        } else {
            if (prev == NULL) {
                adjList[v] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Edge between %d and %d deleted\n", v, u);
        }
    }
};

int main() {
    int v, choice, u, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    GraphList g(v);

    while (1) {
        printf("\nTHE MENU:\n1. INSERT\n2. DISPLAY\n3. SEARCH\n4. DELETE\n5. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter vertices u and v: ");
                scanf("%d%d", &u, &w);
                g.insert(u, w);
                break;
            case 2:
                printf("\nDisplaying Graph:\n");
                g.display();
                break;
            case 3:
                printf("Enter vertices u and v to search: ");
                scanf("%d%d", &u, &w);
                g.search(u, w);
                break;
            case 4:
                printf("Enter vertices u and v to delete the edge: ");
                scanf("%d%d", &u, &w);
                g.deleteEdge(u, w);
                break;
            case 5:
                printf("\nExiting the program !!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
