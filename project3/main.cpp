
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <sstream>
#ifdef __APPLE__
#include <GL/glew.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <fcntl.h>
#include "Vector.h"

//todo: dont use using namespace
using namespace std;
bool loadOBJ(const char* path,
		vector<Vector3d>& vertexes,
		vector<Vector3d>& normals,
		vector<Vector2d>& tCoords,
		vector<Vector3d>& tans,
		vector<Vector3d>& biTans,
		vector<vector<Vector3d> >& faces,
		string& nameOfMtllib,
		string& nameOfMtluse
		){

	fstream fs;
	fs.open(path, fstream::in);
	
	string buffer;
	string comment;
	double x,y,z;
	int a,b,c,d;

	string delimiter = "/";
	

	int countv= 0, countvt =0,countvn=0, countvx= 0, countvy= 0, countf=0;
	while(!fs.eof()){
		//skip comments.
		if((int)'#' == fs.peek()){
			getline(fs, comment);
			cout<< comment<< endl;
			continue;
		}
		
		fs>> buffer;	
		if(buffer== "v"){
			fs>> x>>y>> z;
			vertexes.push_back(Vector3d(x,y,z));
			countv++;
		}
		else 
		if(buffer== "vt"){
			fs>>x >>y;
			tCoords.push_back(Vector2d(x,y));
			countvt++;
		}
		else 
		if(buffer== "vn"){
			fs>> x>> y>>z;
			normals.push_back(Vector3d(x,y,z));
			countvn++;
		}
		else 
		if(buffer== "vx"){
			fs>> x>> y>> z;
			tans.push_back(Vector3d(x,y,z));
			countvx++;
		}
		else 
		if(buffer== "vy"){
			fs>> x>> y>> z;
			biTans.push_back(Vector3d(x,y,z));
			countvy++;
		}
		else 
		if(buffer== "f"){
//			cout << "face" << endl;
	
			vector<Vector3d> face;
			// todo: ugly code here, need more elegant solution.
			for(int i =0;i < 4; i++){

				fs>> buffer;
				size_t pos = 0;
				if((pos = buffer.find(delimiter)) != string::npos) {
    				stringstream sa(buffer.substr(0, pos));
					sa>> a;
		    		buffer.erase(0, pos + delimiter.length());
				}

				if((pos = buffer.find(delimiter)) != string::npos) {
    				stringstream sb(buffer.substr(0, pos));
					sb>> b;
		    		buffer.erase(0, pos + delimiter.length());
				}

    				stringstream sc(buffer.substr(0, pos));
					sc>> c;
		    		buffer.erase(0, pos + delimiter.length());
				face.push_back(Vector3d(a,b,c));
			}
			faces.push_back(face);
			countf++;
		}
		else 
		if(buffer == "usemtl"){
			fs>> nameOfMtluse;
		}else
		if(buffer == "mtllib"){
			fs>> nameOfMtllib;
		}
	}
	
	cout << countv << endl;
	cout << countvt << endl;
	cout << countvn << endl;
	cout << countvx << endl;
	cout << countvy << endl;
	cout << countf << endl;
	cout << nameOfMtllib<< endl;
	cout << nameOfMtluse << endl;
	fs.close();
	return true;
}


int main(int argc, char** argv){
		vector<Vector3d> vertexes;
		vector<Vector3d> normals;
		vector<Vector2d> tCoords;
		vector<Vector3d> tans;
		vector<Vector3d> biTans;
		vector<vector<Vector3d> >faces;	
		string nameOfMtllib;
		string nameOfMtluse;
	loadOBJ(argv[1],
		vertexes,
		normals,
		tCoords,
		tans,
		biTans,
		faces,
		nameOfMtllib,
		nameOfMtluse
		);

	cout << vertexes[0];
	cout << vertexes[13007];

	

	cout << faces[13007][0];
	cout << faces[13007][1];
	cout << faces[13007][2];
	cout << faces[13007][3];

	//read file
	//read shader and use shader 
	//set texture image
	//set up enviroment
	//render scene
	return 0;
}
