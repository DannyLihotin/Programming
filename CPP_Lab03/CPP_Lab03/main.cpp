/* ПРОСТОЙ ПРИМЕР

#include <iostream>

// 1.
// int hello(int);


int hello(int)
// 4.
{
	return 0;
}

// 2.
int main()
{
	int result = hello(5);
	std::cout << result;
	return 0; 
}

// Ошибка заключается в том, что мы объявили, но не определили функцию hello.
// Поэтому я определил функцию, добавив одну единственную строку и теперь программа заработала.
*/