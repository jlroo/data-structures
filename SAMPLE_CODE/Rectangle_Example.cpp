#include <iostream>

using namespace std;

//This is your Header
class Rectangle {
	private:
		//class variables that are private below
		int length;
		int width;
	public:
		Rectangle(int l, int w); //your constructor that takes in 2 parameters
		//you accessors, this program does not have mutators
		int get_area();
		int get_length();
		int get_width();
};

//This is your class that has a scope of Header Rectangle
Rectangle::Rectangle(int l, int w)
{
	if(l<=0){
		cout << "Length must be a positive integer" << endl;
	}
	else
	{
		if(w<=0){
			cout << "Width must be a positive integer" << endl;
		}
		else
		{
			length=l;
			width=w;
		}
	}
}

int Rectangle::get_length() {
	return length;
}

int Rectangle::get_width() {
	return width;
}

int Rectangle::get_area() {
	return length*width;
}

//your main to test your class implemented the header correctly
int main()
{
	Rectangle r (5,3);
	cout << "Width is " ;
	cout << r.get_width() << endl;
	cout << "Length is ";
	cout << r.get_length() << endl;
	cout << "Area is ";
	cout << r.get_area() << endl;
	return 1;
}