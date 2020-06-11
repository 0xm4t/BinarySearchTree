#include <bits/stdc++.h>
#include <search.h>

using namespace std;

struct Node {
    double key;
    struct Node *left, *right;
};

Node* newNode(double item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void printTree(struct Node* node)
{
    if (node == NULL)
        return;

    cout << node->key << " ";

    printTree(node->left);

    printTree(node->right);
}

Node* addNode(Node* node, double key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = addNode(node->left, key);
    else
        node->right = addNode(node->right, key);

    return node;
}


Node* removeNode(Node* root, double k)
{
    // Base case
    if (root == NULL)
        return root;

    if (root->key > k) {
        root->left = removeNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = removeNode(root->right, k);
        return root;
    }


    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    else {

        Node* succParent = root->right;

        Node *succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }


        succParent->left = succ->right;

        root->key = succ->key;

        delete succ;
        return root;
    }
}

void print2DUtil(Node *root, int space)

{
    if (root == NULL)
        return;
    int COUNT = 10;
    space += COUNT;

    print2DUtil(root->right, space);


    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";

    print2DUtil(root->left, space);
}

void print2D(Node *root)
{

    print2DUtil(root, 0);
}


int main()
{


    Node* root = NULL;


    double TreeKeys[16] = {52.4,32.3,24.2, 4.4,41.4 ,72.7,63.6,83.44, 14.4, 100.21,
                           83.3, 2.2, 3.1, 70.4, 4};
    for (int i = 0; i < 16; ++i)
    {
        root = addNode(root,TreeKeys[i]);
    }

    printTree(root);
    cout << "  ( for Preorder traversal )   \n";

    print2D(root);

    return 0;
}