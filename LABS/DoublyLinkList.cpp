#include <iostream>

class DLL_Node
{
	public:
		int data;
		DLL_Node *prev, *next;
		DLL_Node() {prev=next=NULL;}
};

class DList
{
	private:
		DLL_Node *Head, *Tail;
	public:
		DList() {Head=Tail=NULL;}
		void Append(DLL_Node *NewNode);
		DLL_Node* GetNode();
		void Create();
		void Traverse();
		void Delete_Pos(int pos);
		void Insert_Pos(DLL_Node * NewNode, int pos);
        DLL_Node * search_for_node(int data);
        int length_list();

};



using namespace std;

void DList::Append(DLL_Node *NewNode)
{
	if(Head==NULL)
	{
		Head=NewNode;
		Tail=NewNode;
	}
	else
	{
		Tail->next = NewNode;	//add to end
		NewNode->prev = Tail;
		Tail = NewNode;
	}
}

DLL_Node* DList::GetNode()
{
	DLL_Node *NewNode;
	NewNode = new DLL_Node;
	cout << "Enter data ";
	cin >> NewNode->data;
	NewNode->next = NewNode->prev = NULL;
	return NewNode;
}

void DList::Create()
{
	char ans;
	DLL_Node *NewNode;
	while(1)
	{
		cout << "Any more nodes to add (Y/N)? ";
		cin >> ans;
        if( (ans=='n') || (ans=='N') )
			break;
		NewNode = GetNode();
		Append(NewNode);
	}
}

void DList::Traverse()
{
	DLL_Node *Curr;
	Curr = Head;
	if(Curr==NULL) cout << "List is empty\n";
	else
	{
		while(Curr != NULL)
		{
			cout << Curr->data << "\t";
			Curr = Curr->next;
		}
	}
}

void DList::Delete_Pos(int pos)
{
    int count=1;
    DLL_Node *temp=Head;
    if(pos==1)
    {
        Head=Head->next;
        Head->prev=NULL;
        delete temp;
    }
    else
    {
        while(count != pos)
        {
            temp=temp->next;
            if(temp!=NULL)
                count++;
            else
                break;
        }
        if(count==pos)
        {
            if(temp==Tail)
            {
                Tail=temp->prev;
                (temp->prev)->next=NULL;
                delete temp;
            }
            else
            {
                (temp->prev)->next=temp->next;
                (temp->next)->prev=temp->prev;
                delete temp;
            }
        }
        else cout << "The node to be deleted is not found." << endl;
    }
}

void DList::Insert_Pos(DLL_Node * NewNode, int pos)
{
    DLL_Node *temp=Head;
    int count=1;

    if(Head==NULL)
        Head=Tail=NewNode;
    else if(pos==1)     //the node will be new head
    {
        NewNode->next=Head;
        Head->prev=NewNode;
        Head=NewNode;
    }
    else
    {
        while(count!=pos)   //increment to position
        {
            temp=temp->next;
            if(temp!=NULL)
                count++;
            else
                break;
        }
        if(count==pos)
        {
            (temp->prev)->next=NewNode;
            NewNode->prev=temp->prev;
            NewNode->next=temp;         //wasn't in book
            temp->prev=NewNode;
        }
        else
            cout << "The node position is not found" << endl;
    }
}

/******************* Week 6, Exercise 2 *******************/
DLL_Node * DList::search_for_node(int data)
{
    DLL_Node * temp;
    temp=Head;
    if(temp->data==data) return temp;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        if(temp->data==data) return temp;
    }
    cout << "Could not find value in list.\n";
    return NULL;
}

int DList::length_list()
{
    DLL_Node * temp;
    temp=Head;
    int count=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

/******************* Week 6, Exercise 2 *******************/


int main()
{
    DList x;
    x.Create();
    x.Traverse();
    cout << endl;
    //x.Delete_Pos(1);
    DLL_Node *a=new DLL_Node();
    a->data=10;
    x.Insert_Pos(a,2);
    x.Traverse();
    cout << endl;
    return 0;
}
