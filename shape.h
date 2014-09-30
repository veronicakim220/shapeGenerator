//*********************************************
// Student Name: Ji Won (Veronica) Kim
// Student Number: 20539908
//
// SYDE 121 Lab: 10 Assignment: 1
//
// Filename: shape.h
// Date submitted: November Sat. 30th Nov 2013
//
// I hereby declare that this code, submitted
// for credit for the course SYDE121, is a product
// of my own efforts. This coded solution has
// not been plagiarized from other sources and
// as not been knowingly plagiarized by others.
//
//*********************************************

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <fstream>

using namespace std;

enum Shape_Type{SQUARE, DIAMOND, PYRAMID, TRIANGLE};

class Shape
{
	public:
		Shape();
		// set square as the default
		Shape(Shape_Type s);
		// takes in s and sets it to shape_type
		void defineSize();
		// prompts the user to enter the size of the shape
		// default = square; ask for positive num btw 0-20
		void defineFill();
		// prompts the user to enter a fill type for printing the shape
		// isFilled is set to true of false
		// o = hollow = false, 1 = fill = true;
		int getSize();
		// accessor function that returns shape_size
		void setSize(int s);
		// mutator function that sets the value of shape_size	
		void printFilledShape(ofstream &out_stream);
		// prints out hollow solid of shape_size
		// default = square
		void printHollowShape(ofstream &out_stream);
		// prints out hollow solid of shape_size
		// default = square
		bool getIsFilled();
		// returns bool value of isFilled
		
	private:
		Shape_Type shape_type;
		int shape_size;
		bool isFilled;
		
};

class Square: public Shape
{
};

class Diamond: public Shape
{
	public:
		Diamond();
		void defineSize();
		void printFilledShape(ofstream &out_stream);
		void printHollowShape(ofstream &out_stream);
};

class Pyramid: public Shape
{
	public:
		Pyramid();
		void defineSize();
		void printFilledShape(ofstream &outstream);
		void printHollowShape(ofstream &outstream);
};

class Triangle: public Shape
{
	public:
		Triangle();
		void defineSize();
		void printFilledShape(ofstream &outstream);
		void printHollowShape(ofstream &outstream);
};

#endif
