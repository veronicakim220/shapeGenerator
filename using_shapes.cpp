//*********************************************
// Student Name: Ji Won (Veronica) Kim
// Student Number: 20539908
//
// SYDE 121 Lab: 10 Assignment: 1
//
// Filename: using_shapes.cpp
// Date submitted: November Sat. 30th Nov 2013
//
// I hereby declare that this code, submitted
// for credit for the course SYDE121, is a product
// of my own efforts. This coded solution has
// not been plagiarized from other sources and
// as not been knowingly plagiarized by others.
//
//*********************************************

#include "shape.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Shape my_square;
	Diamond my_diamond;
    Pyramid my_pyramid;
    Triangle my_triangle;

    // Open output stream and check for any errors
    ofstream fout;
    fout.open("output.txt");
    if (fout.fail()) {
       cout << "Error occurred opening output.txt\n";
       system("pause");
       exit(EXIT_FAILURE);
    }
    
	 // initialize my_square and print to file
    my_square.defineSize();
    my_square.defineFill();
    
    if(my_square.getIsFilled() == true){
    	fout << "Filled Square of size " << my_square.getSize() << ": \n";
    	my_square.printFilledShape(fout);
    }else{
    	fout << "Hollow Square of size " << my_square.getSize() << ": \n";    	
    	my_square.printHollowShape(fout);
    }
    
     // initialize my_diamond and print to file
    my_diamond.defineSize();
    my_diamond.defineFill();
    
    if (my_diamond.getIsFilled() == true){
	  fout << "Filled Diamond of size " << my_diamond.getSize() << ": \n" << endl;
      my_diamond.printFilledShape(fout);
    } else {
	  fout << "Hollow Diamond of size " << my_diamond.getSize() << ": \n" << endl;
      my_diamond.printHollowShape(fout);
    }
    
    // initialize my_pyramid and print to file
    my_pyramid.defineSize();
    my_pyramid.defineFill();
    
    if (my_pyramid.getIsFilled() == true){
	  fout << "Filled Pyramid of size " << my_pyramid.getSize() << ": \n" << endl;
      my_pyramid.printFilledShape(fout);
    } else {
	  fout << "Hollow Pyramid of size " << my_pyramid.getSize() << ": \n" << endl;
      my_pyramid.printHollowShape(fout);
    }

    // initialize my_triangle and print to file
    my_triangle.defineSize();
    my_triangle.defineFill();
    
    if (my_triangle.getIsFilled() == true){
	  fout << "Filled Triangle of size " << my_triangle.getSize() << ": \n" << endl;
      my_triangle.printFilledShape(fout);
    } else {
	  fout << "Hollow Triangle of size " << my_triangle.getSize() << ": \n" << endl;
      my_triangle.printHollowShape(fout);
    }

    fout.close();   
	
	return 0;
}
