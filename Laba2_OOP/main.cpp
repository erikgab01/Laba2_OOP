#include <iostream>
#include <string>
#include "Laba2_OOP.h"
using namespace std;

int main()
{
    Point* p1 = new Point(1, 2);
    Point* p2 = new Point();
    Point* p3 = new Point(p1);

    p1->ShowLocation();
    p2->ShowLocation();
    p3->ShowLocation();
}
