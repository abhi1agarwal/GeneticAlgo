/** C++ implementation for Red-Black Tree Insertion
   This code is adopted from the code provided by
   Dinesh Khandelwal in comments **/
#include <bits/stdc++.h>
using namespace std;
int req[111]={0};
enum Color {RED, BLACK};

struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;

    // Constructor
    Node(int data)
    {
       this->data = data;
       left = right = parent = NULL;
    }
};

// Class to represent Red-Black Tree
class RBTree
{
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    void levelOrder();
};

// A recursive function to do level order traversal
void inorderHelper(Node *root)
{   req[0]++;
    if (root == NULL)
        return;

    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}

/* A utility function to insert a new node with given key
   in BST */
Node* BSTInsert(Node* root, Node *pt)
{
    /* If the tree is empty, return a new node */
    req[1]++;
    if (root == NULL)
       return pt;

    /* Otherwise, recur down the tree */
    if (pt->data < root->data)
    {	req[2]++;
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {	req[3]++;
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}

// Utility function to do level order traversal
void levelOrderHelper(Node *root)
{		req[4]++;
    if (root == NULL)
        return;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {	req[5]++;
        Node *temp = q.front();
        cout << temp->data << "  ";
        q.pop();

        if (temp->left != NULL){
        	req[23]++;
            q.push(temp->left);
        }

        if (temp->right != NULL){
        	req[24]++;
            q.push(temp->right);
        }
    }
}

void RBTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;

    pt->right = pt_right->left;
    req[6]++;
    if (pt->right != NULL){
        pt->right->parent = pt;
    }

    pt_right->parent = pt->parent;

    if (pt->parent == NULL){
    	req[19]++;
        root = pt_right;
    }

    else if (pt == pt->parent->left){
        pt->parent->left = pt_right;
        req[20]++;
    }

    else{req[21]++;
        pt->parent->right = pt_right;
    }

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RBTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;

    pt->left = pt_left->right;
	req[7]++;
    if (pt->left != NULL){req[22]++;
        pt->left->parent = pt;
    }

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
    {   req[8]++;
        root = pt_left;
    }
    else if (pt == pt->parent->left){
    	req[22]++;
        pt->parent->left = pt_left;
    }

    else{
    	req[9]++;
        pt->parent->right = pt_left;
    }

    pt_left->right = pt;
    pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion
void RBTree::fixViolation(Node *&root, Node *&pt)
{
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;
    req[25]++;
    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {
    	req[10]++;
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /*  Case : A
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {
        	req[11]++;
            Node *uncle_pt = grand_parent_pt->right;

            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == RED)
            {	req[12]++;
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }

            else
            {	req[13]++;
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right)
                {	req[14]++;
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }

        /* Case : B
           Parent of pt is right child of Grand-parent of pt */
        else
        {
            Node *uncle_pt = grand_parent_pt->left;

            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == RED))
            {	req[15]++;
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {	req[16]++;
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left)
                {	req[17]++;
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

// Function to insert a new node with given data
void RBTree::insert(const int &data)
{
    Node *pt = new Node(data);
    req[18]++;
    // Do a normal BST insert
    root = BSTInsert(root, pt);

    // fix Red Black Tree violations
    fixViolation(root, pt);
}

// Function to do inorder and level order traversals
void RBTree::inorder()     {  inorderHelper(root);}
void RBTree::levelOrder()  {  levelOrderHelper(root); }

// Driver Code
int main()
{
    int tt,rr=26; // ;
    scanf("%d",&tt);
    fprintf(stderr,"%d %d\n",tt,rr);
    while (tt--)
    {
    	memset(req,0,sizeof(req));

	    RBTree tree;
	    int nn;
	    scanf("%d",&nn);
	    while (nn--)
	    {
	    	int d;
			
	    	scanf("%d",&d);
		    tree.insert(d);
	   	}
	    cout << "Inoder Traversal of Created Tree\n";
	    tree.inorder();
	    cout << "\n\nLevel Order Traversal of Created Tree\n";
	    tree.levelOrder();
	    {
	    	int i;
	    	for (i=0;i<rr;i++)
	    	{
	    		/*if (i==18)
	    			continue;*/
	    		fprintf(stderr,"%d ",req[i]>0?1:0);
	    	}
	    	fprintf(stderr,"\n");
	    }
	}
    return 0;
}