#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <stack>
using namespace std;

class ExpressionTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;
    };
    Node* root;

public:
    ExpressionTree() { 
        root = nullptr; 
    }

    Node* createNode(char value) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void constructFromPostfix(const char* postfix) {
        stack<Node*> st;
        for (int i = 0; postfix[i] != '\0'; i++) {
            if (isalnum(postfix[i])) { 
                st.push(createNode(postfix[i]));
            } else { 
                Node* newNode = createNode(postfix[i]);
                newNode->right = st.top(); st.pop();
                newNode->left = st.top(); st.pop();
                st.push(newNode);
            }
        }
        root = st.top();
    }

    void inorder_traversal(Node* node) {
        if (node == nullptr) return;
        inorder_traversal(node->left);
        printf("%c ", node->data);
        inorder_traversal(node->right);
    }

    void inorder() {
        inorder_traversal(root);
        printf("\n");
    }

    void preorder_traversal(Node* node) {
        if (node == nullptr) return;
        printf("%c ", node->data);
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }

    void preorder() {
        preorder_traversal(root);
        printf("\n");
    }

    void postorder_traversal(Node* node) {
        if (node == nullptr) return;
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        printf("%c ", node->data);
    }

    void postorder() {
        postorder_traversal(root);
        printf("\n");
    }
};

int main() {
    ExpressionTree T;
    int choice;
    char postfix[100];

    while (true) {
        printf("\n------- MENU -------\n");
        printf("1. Enter Postfix Expression\n");
        printf("2. Construct Expression Tree\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a valid postfix expression: ");
                scanf("%s", postfix);
                break;
            case 2:
                T.constructFromPostfix(postfix);
                printf("Expression tree constructed.\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                T.preorder();
                break;
            case 4:
                printf("Inorder Traversal: ");
                T.inorder();
                break;
            case 5:
                printf("Postorder Traversal: ");
                T.postorder();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}