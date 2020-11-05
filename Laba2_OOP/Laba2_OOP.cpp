#include <string>
#include "Laba2_OOP.h"
using namespace std;

//класс Base

Base::Base() {
	printf("Base::Base()\n");
	name = "Base";
}

Base::~Base() {
	printf("Base::~Base()\n");
}

string Base::ReturnName() {
	return(name);
}

//класс Point

Point::Point() {
	printf("Point::Point()\n");
	x = 0;
	y = 0;
	Base::name = "Point";
}

Point::Point(int _x, int _y) {
	printf("Point::Point(int x, int y)\n");
	x = _x;
	y = _y;
	Base::name = "Point";
}

Point::Point(Point* p) {
	printf("Point::Point(point* p)\n");
	x = p->x;
	y = p->y;
	Base::name = "Point";
}
Point::~Point() {
	printf("Point::~Point()\n");
}

void Point::SetPoint(int _x, int _y) {
	x = _x;
	y = _y;
	printf("Point is now at (%i, %i)\n", x, y);
}

void Point::Move(int dx, int dy) {
	x += dx;
	y += dy;
	printf("Point moved to (%i, %i)\n", x, y);
}

void Point::ShowLocation() {
	printf("Point is at (%i, %i)\n", x, y);
}

int* Point::ReturnCoordinates() {
	int coord[2];
	coord[0] = x;
	coord[1] = y;
	return coord;
}

//класс Point3D

Point3D::Point3D(): Point() {
	printf("Point3D::Point3D()\n");
	z = 0;
	Base::name = "Point3D";
}

Point3D::Point3D(int _x, int _y, int _z): Point(_x, _y) {
	printf("Point3D::Point3D(int _x, int _y, int _z)\n");
	z = _z;
	Base::name = "Point3D";
}

Point3D::Point3D(Point3D* p): Point(p) {
	printf("Point3D::Point3D(Point3D* p)\n");
	z = p->z;
	Base::name = "Point3D";
}

Point3D::~Point3D() {
	printf("Point3D::~Point3D()\n");
}

void Point3D::SetPoint(int _x, int _y, int _z) {
	Point::SetPoint(_x, _y);
	z = _z;
}

void Point3D::Move(int dx, int dy, int dz) {
	Point::Move(dx, dy);
	z += dz;
}

void Point3D::ShowLocation() {
	printf("Point is at (%i, %i, %i)\n", x, y, z);
}


//класс Circle

Circle::Circle() {
	centre = new Point();
	r = 0;
	Base::name = "Cirlce";
}

Circle::Circle(int _r, Point* p) {
	centre = new Point(p);
	r = _r;
	Base::name = "Cirlce";
}

Circle::Circle(Circle* c) {
	centre = new Point(c->centre);
	r = c->r;
	Base::name = "Cirlce";
}

Circle::~Circle() {
	printf("Circle::~Circle()");
}

void Circle::Draw() {
	int* coord = centre->ReturnCoordinates();
	printf("Drawing circle at (%i, %i) with radius = %f", coord[0], coord[1], r);
}