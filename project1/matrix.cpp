#include"matrix.h"

void Matrix::printData(){
	for(int y = 0;y != height;y++){
		for(int x=0;x != width; x ++){
			std::cout << data[y*width + x] << "\t" ;
		}
		std::cout << std::endl;	
	}
}

Matrix Matrix::operator*(const Matrix& m){
	if(width!=m.height){
		std::cout<< "can not Multiply" << std::endl;
		Matrix mx;
		return mx;
	}
	
	int newMatrixHeight = height;
	int newMatrixWidth = m.width;
	double* newMatrixData= new double[newMatrixHeight * newMatrixWidth];

	for(int i =0 ; i!= newMatrixHeight* newMatrixWidth ; i++){
		newMatrixData[i] = 0;
	}

	for(int y = 0; y != newMatrixHeight; y ++){
		for(int x = 0;x != newMatrixWidth; x ++){
			double sum = 0;
			for(int c = 0; c != width ; c ++){
			//	sum += data[y][c] * m.data[c][x];
				sum += data[y*width+ c] * m.data[c* m.width+ x];
			}
			newMatrixData[y*newMatrixWidth+ x] = sum;
		}
	}
	Matrix mulResult(newMatrixWidth, newMatrixHeight, newMatrixData);
	delete[] newMatrixData;
	return mulResult;
}

Matrix Matrix::operator*(int n){
	Matrix newMatrix(*this);
	for(int i = 0; i != width * height; i ++){
		newMatrix.data[i]*=n;
	}
	return newMatrix;
}

double Matrix::dotProductionWith(const Matrix& m){
	double result= 0;
	for(int i = 0;i != width*height; i++){
		result+=data[i]; 
	}		
	return result;
} 

double & Matrix::dataAt(int x, int y){
	return data[y*width+x];
}

Matrix inverse(){
	
}






