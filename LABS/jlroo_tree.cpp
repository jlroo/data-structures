#include <iostream>

class Node
{

    public:
        int data;
        Node * link;
};

class Llist
{
    private:
        Node *Head, *Tail;
    public:
        Llist();
        void Append(Node * NewNode);
        void Insert_at_Pos(Node * NewNode, int position);
        void DeleteNode(int position);
        void show_nodes();
        Node * search_for_node(int data);
        int length_list();
};

using namespace std;

Llist::Llist()
{
    Head=NULL;
}

void Llist::Append(Node * NewNode)
{
    if(Head==NULL)
    {
        Head=NewNode;
        Tail=NewNode;
    }
    else
    {
        Tail->link=NewNode;
        Tail=NewNode;
    }
}

void Llist::Insert_at_Pos(Node * NewNode, int position)
{
    Node *temp=Head;
    if(position==1)     //we will insert at the first position
    {
        NewNode->link=temp;
        Head=NewNode;           //update the head
    }
    else
    {
        int count=1, flag=1;
        while(count!=position-1)
        {
            temp=temp->link;
            if(temp==NULL) {flag=0; break;}
            count++;
        }
        if(flag==1)
        {
            NewNode->link=temp->link;
            temp->link=NewNode;
        }
        else
            cout << "Position not found.\n";
    }
}

void Llist::DeleteNode(int position)
{
    Node *temp=Head;
    if(position==1)     //we will delete the first node
    {
        Head=temp->link;
        delete temp;           //delete the node
    }
    else
    {
        int count=1, flag=1;
        Node *curr;
        while(count!=position-1)
        {
            temp=temp->link;
            if(temp==NULL) {flag=0; break;}
            count++;
        }
        if(flag==1)
        {
            curr=temp->link;
            temp->link=curr->link;
            delete curr;
        }
        else
            cout << "Position not found.\n";
    }
}

void Llist::show_nodes()
{
    int i=1;
    Node * temp;
    temp=Head;
    cout << i << "\t" << temp->data << "\n";
    i++;
    while(temp->link!=NULL)
    {
        temp=temp->link;
        cout << i << "\t" << temp->data << "\n";
        i++;
    }
}

/******************* Week 6, Exercise 1 *******************/
Node * Llist::search_for_node(int data)
{
    //write your function here
    return NULL;		//You'll need to fix this. Return 0 included to compile
}

int Llist::length_list()
{
    //write your function here
    return 0;		//You'll need to fix this. Return 0 included to compile
}

/******************* Week 6, Exercise 1 *******************/

int main()
{
    Llist x;                //create the linked list

    //create a node to add to list
    Node *node1=new Node;
    node1->data=10;
    node1->link=NULL;
    x.Append(node1);

    //create a node to add to list
    Node *node2=new Node;
    node2->data=5;
    node2->link=NULL;
    x.Append(node2);
    x.show_nodes();

    //create a node to add to list at 2nd position
    Node *node3=new Node;
    node3->data=1;
    node3->link=NULL;
    x.Insert_at_Pos(node3,2);
    x.show_nodes();

    //test the length_list function
    cout << "The list has " << x.length_list() << " elements." << endl;
    cout << endl;

    //test search_for_node function
    Node * temp;
    temp=x.search_for_node(1);
    if(temp!=NULL) cout << "I found " << temp->data << endl;

    //delete a node and test the length_list function again
    x.DeleteNode(2);
    x.show_nodes();
    cout << "The list has " << x.length_list() << " elements." << endl;

    //test search_for_node function --> Should not find it; it is looking for the deleted node
    temp=x.search_for_node(1);
    if(temp!=NULL) cout << "I found " << temp->data << endl;

    return 0;
}
