#include <stdlib.h>
#include <iostream>

struct TwoInts // Объявляется структура TwoInts с двумся полями
{
    int a;
    int b;
};

struct StructWithArray // Объявляется структура StructWithArray с массивом из четырёх элементов и указателем типа int
{
    int arr[4];
    int* someNumber;
};

int main() 
{
    TwoInts i2 = { }; // Определяем переменную типа TwoInts и инициализируем поля переменной как нули
    i2.a = 5; // Присваиваем переменным из i2 значения 5 и 7
    i2.b = 7;

    std::cout << i2.a << std::endl; // Выводим их на экран
    std::cout << i2.b << std::endl;

    StructWithArray s = { }; // Определяем переменную типа StructWithArray, называем её s и инициализируем поля переменной как нули
    s.arr[0] = 10; // Первому элемент массива присваиваем значение 10

    StructWithArray s1 = { }; 
    s1.arr[0] = 15;

    StructWithArray* sPointer = &s; // Создаём указатель с указанием на переменную s
    sPointer->arr[0] = 20; // Изменяем подпеременную arr[0] на 20

    std::cout << s.arr[0] << std::endl; //Выводим на экран (20)
    s.arr[0] = 25; // Изменяем подпеременную arr[0] на 25
    std::cout << s.arr[0] << std::endl; //25
    sPointer->arr[0] = 30; // Изменяем подпеременную arr[0] на 30
    std::cout << s.arr[0] << std::endl; //30

    sPointer = &s1; // Теперь указатель sPointer указывает на переменную s1 дальнейшее использование sPointer будет влиять только на s1
    sPointer->arr[0] = 35; // Подпеременная arr[0] переменной s1 теперь ровняется 35
    std::cout << s.arr[0] << std::endl; // На экран выводятся значения переменных s и s1 (30 и 35)
    std::cout << s1.arr[0] << std::endl;

    StructWithArray structArray[2] = { }; // Объявляем массив типа StructWithArray
    structArray[0].arr[3] = 77; // Третьему элементу массива arr в structArray[0] присваивается значение 77
    structArray[1].someNumber = &structArray[0].arr[3]; // Указатель someNumber в structArray[1] получает значение адреса arr[3] из первого structArray
    //structArray[1].arr[3] = structArray[0].arr[1];

    sPointer = &s; //Указатель sPointer вновь указывает на переменную s
    int* pointer = &sPointer->arr[3]; //Объявляется новый указатель pointer с адресом arr[3] в s
    s.arr[3] = 72; //Присваиваем значение 72 arr[3] в s
    std::cout << *pointer; // 72

    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray)); //Заполняется память переменной нулями и константа 24
    return 0;
}