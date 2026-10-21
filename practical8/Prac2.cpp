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
node *insert(node *root, int value)
{
    if (root == NULL){
        return createNode(value);
    }
    if (value < root->data){
        root->left = insert(root->left, value);
    }else if (value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(node *root){
    if (root == NULL){ return;}
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    node *root = NULL;
    int n;
    int value;
    cout << "Enter number of books: ";
    cin >> n;
    cout << "Enter book codes:" << endl;
    for (int i = 0; i < n; i++){
        cin >> value;
        root = insert(root, value);
    }
    cout << "Inorder traversal: ";
    inorder(root);
    cout<<endl;
    return 0;
}