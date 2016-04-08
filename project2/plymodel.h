#ifndef PLYMODEL_H
#define PLYMODEL_H

#include<cmath>
#include<cstdio>
#include<GL/gl.h>
#include<GL/glut.h>


class PLYModel{
public:
	void draw();
	GLfloat* vertexes;
	GLint* faces;


}
