#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    // Insert a node
    void insert(int value)
    {
        root = insertNode(root, value);
    }

    Node* insertNode(Node *temp, int value)
    {
        if (temp == NULL)
        {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        if (value < temp->data)
            temp->left = insertNode(temp->left, value);
        else
            temp->right = insertNode(temp->right, value);

        return temp;
    }

    // Level order traversal
    void levelOrder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        cout << endl;
    }

    // Find height of BST
    int height()
    {
        return findHeight(root);
    }

    int findHeight(Node *temp)
    {
        if (temp == NULL)
            return -1;

        int leftHeight = findHeight(temp->left);
        int rightHeight = findHeight(temp->right);

        return 1 + max(leftHeight, rightHeight);
    }

    // Print leaf nodes
    void printLeafNodes()
    {
        printLeaves(root);
        cout << endl;
    }

    void printLeaves(Node *temp)
    {
        if (temp == NULL)
            return;

        if (temp->left == NULL && temp->right == NULL)
        {
            cout << temp->data << " ";
            return;
        }

        printLeaves(temp->left);
        printLeaves(temp->right);
    }
};

int main()
{
    BST tree;
    int choice, value;

    do
    {
        cout << "\n===== Binary Search Tree Menu =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Level-wise Traversal";
        cout << "\n3. Find Height";
        cout << "\n4. Display Leaf Nodes";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Level-wise Traversal: ";
            tree.levelOrder();
            break;

        case 3:
            cout << "Height of BST: " << tree.height() << endl;
            break;

        case 4:
            cout << "Leaf Nodes: ";
            tree.printLeafNodes();
            break;

        case 5:
            cout << "Program Exited." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
