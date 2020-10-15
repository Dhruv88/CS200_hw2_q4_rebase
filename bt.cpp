#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<fstream>

struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

//Make a valid binary tree from the inorder traversal
Node *buildTree(int in[], int n)
{

    Node *root = newNode(in[n / 2]);
    Node *cur = root;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Node *temp = newNode(in[i]);
        cur->left = temp;
        cur = cur->left;
    }
    cur = root;
    for (int i = n / 2 + 1; i < n; i++)
    {
        Node *temp = newNode(in[i]);
        cur->right = temp;
        cur = cur->right;
    }
    return root;
}


int main()
{
    int in[30];
    string FileName;
    cout << "Store the input file in same folder in which the code is stored and provide file name with extension\n";
    cin >> FileName;
    //read input from file specified
    ifstream file(FileName);

    int cnt = 0;
    int x;

    while (cnt < 30 && file >> x)
        in[cnt++] = x;

    // display the values stored in the array as confirmation
    for (int i = 0; i < cnt; i++)
        cout << in[i] << ' ';
    cout << "\n";

    int n = cnt;
    Node *root = buildTree(in, n);
    cout << "The binary tree is constructed\n";
    return 0;
}
