#include "bst.h"
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    Node* root;
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

public:
    ExpressionTree() : root(nullptr) {}
    
    void constructFromPostfix(const char* postfix) {
        stack<Node*> st;
        for (int i = 0; i < strlen(postfix); i++) {
            char c = postfix[i];
            Node* newNode = new Node(c);
            if (isOperator(c)) {
                if (st.size() < 2) {
                    printf("Invalid postfix expression!\n");
                    return;
                }
                newNode->right = st.top(); st.pop();
                newNode->left = st.top(); st.pop();
            }
            st.push(newNode);
        }
        if (st.size() != 1) {
            printf("Invalid postfix expression!\n");
            return;
        }
        root = st.top();
    }
    
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            printf("%c ", node->data);
            inorder(node->right);
        }
    }
    
    void preorder(Node* node) {
        if (node) {
            printf("%c ", node->data);
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            printf("%c ", node->data);
        }
    }
    
    void printInorder() { printf("Inorder: "); inorder(root); printf("\n"); }
    void printPreorder() { printf("Preorder: "); preorder(root); printf("\n"); }
    void printPostorder() { printf("Postorder: "); postorder(root); printf("\n"); }
};

int main() {
    ExpressionTree tree;
    char postfix[100];
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Enter Postfix Expression\n");
        printf("2. Construct Expression Tree\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                break;
            case 2:
                tree.constructFromPostfix(postfix);
                printf("Expression tree constructed.\n");
                break;
            case 3:
                printf("Inorder traversal of expression tree: ");
                tree.printInorder();
                break;
            case 4:
                printf("Preorder traversal of expression tree: ");
                tree.printPreorder();
                break;
            case 5:
                printf("Postorder traversal of expression tree: ");
                tree.printPostorder();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
