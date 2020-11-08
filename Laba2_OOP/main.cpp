#include <iostream>
#include <string>
#include "Laba2_OOP.h"
#include <ctime>
#include <conio.h>
using namespace std;

//Вызов конструктов и деструктуров различных классов
void func1() 
{
    printf("Создаём объект класса Base:\n");
    Base* b = new Base();
    printf("Создаём объект класса Point:\n");
    Point* p = new Point();
    printf("Создаём объект класса Point3D:\n");
    Point3D* p3d = new Point3D();
    printf("Создаём объект класса Circle:\n");
    Circle* c = new Circle();
    printf("\n");
    printf("Уничтожаем объект класса Base:\n");
    delete b;
    printf("Уничтожаем объект класса Point:\n");
    delete p;
    printf("Уничтожаем объект класса Point3D:\n");
    delete p3d;
    printf("Уничтожаем объект класса Circle:\n");
    delete c;

    _getch();
}

//Помещаем потомков в родительский класс и вызываем метод
void func2()
{
    Base* bArray[10];
    srand(time(0));
    for (int i = 0; i < 10; i++) 
    {
        int rnd = rand() % 3;
        switch (rnd)
        {
        case 0:
            bArray[i] = new Point();
            break;
        case 1:
            bArray[i] = new Point3D();
            break;
        case 2:
            bArray[i] = new Circle();
            break;
        default:
            break;
        }
    }
    printf("\n");
    for (int i = 0; i < 10; i++) 
    {
        cout << bArray[i]->ReturnName() << endl;
    }

    _getch();
}

//Методы класса Circle
void func3()
{
    int x1, y1, x2, y2, r;
    cout << "Введите центр окружности: ";
    cin >> x1 >> y1;
    cout << "Введите радиус окружности: ";
    cin >> r;
    cout << "Введите координаты точки: ";
    cin >> x2 >> y2;
    printf("\n");
    Point centre(x1, y1);
    Circle c(r, &centre);

    Point p(x2, y2);
    printf("\n");
    c.Draw();
    c.IsPointInCircle(&p);
    printf("\n");

    _getch();
}

//Методы классов Point и Point3D
void func4() 
{
    Point* p = new Point(5, 5);
    Point3D* p3d1 = new Point3D(1, 2, 3);
    Point3D* p3d2 = new Point3D(p3d1);

    int dx = 10, dy = 6, dz = 9;

    printf("\n");

    printf("Старые координаты точек:\n");
    p->ShowLocation();
    p3d1->ShowLocation();
    p3d2->ShowLocation();

    printf("\n");

    p->Move(dx, dy);
    p3d1->Move(dx, dy, dz);
    p3d2->SetPoint(75, 30, 20);

    printf("Новые координаты точек:\n");
    p->ShowLocation();
    p3d1->ShowLocation();
    p3d2->ShowLocation();

    _getch();
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int flag = 1;
    int digit;

label:

    system("cls");

    printf("1 - Вызов конструктов и деструктуров различных классов\n");
    printf("2 - Помещаем потомков в родительский класс и вызываем метод\n");
    printf("3 - Методы класса Circle\n");
    printf("4 - Методы классов Point и Point3D\n");
    printf("0 - Завершение программы\n");
    printf("\nВведите цифру: ");
    cin >> digit;

    switch (digit)
    {
    case 1:
        system("cls");
        func1();
        break;
    case 2:
        system("cls");
        func2();
        break;
    case 3:
        system("cls");
        func3();
        break;
    case 4:
        system("cls");
        func4();
        break;
    case 0:
        flag = 0;
        break;
    default:
        break;
    }

    if (flag)
        goto label;

    return 0;
}
