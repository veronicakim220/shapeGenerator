//*********************************************
// Student Name: Ji Won (Veronica) Kim
// Student Number: 20539908
//
// SYDE 121 Lab: 10 Assignment: 1
//
// Filename: shape.cpp
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

using namespace std;

Shape::Shape():shape_type(SQUARE)
{
}

Shape::Shape(Shape_Type s):shape_type(s)
{
}

void Shape::defineSize()
{
	int size;
	do{
		cout << "Enter dimension of square." << endl;
	   	cout << "Must be an even number between 0 and 20. ";
	   	cin >> size;
	   	cout << endl;

   	}while( size % 2 == 1 || size < 2 || size > 20 );
		
	cout << endl << "Selected size is: " << size << endl << endl;
	
	setSize(size);
}

void Shape::defineFill()
{
	cout << "Enter the fill type. (0 = hollow, 1 = solid fill): ";
	cin >> isFilled;
	cout << endl << endl;
}

int Shape::getSize()
{
	return shape_size;
}

void Shape::setSize(int s)
{
	shape_size = s;
}

void Shape::printFilledShape(ofstream &out_stream)
{
		for (int i = 1; i <= getSize(); i++){
			for(int j = 1; j <= getSize(); j++)
				out_stream << "*";
			out_stream << endl;
		}
		out_stream << endl << endl;
}

void Shape::printHollowShape(ofstream &out_stream)
{
		int row = getSize();
		while ( row > 0 )
   		{
   	  		int column = getSize();

      		while ( column > 0 )
      		{
      	 		// if row is at the very top or very bottom
         		//   or if column is at the left or right
         		//   hand side, print an asterisk
   		 		if ( row == getSize() || row == 1 ||
      					column == 1 || column == getSize() )
         			out_stream << '*';
         		else
         			out_stream << ' ';

         		--column;
      		}

      		out_stream << endl;
      		--row;
   		}	
			out_stream << endl << endl;
}

bool Shape::getIsFilled()
{
	return isFilled;
}

//Diamond

Diamond::Diamond():Shape(DIAMOND)
{
}

void Diamond::defineSize()
{
	int size;
	
	do{
		cout << "Enter dimension of diamond." << endl
			 << "Must be an odd number between 1 and 19. ";
		cin >> size;
		cout << endl;
		
	}while(size % 2 == 0|| size < 1 || size > 19);

	cout << endl << "Selected size is: " << size << endl << endl;
	
	setSize(size);
}

void Diamond::printFilledShape(ofstream &out_stream)
{
	    for (int i = -getSize()/2; i <= getSize()/2; i++){
        
        	for(int s = 1; s <= abs(i); s++){
                out_stream <<" ";        
        	}	
        
        	for(int a = 1; a <= (getSize() - 2*abs(i)); a++){
                out_stream << "*";   
        	}     
        out_stream << endl;	
		}
		out_stream << endl << endl;		
}

void Diamond::printHollowShape(ofstream &out_stream)
{
		for (int i = -getSize()/2; i <= getSize()/2; i++){
        
        	for(int s = 1; s <= abs(i); s++){
                out_stream <<" ";        
       	 	}
        
        	for(int a = 1; a <= (getSize() - 2*abs(i)); a++){
        		if ((a==1)||(a == (getSize() - 2*abs(i))))
                	out_stream << "*"; 
				else
					out_stream << " ";            
        	}     
        out_stream << endl;
        
    	}
		out_stream << endl << endl;
}


//Pyramid

Pyramid::Pyramid():Shape(PYRAMID)
{
}

void Pyramid::defineSize()
{
	int size;
	
	do{
		cout << "Enter dimension of triangle." << endl
			 << "Must be an odd number between 1 and 19. ";
		cin >> size;
		cout << endl;
		
	}while(size % 2 == 0|| size < 1 || size > 19);

	cout << endl << "Selected size is: " << size << endl << endl;
	
	setSize(size);
}

void Pyramid::printFilledShape(ofstream &out_stream)
{
		for (int i = 1; i <= ((getSize()+1)/2); i++){
			for (int j = 1; j <= (((getSize()+1)/2)-i); j++)
				out_stream << " ";
			for (int k = 1; k <= (2*i - 1); k++)
				out_stream << "*";
			out_stream << endl;
		}
		out_stream << endl << endl;

}

void Pyramid::printHollowShape(ofstream &out_stream)
{
		for (int i = 1; i <= ((getSize()+1)/2); i++){
			for (int j = 1; j <= (((getSize()+1)/2)-i); j++)
				out_stream << " ";
			for (int k = 1; k <= (2*i - 1); k++)
				if ((k==1)||(k==(2*i-1))||((2*i-1)==getSize()))
					out_stream << "*";
				else
					out_stream << " ";
			out_stream << endl;
		}	
		out_stream << endl << endl;
}

//Triangle

Triangle::Triangle():Shape(TRIANGLE)
{
}

void Triangle::defineSize()
{
	int size;
	do{
		cout << "Enter dimension of triangle." << endl;
	   	cout << "Must be an even number between 0 and 20. ";
	   	cin >> size;
	   	cout << endl;

   	}while( size % 2 == 1 || size < 2 || size > 20 );
		
	cout << endl << "Selected size is: " << size << endl << endl;
	
	setSize(size);
}

void Triangle::printFilledShape(ofstream &out_stream)
{
		for (int i = 1; i <= getSize(); i++){
			for(int j = 1; j <= getSize()-i; j++)
				out_stream << " ";
			for(int k = 1; k <= i; k++)
				out_stream << "*";
			out_stream << endl;
		}	
		out_stream << endl << endl;
}

void Triangle::printHollowShape(ofstream &out_stream)
{
		for (int i = 1; i <= getSize(); i++){
			for(int j = 1; j <= getSize()-i; j++)
				out_stream << " ";
			for(int k = 1; k <= i; k++)
				if ((k == 1) || (k == i)|| (i == getSize()))
					out_stream << "*";
				else
					out_stream << " ";
			out_stream << endl;
		}
		out_stream << endl << endl;
}
