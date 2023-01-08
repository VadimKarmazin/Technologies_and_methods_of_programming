/*
 * C++ Program to Implement Randomized Binary Search Tree
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib> 
#define MAX_VALUE 65536
using namespace std;
/*
 * Class RBSTNode
 */
class RBSTNode
{
public:
    RBSTNode* left, * right;
    int priority, element;
    /* Constructor */
    RBSTNode()
    {
        this->element = 0;
        this->left = this;
        this->right = this;
        this->priority = MAX_VALUE;
    }
    /* Constructor */
    RBSTNode(int ele)
    {
        RBSTNode(ele, NULL, NULL);
    }
    /* Constructor */
    RBSTNode(int ele, RBSTNode* left, RBSTNode* right)
    {
        this->element = ele;
        this->left = left;
        this->right = right;
        this->priority = rand() % 100 + 1;
    }
};

/*
 * Class RandomizedBinarySearchTree
 */
class RandomizedBinarySearchTree
{
private:
    RBSTNode* root;
    RBSTNode* nil;
public:
    /* Constructor */
    RandomizedBinarySearchTree()
    {
        root = nil;
    }
    /* Function to check if tree is empty */
    bool isEmpty()
    {
        return root == nil;
    }
    /* Make the tree logically empty **/
    void makeEmpty()
    {
        root = nil;
    }

    /* Functions to insert data **/
    void insert(int X)
    {
        root = insert(X, root);
    }
    RBSTNode* insert(int X, RBSTNode* T)\
    {
        if (T == nil)
            return new RBSTNode(X, nil, nil);
        else if (X < T->element)
        {
            T->left = insert(X, T->left);
            if (T->left->priority < T->priority)
            {
                RBSTNode* L = T->left;
                T->left = L->right;
                L->right = T;
                return L;
            }
        }
        else if (X > T->element)
        {
            T->right = insert(X, T->right);
            if (T->right->priority < T->priority)
            {
                RBSTNode* R = T->right;
                T->right = R->left;
                R->left = T;
                return R;
            }
        }
        return T;
    }
    /*
     * Functions to count number of nodes
     */
    int countNodes()
    {
        return countNodes(root);
    }

    int countNodes(RBSTNode* r)
    {
        if (r == nil)
            return 0;
        else
        {
            int l = 1;
            l += countNodes(r->left);
            l += countNodes(r->right);
            return l;
        }
    }
    /*
     * Functions to search for an element
     */
    bool search(int val)
    {
        return search(root, val);
    }
    bool search(RBSTNode* r, int val)
    {
        bool found = false;
        while ((r != nil) && !found)
        {
            int rval = r->element;
            if (val < rval)
                r = r->left;
            else if (val > rval)
                r = r->right;
            else
            {
                found = true;
                break;
            }
            found = search(r, val);
        }
        return found;
    }

    /*
     * Function for inorder traversal
     */
    void inorder()
    {
        inorder(root);
    }

    void inorder(RBSTNode* r)
    {
        if (r != nil)
        {
            cout << r->element << "  ";
            inorder(r->left);

            inorder(r->right);
        }
    }
    /*
     * Function for semetric traversal
     */
    vector<int> preorder()
    {
        return preorder(root);
    }
    vector<int> preorder(RBSTNode* r)
    {
        vector<int> semetric;
        if (r != nil)
        {

            preorder(r->left);
            cout << r->element << "  ";
            preorder(r->right);
            semetric.push_back(r->element);
        }
        return semetric;
    }








    vector<int> preorder_with()
    {
        vector <int> res;
        preorder_with(root, &res);
        return res;
    }
    void preorder_with(RBSTNode* r, vector<int>* res)
    {

        if (r != nil)
        {

            preorder_with(r->left, res);

            preorder_with(r->right, res);
            res->push_back(r->element);
        }

    }


    /*
     * Function for postorder traversal
     */
    vector<int> postorder()
    {
        return  postorder(root);
    }
    vector<int> postorder(RBSTNode* r)
    {
        vector<int> postmas;
        if (r != nil)
        {
            postorder(r->left);
            postorder(r->right);
            cout << r->element << "  ";
            postmas.push_back(r->element);

        }

        return postmas;
    }

    vector<int> postorder_with()
    {
        vector<int> res;
        postorder_with(root, &res);
        return res;
    }
    void postorder_with(RBSTNode* r, vector<int>* res)
    {

        if (r != nil)
        {
            postorder_with(r->left, res);
            postorder_with(r->right, res);

            res->push_back(r->element);

        }


    }


    RandomizedBinarySearchTree task(RandomizedBinarySearchTree rbst_1) {

        vector<int> a;

        auto semetric = this->preorder_with();
        auto postorder = rbst_1.postorder_with();

        for (int i = 0; i < semetric.size(); i++) {
            for (int j = 0; j < postorder.size(); j++) {
                if (semetric[i] != postorder[j]) {
                    a.push_back(semetric[i]);
                }
            }
        }
        RandomizedBinarySearchTree rbst_2;
        for (int i = 0; i < a.size(); i++) {
            rbst_2.insert(a[i]);
        }
        return rbst_2;
    }
};

/*
 * Main Contains Menu
 */

int main()
{

    RandomizedBinarySearchTree rbst;
    RandomizedBinarySearchTree rbst_1;

    rbst_1.insert(1);
    rbst_1.insert(2);
    rbst_1.insert(6);
    rbst_1.insert(10);
    rbst_1.insert(11);

    cout << "Randomized Binary SearchTree Test\n";
    char ch;
    int choice, item;
    /*
     * Perform tree operations
     */
    do
    {
        cout << "\nRandomized Binary SearchTree Operations\n";
        cout << "1. Insert " << endl;
        cout << "2. Search " << endl;
        cout << "3. Count Nodes " << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Clear" << endl;
        cout << "6. Task" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter integer element to insert: ";
            cin >> item;
            rbst.insert(item);
            break;
        case 2:
            cout << "Enter integer element to search: ";
            cin >> item;
            if (rbst.search(item))
                cout << "Element " << item << " found in the Tree" << endl;
            else
                cout << "Element " << item << " not found in the Tree" << endl;
            break;
        case 3:
            cout << "Nodes = " << rbst.countNodes() << endl;
            break;
        case 4:
            if (rbst.isEmpty())
                cout << "Tree is Empty" << endl;
            else
                cout << "Tree is not Empty" << endl;
            break;
        case 5:
            cout << "\nRandomizedBinarySearchTree Cleared" << endl;
            rbst.makeEmpty();
            break;
        case 6:
            rbst.task(rbst_1);
            break;
        default:
            cout << "Wrong Entry \n ";
            break;
        }

        /**  Display tree  **/
        cout << "\nPost order : ";
        rbst.postorder();
        cout << "\nsemetric order : ";
        rbst.preorder();
        cout << "\nIn order : ";
        rbst.inorder();
        cout << "\nDo you want to continue (Type y or n) \n";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
