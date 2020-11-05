#include <string>
#pragma once

class Base
{
public:
	Base();
	~Base();
	void ReturnName();

private:
	std::string name;
};

class Point: public Base
{
public:
	Point();
	Point(int x, int y);
	Point(Point* p);
	~Point();
	void SetPoint(int x, int y);
	void Move(int dx, int dy);

private:
	int x, y;
};

class Point3D: public Point
{
public:
	Point3D();
	Point3D(int x, int y, int z);
	Point3D(Point3D* p);
	~Point3D();
	void SetPoint(int x, int y, int z);
	void Move(int dx, int dy, int dz);

private:
	int z;
};

class Circle: public Base
{
public:
	Circle();
	Circle(int r, Point* p);
	~Circle();
	void Draw();

private:
	double R;
	Point* centre;
};

