//
//  HW_1.cpp
//  COMP_271
//  FALL 2014
//  Created by jlroo on 9/3/14.
//  Copyright (c) 2014 Jose L Rodriguez. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
const double pi = 3.1415926;

class Cube {
private:
    int length;
    int width;
    int depth;
    
public:
    Cube(int l, int w, int d);
    int get_length();
    int get_width();
    int get_depth();
    int get_surface_area();
};

Cube::Cube(int l, int w, int d){
        length=l;
        width=w;
        depth=d;
};

int Cube::get_length()
{
	return length;
}

int Cube::get_width()
{
	return width;
}

int Cube::get_depth()
{
	return depth;
}

int Cube::get_surface_area() // Rectangular Prism area = 2ab + 2bc + 2ac
{
    
	return 2*(length*width)+2*(length*depth)+2*(width*depth);
}

class Sphere{
private:
    int radius;
public:
    Sphere(double r);
    int get_radius();
    int get_surface_area();
};

Sphere::Sphere(double r){
        radius=r;
}

int Sphere::get_surface_area(){
    
	return 4*(pi)*(radius^2);
}

class Triangle{
    
private:
    int base;
    int height;
    
public:
    Triangle(int b, int h);
    int get_base(); //return base
    int get_height(); //return height
    int get_area(); //sum of area for triangle
};

Triangle::Triangle(int b, int h){
    
        base=b;
        height=h;
}

int Triangle::get_base(){
    return base;
}

int Triangle::get_height(){
    return height;
}

int Triangle::get_area(){
    int r;
    r=base*height;
    return r/2;
}
int main(){
    //initialize user input variables
	char key;
    int length_user;
    int width_user;
    int depth_user;
    double radius_user;
    int base_user;
    int height_user;

    do {
        //welcome message and menu options
        cout << "Welcome to Geometry 101"<<endl<<endl;
        cout << "Lets find some shapes"<< endl;
        cout << "For Rectangular Prism press(1)"<<endl;
        cout << "For Sphere press(2)"<<endl;
        cout << "For Triangle press(3)"<<endl;
        cout << "To Exit press(4)"<<endl;
        cout << "Choose one option:"<<endl;
        cin >> key; //get option for the swicth
        cout << ""<<endl;
        
        switch (key) {
       
            case 49:{
            cout << "To find a Rectangular Prism Surface Area enter values for:" <<endl;
            cout << "Lenght"<<endl;
            cin >> length_user; //get length value from user
            cout << "width"<<endl;
            cin >> width_user; //get width value from user
            cout << "depth"<<endl;
            cin >> depth_user; //get depth value from user
                
                if (length_user<=0 || width_user<=0 || depth_user<=0) { //check that values are not less or equal to zero
                    cout <<"Values must be positive, try again or exit" << endl<<endl;;
                }
                else {
                    
                    Cube s_area (length_user, width_user,depth_user);
                    cout << "The Surface area is:"<<endl;
                    std::string rec_prism = std::to_string(s_area.get_surface_area());// to avoid trigger the switch to an infinite loop from the result
                    cout << rec_prism <<endl<<endl;
                }
            }
            break;
        
            case 50:{
                cout << "To find a Sphere Surface Area enter value for:" <<endl;
                cout << "Radius"<<endl<<endl;
                cin >> radius_user;
                if (radius_user<=0) {
                    cout <<"Values must be positive, try again or exit" << endl<<endl;;
                }
                else {
                    Sphere sphere_area (radius_user);
                    cout << "The Surface area is:"<<endl;
                    std::string sphere_anw = std::to_string(sphere_area.get_surface_area());// to avoid trigger the switch to an infinite loop from the result
                    cout << sphere_anw <<endl<<endl;
                }
            }
            break;
        
            case 51:{
                cout << "To find an Area of a Triangle enter values for:" <<endl;
                cout << "Base"<<endl;
                cin >> base_user;
                cout << "Heigth"<<endl;
                cin >>  height_user;
                if (base_user<=0 || height_user<=0) {
                    cout <<"Values must be positive, try again or exit" << endl<<endl;;
                }
                else {
                    Triangle t_area (base_user, height_user);
                    cout << "The area is:"<<endl;
                    std::string triangle_area = std::to_string(t_area.get_area());// to avoid trigger the switch to an infinite loop from the result
                    cout << triangle_area <<endl<<endl;
                }
            }
            break;
        
            case 52:{
                cout << "Thank you!"<<endl<<endl;
            }
            break;
            default:{
                cout << "Not an option, try again or exit (4)"<<endl<<endl;
            }
            
        }
    }while (key!=52);
}