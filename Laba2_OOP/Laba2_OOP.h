#include <string>
using namespace std;
#pragma once

class Base
{
public:
	Base();
	~Base();
	string ReturnName();

protected:
	string name;
};

class Point: public Base
{
public:
	Point();
	Point(int _x, int _y);
	Point(Point* p);
	~Point();
	void ShowLocation();
	int* ReturnCoordinates();
	void SetPoint(int _x, int _y);
	void Move(int dx, int dy);

protected:
	int x, y;
};

class Point3D: public Point
{
public:
	Point3D();
	Point3D(int _x, int _y, int _z);
	Point3D(Point3D* p);
	~Point3D();
	void ShowLocation();
	void SetPoint(int _x, int _y, int _z);
	void Move(int dx, int dy, int dz);

private:
	int z;
};

class Circle: public Base
{
public:
	Circle();
	Circle(int _r, Point* p);
	Circle(Circle* c);
	~Circle();
	void Draw();

private:
	double r;
	Point* centre;
};

