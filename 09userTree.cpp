#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int val){
        data = val;
        left = NULL;
        right = NULL;
      }
};

Node* buildTree(){
    int val;
    cout<<"Enter root value: ";
    cin>>val;

    if(val == -1) return NULL;

    Node* root = new Node(val);

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        int leftVal,rightVal;

        cout << "Enter left child of " << curr->data << ": ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << ": ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

Node* insertNode(Node* root, int key){
    if (root == NULL) {
        return new Node(key);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left == NULL) {
            curr->left = new Node(key);
            return root;
        } else q.push(curr->left);

        if (curr->right == NULL) {
            curr->right = new Node(key);
            return root;
        } else q.push(curr->right);
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    // If tree has only one node
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            delete root;
            return NULL;
        }
        return root;
    }

    queue<Node*> q;
    q.push(root);

    Node* keyNode = NULL;
    Node* lastNode = NULL;
    Node* parentOfLast = NULL;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->data == key)
            keyNode = curr;

        if (curr->left) {
            parentOfLast = curr;
            lastNode = curr->left;
            q.push(curr->left);
        }

        if (curr->right) {
            parentOfLast = curr;
            lastNode = curr->right;
            q.push(curr->right);
        }
    }

    // If key node found
    if (keyNode != NULL) {
        keyNode->data = lastNode->data; // replace value

        // delete deepest node
        if (parentOfLast->right == lastNode)
            parentOfLast->right = NULL;
        else
            parentOfLast->left = NULL;

        delete lastNode;
    }

    return root;
}

bool searchBFS(Node* root, int key) {
    if (root == NULL) return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->data == key)
            return true;

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return false;
}

bool searchDFS(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;

    return searchDFS(root->left, key) || searchDFS(root->right, key);
}

void bfs(Node* root){
    if(root == NULL) return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";

        if(curr->left){
            q.push(curr->left);
        }

        if(curr->right){
            q.push(curr->right);
        }
    }

}

void preorder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int treeHeight(Node* root){
    if(root == NULL) return 0;

    int leftHeight, rightHeight;
    leftHeight = treeHeight(root->left);
    rightHeight = treeHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    //Node* root = buildTree();

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    insertNode(root, 4);
    insertNode(root, 5);
    deleteNode(root,4);

    int height = treeHeight(root);
    cout<<"Height of Tree: "<<height<<"\n";

    cout<<"BFS Traversal: ";
    bfs(root);
    cout<<endl;

    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postorder(root);

    return 0;
}