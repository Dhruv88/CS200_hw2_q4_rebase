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

void printZigZag(struct Node *root)
{
    // if null then return
    if (!root)
        return;

    // declare two stacks
    stack<struct Node *> currentlevel;
    stack<struct Node *> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty
    bool lefttoright = true;
    while (!currentlevel.empty())
    {

        // pop out of stack
        struct Node *temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp)
        {

            // print the data in it
            cout << temp->data << " ";

            // store data according to current
            // order.
            if (lefttoright)
            {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty())
        {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }

  
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

void printPreOrder(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
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
