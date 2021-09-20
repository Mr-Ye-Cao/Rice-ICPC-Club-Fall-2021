/* Program to implement Binary Search Tree in c++ using classes  */
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
    private:
        struct Node* root;
    public:
        BinaryTree() {
            root = NULL;
        }
        Node* createNode(int);
        Node* insertNode(Node*, int);
        Node* deleteNode(Node*, int);
        void inOrder(Node*);
        void preOrder(Node*);
        void postOrder(Node*);
        Node* findMinimum(Node*);

        Node* getRoot() {
            return root;
        }

        void setRoot(Node* ptr) {
            root = ptr; 
        }
};

Node* BinaryTree :: createNode(int n) {
    Node* newNode = new struct Node();
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}


Node* BinaryTree :: findMinimum(Node* rootPtr) {
    while(rootPtr->left != NULL) {
        rootPtr = rootPtr->left;
    }
    return rootPtr;
}


Node* BinaryTree :: insertNode(Node* rootPtr, int n) {
    if(rootPtr == NULL) {
        return createNode(n);
    }
    if(n < rootPtr->data) {
        rootPtr->left = insertNode(rootPtr->left, n);
    }
    if(n > rootPtr->data) {
        rootPtr->right = insertNode(rootPtr->right, n);
    }
    return rootPtr;
}


Node* BinaryTree :: deleteNode(Node* rootPtr, int n) {
    if(rootPtr == NULL) {
        cout<<"Node to be deleted is not present.!"<<endl;
        return rootPtr;
    }
    else if(n < rootPtr->data) {
        rootPtr->left = deleteNode(rootPtr->left, n);
    } else if(n > rootPtr->data) {
        rootPtr->right = deleteNode(rootPtr->right, n);
    } else {
        if(rootPtr->left == NULL && rootPtr->right == NULL) {
            delete rootPtr;
            rootPtr = NULL;
        }
        else if(root->left == NULL) {
            struct Node* temp = rootPtr;
            rootPtr = rootPtr->right;
            delete temp;
        }
        else if(rootPtr->right == NULL) {
            struct Node* temp = rootPtr;
            rootPtr = rootPtr->left;
            delete temp;
        } else {
            Node* temp = findMinimum(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->left = deleteNode(rootPtr->right, temp->data);
        }
    }

    return rootPtr;
}


void BinaryTree :: inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<"\t";
    inOrder(root->right);
}

void BinaryTree :: preOrder(Node* root) {
    if(root == NULL) return;
    cout<<root->data<<"\t";
    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree :: postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"\t";
}

int main() {
    BinaryTree l1;
    int ch, ele, res;
    Node* ptr;
    do {
            cout<<"1 - Insert Node\n";
            cout<<"2 - IN-ORDER Traversal\n";
            cout<<"3 - PRE-ORDER Traversal\n";
            cout<<"4 - POST-ORDER Traversal\n";
            cout<<"Enter choice\n";
            cin>>ch;
            switch(ch) {
                case 1: 
                    cout<<"Entre element to insert to the List\n";
                    cin>>ele;

                    ptr = l1.insertNode(l1.getRoot(), ele);
  
                    l1.setRoot(ptr);
                    break;
                case 2:
                    cout<<"---IN-ORDER TRAVERSAL---"<<endl;
                    l1.inOrder(l1.getRoot());
                    cout<<endl;
                    break;
                case 3:
                    cout<<"---PRE-ORDER TRAVERSAL---"<<endl;
                    l1.preOrder(l1.getRoot());
                    cout<<endl;
                    break;
                case 4:
                    cout<<"---POST-ORDER TRAVERSAL---"<<endl;
                    l1.postOrder(l1.getRoot());
                    cout<<endl;
                    break;
                case 5:
                    cout<<"Enter node to be deleted."<<endl;
                    cin>>ele;
                    ptr = l1.deleteNode(l1.getRoot(), ele);
                    l1.setRoot(ptr);
                default: cout<<"Invalid choice"<<endl;
            }
    } while(ch >=1 && ch <= 5);
    return 0;
}