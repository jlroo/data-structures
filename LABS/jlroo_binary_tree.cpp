/*************************************************************************
Create the functions for Preorder, Inorder, Postorder, PreorderR,
InorderR, and PostorderR. I've written a main function to test
your functions. What is D? L? and R?
Can you use the Find Node function?
*************************************************************************

#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
	public:
		char Data;
		TreeNode * Lchild;
		TreeNode * Rchild;
        int count;
};

class BinaryTree {
	public:
		TreeNode * Root;
	public:
		BinaryTree() {
            Root=NULL;
        }       //constructor
		void Preorder   ();
		void Inorder    ();
		void Postorder  ();
		void PreorderR  (TreeNode * );
		void InorderR   (TreeNode * );
        void PostorderR (TreeNode * );
        TreeNode * Find_Node_Inorder(char D);
        void InsertNode(char Val);
};

void BinaryTree::Preorder() {
    

}

void BinaryTree::Inorder() {
    TreeNode * Tmp=Root;
    stack<TreeNode * > S;
    while(1)
    {
        //traverse left until its NULL & push
        while(Tmp!=NULL)
        {
            S.push(Tmp);
            Tmp=Tmp->Lchild;
        }
        //if stack is empty stop the process
        if(S.empty()) return;
        //if not empty, pop 1 and go right
        Tmp=S.top();
        S.pop();
        cout << Tmp->Data;
        Tmp=Tmp->Rchild;
    }
}

void BinaryTree::Postorder()
{

}

void BinaryTree::PreorderR( TreeNode * root) {
}

void BinaryTree::InorderR(TreeNode *) {
    if(Root!=NULL)
    {
        InorderR(Root->Lchild);
        cout << Root->Data;
        InorderR(Root->Rchild);
    }
}

void BinaryTree::PostorderR(TreeNode*) {

}


TreeNode* BinaryTree::Find_Node_Inorder(char D) {
    
    node *temp=head;
    
    while(temp!=NULL)
    {
        if(temp->data==num)
            break;
        
        if(num>temp->data)
            temp=temp->right;
        
        if(num<temp->data)
            temp=temp->left;
    }
    if(temp==NULL)
        return false;
    else if(temp->data==num)
        return true;
}

void BinaryTree::InsertNode(char Val ) {
	TreeNode *newNode,	// Pointer to a new node
             *nodePtr;
	// Create a new node
    newNode = new TreeNode;
	newNode->Data = Val;
	newNode->Lchild = newNode->Rchild = NULL;

	if (!Root)	// Is the tree empty?
		Root = newNode;
	else
	{
		nodePtr = Root;
		while (nodePtr != NULL)
		{
			if (Val < nodePtr->Data)
			{
				if (nodePtr->Lchild)
					nodePtr = nodePtr->Lchild;
				else
				{
					nodePtr->Lchild = newNode;
					break;
				}
			}
			else if (Val > nodePtr->Data)
			{
				if (nodePtr->Rchild)
					nodePtr = nodePtr->Rchild;
				else
				{
					nodePtr->Rchild = newNode;
					break;
				}
			}
			else
			{
				cout << "Duplicate value found in tree.\n";
				break;
			}
		}
	}
}


/*
 struct TNode{
 long data;
 struct TNode *left;
 struct TNode *right;
 };
 
 struct TNode * newNode(long data){
 struct TNode * node = new struct TNode ;
 node->data=data;
 node->left=NULL;
 node->right=NULL;
 return node;
 }
 
 struct TNode * sorted_vector_ToBST( vector<long> l_gnome, long start, long end){
 if(start>end)
 return NULL;
 long mid = start + (end - start) / 2;
 struct TNode * root=newNode(l_gnome[mid]);
 root->left=sorted_vector_ToBST(l_gnome,start, mid-1);
 root->right=sorted_vector_ToBST(l_gnome,mid+1, end);
 return root;
 }
 
 struct TNode * sorted_vector_ToBST( vector<long> l_gnome, long n){
 return sorted_vector_ToBST(l_gnome,0, n-1);
 }
 
 void preOrder(struct TNode *root ){
 if(root==NULL)
 return ;
 // preOrder(root->left);
 cout<<root->data<<endl;
 preOrder(root->left);
 preOrder(root->right);
 }
 
 void Inorder( struct TNode * root ){           //Function to read the tree Inorder data structure
 if(root!=NULL) {                                        //and print out the data in the root
 Inorder (root -> left);
 cout << root ->data <<endl;
 Inorder (root ->right);
 }
 }
 
 void Postorder ( struct TNode * root ) {             //Function to read the tree Postorder data structure
 if (root!=NULL) {
 Postorder (root-> left);
 Postorder (root-> right);
 cout << root->data<<endl;
 }
 }
 
 bool Search( struct TNode * root,long val) {                //Function to search inpur data in the tree
 struct TNode * Tmp= root;                       //Points Tmp to the Root
 while (Tmp) {
 if ( Tmp->data== val)
 return 1;
 else
 if (Tmp->data > val)
 Tmp=Tmp->left;
 else
 Tmp=Tmp->right;
 }
 return 0;
 }
 
 */


 
 
 /************************************* MAIN FUNCTION *************************************/
