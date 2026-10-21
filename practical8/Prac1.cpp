#include <iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *createNode(int value){
    node *n = new node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inorder(node *root){
    if (root == NULL){ return; }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root){
    if (root == NULL){ return; }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if (root == NULL) {return; }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelorder(node *root){
    if (root == NULL){ return; }
    node *queue[100];
    int front = 0;
    int rear = 0;
    queue[rear] = root;
    while (front <= rear){
        node *current = queue[front];
        front++;
        cout<<current->data << " ";
        if (current->left != NULL){
            rear++;
            queue[rear] = current->left;
        }
        if (current->right != NULL){
            rear++;
            queue[rear] = current->right;
        }
    }
}
int main(){
    node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout << "Preorder: ";
    preorder(root);
    cout<<endl;
    cout << "Postorder: ";
    postorder(root);
    cout<<endl;
    cout << "Level Order: ";
    levelorder(root);
    cout<<endl;
    return 0 ;
}