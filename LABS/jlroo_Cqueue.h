class Cqueue
{
    private:
        int Rear, Front;
        int Queue[5];
        int Max;
        int Size;
    public:
        Cqueue(){Size=0; Max=5; Rear=Front=-1;}
        int Is_Empty();
        int Is_Full();
        void Add(int Element);
        int Delete();
        int getFront();
        void write_Cqueue_to_Console();         //write all of the class variables to the console
};

int Cqueue::Is_Empty()
{
    if(Size==0) return true;
    else return false;
}

int Cqueue::Is_Full()
{
    if(Size==Max) return true;
    else return false;
}

void Cqueue::Add(int Element)
{
    if(!Is_Full()) Rear=(Rear+1)%Max;
    cout<<"Rear-ADD: "<<Rear<<endl;
    Queue[Rear]=Element;
    Size++;
}

int Cqueue::Delete()
{
    if(Is_Empty())
    {
        cout << "The Cqueue is empty." << endl;
        return -1;
    }
    else
    {
        Front=(Front+1)%Max;
        cout<<"Front-Delete: "<<Front<<endl;
        Size--;
        return Queue[Front];
    }
}

int Cqueue::getFront()
{
    int Temp;
    if(Is_Empty())
    {
        return -1;
    }
    else
    {
        Temp=(Front+1)%Max;
        return Queue[Front];
    }
}

void Cqueue::write_Cqueue_to_Console()         //write all of the class variables to the console
{
    int i;
    int Temp;
    if(Is_Empty())
        cout << "Queue is empty.\n";
    else
    {
        for(i=1; i<=Size; i++)
        {
            Temp=(Front+i)%Max;
            cout << Queue[Temp] << " ";
        }
        cout << endl;
    }
}