/*
int main()
{
    //   void BinaryTree::Insert(char key, TreeNode *leaf)
    
    BinaryTree b;
    b.InsertNode('m');
    b.InsertNode('q');
    b.InsertNode('a');
    b.InsertNode('q');
    b.InsertNode('a');
    b.InsertNode('e');
    
    cout << "Inorder: ";
    b.Inorder();
    cout << endl;
 
     cout << "Postorder: ";
     b.Postorder();
     cout << endl;
     
     cout << "Preorder: ";
     b.Preorder();
     cout << endl;
 
    return 0;
}
 
 */

 #include<stdio.h>
 #include<stdlib.h>

 struct tree{
     char data;
     struct tree * child;
     struct tree * sibling;
 };

 void preorder( struct tree * p) {
     if(p==NULL)
         return;
     preorder(p->child);
     printf(" %d",p->data);
     preorder(p->sibling);
 }

 struct tree * search(struct tree* root,int data) {
     if(root==NULL)
         return NULL;
     if(data==root->data)
         return root;
     struct tree * t = search(root->child,data);
        if(t==NULL)
            t = search(root->sibling,data);
        return t;
 
 }
 
 struct tree * createNode(char data) {
    struct tree * newnode = new tree;
    newnode->child   = NULL;
    newnode->sibling = NULL;
    newnode->data    = data;
    return newnode;
 }
 
 struct tree * createnary(struct tree * root,char data[]) {
 
     struct tree * newnode = search(root,data[0]);      //check if node exist already
        if(newnode==NULL) {                             //if node does not exist
            newnode= createNode(data[0]);
        }
     struct tree * parent=newnode;                      /////now create node of its children
     int j;
        for(j=0;j<data[1];j++) {                        //for first child
            if(j==0) {
                parent->child=createNode(data[j+2]);
                parent = parent->child;
            }                                              //for all other childs
            else {
                parent->sibling=createNode(data[j+2]);
                parent = parent->sibling;
            }
        }
        if(root==NULL)
            root = newnode;
        return root;
}

 int main() {
     int row = 3;                                           //no. of input lines
     char data[3][5]={
                        {'g','a','g','t','t'},                    //1st element in each row is node Value,
                        {'a','g','t','t','c'},                    //2nd - no of child,
                        {'t','t','t','t','t'}                    //>=3rd....=>value of child
                    };
     int i,j;
     struct tree * root = NULL;
     
     for(i=0;i<row;i++) {
    //     preorder(root);
         root = createnary(root,data[i]);
     }
     
     printf(" OTHER PREORDER ");
    
     preorder(root);
 }

/*
 gagttttatc
 agttttatcg
 gttttatcgc
 ttttatcgct
 tttatcgctt
 */
 



