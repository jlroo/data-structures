
bool test_input_simple()
{
    char input[300];
    string filename;
    string artist;
    string album;
    string label;
    int no_of_tracks;
    int year;
    string genre;
    double runtime;
    ifstream fin;
    cout << "Enter a filename: ";
    getline(cin, filename);
    fin.open(filename.c_str());
    
    do
    {
        if (fin.is_open())
        {
            getline(fin, artist, '\t');
            getline(fin, album, '\t');
            fin >> year;
            fin.getline(input, 300, '\t');
            getline(fin, label, '\t');
            fin >> no_of_tracks;
            fin.getline(input, 300, '\t');
            fin >> runtime;
            fin.getline(input, 300, '\t');
            getline(fin, genre, '\r');
            fin.getline(input, 300, '\n');
            
            cout << artist << "," << album << "," << year<< "," << label
            << "," << no_of_tracks << "," << runtime << " "<< genre << "\n\n";
        }
        else{
            cout<<"Could not open file in question, does it exist?"<<endl;
            return false;
        }
    }
    while (!fin.eof()); //checks the connection
    fin.close();
    return true;
}