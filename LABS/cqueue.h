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
