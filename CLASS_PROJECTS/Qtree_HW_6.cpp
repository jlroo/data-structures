#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class BTreeNode
{
	public:
		char Data;
		BTreeNode *Lchild;
		BTreeNode *Rchild;
};

class QTreeNode
{
	public:
		char Data;
		QTreeNode *child1;
		QTreeNode *child2;
		QTreeNode *child3;
		QTreeNode *child4;
};

bool get_words(char * file_name, vector<string> &w, char type);
bool get_reads(char * file_name, vector<string> &r, char type);
bool write_vector_to_screen(vector<string> v);
bool write_vector_to_file(vector<string> v, char * file_name);

int main()
{
    vector<string> words;
    char * genome_file_name="genome_file.txt";          //make certain to place this file in the correct folder. Do not change path.
    if(!get_words(genome_file_name,words,'Q'))          //if doing QTreeNode, pass in 'Q'
        return 1;

    //1. Create a tree based on either BTreeNode or QTreeNode --> transforming the vector of words into the tree
    //2. Read in file BReads or QReads using function get_reads(read_file_name,reads);
    vector<string> reads;
    char * reads_file_name="test_file_BT.txt";           //make certain to place this file in the correct folder. Do not change path.
    if(!get_reads(reads_file_name,reads, 'Q'))          //if doing QTreeNode, pass in 'Q'
        return 1;
    //3. for each read, map it through the tree. If it follows a path in the tree, this read belongs to this genome. Write out a file named "BReads_map_results.txt" or "QReads_map_results.txt" listing each read and "Yes" or "No" if it does or doesn't map to the genome.

    //these function calls are here so that you can check that you are reading and writing correctly. -- REMOVE once you have tested
//    cout << "words" << endl;
//    write_vector_to_screen(words);
        write_vector_to_file(words,"write_outcome_fileBT.txt");
 //   cout << "reads" << endl;
 //   write_vector_to_screen(reads);
}


/*******************************************************************************
This function takes the genome file name to read and reads all overlapping
words of size 10 that are present in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
Type='B' means you are doing a binary tree. Type='Q' means you are doing
the quartenary tree. This function will translate the file such that the
same file can be used for either tree.
*******************************************************************************/
bool get_words(char * file_name, vector<string> &w, char type)
{
    int i,j;
    int len=0;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) {cout << "The genome file could not be opened. Check the location.\t"; return false;}

    char * word=new char [11];                              //this is a default, we'll be looking at words of size 10
    while(in.peek()!=EOF) {in>>word[0]; len++;}             //gets the length of the sequence
    in.clear(); in.close(); in.open(file_name);             //have to close and reopen file to reset filestream to beginning of file

    for(i=0; i<10; i++)
    {
        in>> word[i];
        if(word[i]<97) word[i]+=32;     //makes it lowercase
        if(type=='B' || type=='b')      //if doing BTree, translates 4 letter code into two letter code
        {
            if(word[i]=='a' || word[i]== 'g') word[i]='r';  //purine
            else word[i]='y';   //pyrimidine
        }

    }
    word[10]='\0';
    w.push_back(word);
    
    for(i=1; i<(len-10-1); i++)   //read until the end of the file
    {
        //shift
        for(j=0; j<9; j++) word[j]=word[j+1];
        in>> word[9];
        if(word[9]<97) word[9]+=32;     //makes it lowercase
        if(type=='B' || type=='b')
        {
            if(word[9]=='a' || word[9]== 'g') word[9]='r';  //purine
            else word[9]='y';   //pyrimidine
        }
        word[10]='\0';
        //strcpy(w[i],word);
        cout << i << "\t" << word << endl; cout.flush();
       w.push_back(word);
    }
    in.clear(); in.close();

    return true;
}

/*******************************************************************************
This function takes the reads file name to read and reads each individual word
in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
Type='B' means you are doing a binary tree. Type='Q' means you are doing
the quartenary tree. This function will translate the file such that the
same file can be used for either tree.
*******************************************************************************/
bool get_reads(char * file_name, vector<string> &r, char type)
{
    int i;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) {cout << "The read file could not be opened. Check the location.\t"; return false;}
    
    char * word=new char [20];                              //this is a default, we'll be looking at words of size 10
    
    while(in.peek()!=EOF)
    {
        in.getline(word,20,'\n');
        for(i=0; i<10; i++) {
            if(word[i]<97) word[i]+=32;                      //makes it lowercase
        }
        if(type=='B' || type=='b')      //if doing BTree, translates 4 letter code into two letter code
        {
            for(i=0; i<10; i++)
            {
                if(word[i]=='a' || word[i]== 'g') word[i]='r';  //purine
                else word[i]='y';   //pyrimidine
            }
        }
        r.push_back(word);
    }
    in.clear(); in.close();
    delete word;
    return true;
}

bool write_vector_to_screen(vector<string> v)
{
    int i;
    for(i=0; i<v.size(); i++)
        cout << v[i] << endl;
    return true;
}

bool write_vector_to_file(vector<string> v, char * file_name)
{
    ofstream out;
    out.open(file_name);
    int i;
    for(i=0; i<v.size(); i++)
        out << v[i] << endl;
    out.clear();
    out.close();
    return true;
}
