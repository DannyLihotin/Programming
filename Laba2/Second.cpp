#include <stdlib.h>
#include <iostream>

struct TwoInts // ����������� ��������� TwoInts � ������ ������
{
    int a;
    int b;
};

struct StructWithArray // ����������� ��������� StructWithArray � �������� �� ������ ��������� � ���������� ���� int
{
    int arr[4];
    int* someNumber;
};

int main() 
{
    TwoInts i2 = { }; // ���������� ���������� ���� TwoInts � �������������� ���� ���������� ��� ����
    i2.a = 5; // ����������� ���������� �� i2 �������� 5 � 7
    i2.b = 7;

    std::cout << i2.a << std::endl; // ������� �� �� �����
    std::cout << i2.b << std::endl;

    StructWithArray s = { }; // ���������� ���������� ���� StructWithArray, �������� � s � �������������� ���� ���������� ��� ����
    s.arr[0] = 10; // ������� ������� ������� ����������� �������� 10

    StructWithArray s1 = { }; 
    s1.arr[0] = 15;

    StructWithArray* sPointer = &s; // ������ ��������� � ��������� �� ���������� s
    sPointer->arr[0] = 20; // �������� ������������� arr[0] �� 20

    std::cout << s.arr[0] << std::endl; //������� �� ����� (20)
    s.arr[0] = 25; // �������� ������������� arr[0] �� 25
    std::cout << s.arr[0] << std::endl; //25
    sPointer->arr[0] = 30; // �������� ������������� arr[0] �� 30
    std::cout << s.arr[0] << std::endl; //30

    sPointer = &s1; // ������ ��������� sPointer ��������� �� ���������� s1 ���������� ������������� sPointer ����� ������ ������ �� s1
    sPointer->arr[0] = 35; // ������������� arr[0] ���������� s1 ������ ��������� 35
    std::cout << s.arr[0] << std::endl; // �� ����� ��������� �������� ���������� s � s1 (30 � 35)
    std::cout << s1.arr[0] << std::endl;

    StructWithArray structArray[2] = { }; // ��������� ������ ���� StructWithArray
    structArray[0].arr[3] = 77; // �������� �������� ������� arr � structArray[0] ������������� �������� 77
    structArray[1].someNumber = &structArray[0].arr[3]; // ��������� someNumber � structArray[1] �������� �������� ������ arr[3] �� ������� structArray
    //structArray[1].arr[3] = structArray[0].arr[1];

    sPointer = &s; //��������� sPointer ����� ��������� �� ���������� s
    int* pointer = &sPointer->arr[3]; //����������� ����� ��������� pointer � ������� arr[3] � s
    s.arr[3] = 72; //����������� �������� 72 arr[3] � s
    std::cout << *pointer; // 72

    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray)); //����������� ������ ���������� ������ � ��������� 24
    return 0;
}