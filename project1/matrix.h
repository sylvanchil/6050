/*
 *congq@g.clemson.edu
 */


#ifndef _MATRIX_H_
#define _MATRIX_H_

#include<vector>
#include<iostream>
#include<cstring>

class Matrix{
public:

	Matrix():width(0),height(0),data(new double[0]){
	}
	Matrix(int w, int h,double* d):width(w),height(h),data(new double[w*h]){
		memcpy(data, d, w*h* sizeof(double));
	}
	Matrix(const Matrix& m): width(m.width), height(m.height), data(new double[width*height]){
		memcpy(data, m.data, width* height* sizeof(double));
	}

	~Matrix(){
		delete[] data;
	}
	
	void printData();
	Matrix& operator=(const Matrix& m){
		if(&m == this){
		return *this;
		}
		delete[] data;
		width = m.width;
		height= m.height;
		data = new double[width*height];

		memcpy(data, m.data, width* height* sizeof(double));
		return *this;
	}
	Matrix operator*(const Matrix& m);
	Matrix operator*(int n);
	Matrix operator+(const Matrix& m);
	double dotProductionWith(const Matrix& m);

	Matrix inverse();

	double & dataAt(int x, int y);
	void setDataAt(int x, int y, double e){
		data[y*width+x] = e;
	}
	
private:
	int width;
	int height;
	double* data;

};

#endif 
