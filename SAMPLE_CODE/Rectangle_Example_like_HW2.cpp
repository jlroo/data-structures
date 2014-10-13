#include <iostream>

using namespace std;

//This is your Header
class Rectangle {

private:
		//class variables that are private below
		double length;
		double width;
		char * rect_name;
        char * title;
	
public:
    Rectangle(); //your constructor that takes in 2 parameters
		~Rectangle(); //this is a destructor
		
    //getters
		double get_area();
		double get_length();
		double get_width();
        char * get_rect_name();
        char * get_title_name();

		
    //setters
		bool set_length(double l);
		bool set_width(double w);
		bool set_rect_name(char * n);
        bool set_title_name(char * t);

};

//This is your class that has a scope of Header Rectangle

Rectangle::Rectangle(char *t,double l, double w) {

            title = t;
            length=l;
			width=w;
}

//Setters
bool Rectangle::set_length(double l) {
	if(l !=0){
		length=l;
		return true;
	}
	return false;
}

bool Rectangle::set_width(double w) {
	
    if(w != 0) {
        
		width=w;
		return true;
	}
	return false;
}


bool Rectangle::set_title_name(char * t){
    if(title!=NULL){
        delete title;
    }
    title = new char[strlen(t) + 1];
    strcpy(title, t);
    return true;
}


bool Rectangle::set_rect_name(char * n){
	if(rect_name!=NULL){
		delete rect_name;
	}
    rect_name = new char[strlen(n) + 1];
    strcpy(rect_name, n);
    return true;
}

//Getters
double Rectangle::get_length() {
	return length;
}

double Rectangle::get_width() {
	return width;
}

double Rectangle::get_area() {
	return length*width;
}

char * Rectangle::get_rect_name(){
	return rect_name;
}

char * Rectangle::get_title_name(){
    return title;
}


//Destructors get rid of any pointers that are created like rect_name, you can set other things to NULL and/or 0.

Rectangle::~Rectangle(){
	cout << "Destroying Rectangle"<<endl;
	if (length!=0){
		length=0;
	}
	if(width!=0){
		width=0;
	}
	if(rect_name!=NULL){
		delete rect_name;
	}
}


//your main to test your class implemented the header correctly

int main() {
    double length_r;
    double width_r;

    cout << "enter length"<<endl;
    cin >>length_r;
    cout << "enter width"<<endl;
    cin >> width_r;
    
    Rectangle * r= new Rectangle();
	
    char * r_name;
    cout<<"enter r name"<<endl;
    
    cin >> r_name;
	r->set_rect_name(r_name);
    
    cout <<"Name is ";
    cout <<r->get_title_name()<<endl;
	
    cout << "Width is " ;
	cout << r->get_width() << endl;
	
    cout << "Length is ";
	cout << r->get_length() << endl;
	cout << "Area is ";
	cout << r->get_area() << endl;
	
    cout <<"Name is ";
	cout <<r->get_rect_name()<<endl;
	delete r;
	
    return 1;
}