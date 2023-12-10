#include <iostream>
#include <string>
#include <fstream>
#include <span>
#include <sstream>
#include <vector>

// 1.
enum class Gender
{
	Male = 0,
	Female = 1,
};

struct Person
{
	std::string Name;
	int Age;
	Gender gender;
};

// 2. 

void serializeName(const Person* p, std::ostream& os)
{
	os << p->Name;
}

void serializeAge(const Person* p, std::ostream& os)
{
	os << p->Age;
}

enum class GenderSerializationOption
{
	String,
	Char,
	Number,
};

void serializeGender(const Person* p, std::ostream& os, GenderSerializationOption option = GenderSerializationOption::String)
{
	switch (option)
	{
	case GenderSerializationOption::String:
	{
		switch (p->gender)
		{
		case Gender::Male:
			os << "Male";
			break;
		case Gender::Female:
			os << "Female";
			break;
		}
	}
	case GenderSerializationOption::Char:
	{
		switch (p->gender)
		{
		case Gender::Male:
			os << 'M';
			break;
		case Gender::Female:
			os << 'F';
			break;
		}
	}
	case GenderSerializationOption::Number:
	{
		int genderAsNumber = static_cast<int>(p->gender);
		os << genderAsNumber;
	}
	}
}

// 3.
void serializePerson(const Person* p, std::ostream& os, GenderSerializationOption option)
{
	serializeName(p, os);
	os << ",";
	serializeAge(p, os);
	os << ",";
	serializeGender(p, os, option);
}

// 4.
std::string deserializeName(std::istream& input)
{
	std::string name;
	std::getline(input, name, ',');
	return name;
}

int deserializeAge(std::istream& input)
{
	std::string ageStr;
	std::getline(input, ageStr, ',');

	try
	{
		return std::stoi(ageStr);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Неверный формат ввода";
		return 0; 
	}
}

Gender deserializeGender(std::istream& input, GenderSerializationOption option)
{
	std::string genderStr;
	std::getline(input, genderStr, ',');

	switch (option)
	{
	case GenderSerializationOption::String:
		if (genderStr == "Male")
			return Gender::Male;
		else if (genderStr == "Female")
			return Gender::Female;
		break;

	case GenderSerializationOption::Char:
		if (!genderStr.empty())
		{
			char genderChar = genderStr[0];
			switch (genderChar)
			{
			case 'M':
				return Gender::Male;
			case 'F':
				return Gender::Female;
			}
		}
		break;

	case GenderSerializationOption::Number:
		try
		{
			int genderAsNumber = std::stoi(genderStr);
			return static_cast<Gender>(genderAsNumber);
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Неверный формат ввода";
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Выход за границы";
		}
		break;
	}

	return Gender::Male;
}

// 5.
void deserializePerson(Person* p, std::istream& input, GenderSerializationOption option)
{
	p->Name = deserializeName(input);
	p->Age = deserializeAge(input);
	p->gender = deserializeGender(input, option);
}

// 6. Не знаю почему, но у меня span попросту отказывался работать, всё время подчёркивал std::span и говорил, что требуется
// int, и я в общем я сделал с указателем
void serializePeopleSpan(const Person* people, size_t size, std::ostream& os, GenderSerializationOption option)
{
	for (size_t i = 0; i < size; ++i)
	{
		serializePerson(&people[i], os, option);
		os << '\n'; 
	}
}

// 7.
void deserializePeopleVector(std::istream& input, std::vector<Person>& people, GenderSerializationOption option)
{
	std::string line;
	while (std::getline(input, line))
	{
		std::istringstream iss(line);
		Person person;
		deserializePerson(&person, iss, option);
		people.push_back(person);
	}
}

// 8. Создали файл Persons.txt куда занесли данные о трёх людях: имя, возраст и пол

//9. 

void serializePeopleVector(const std::vector<Person>& people, std::ostream& output, GenderSerializationOption option)
{
	for (const auto& person : people)
	{
		serializePerson(&person, output, option);
		output << '\n';
	}
}

int main()
{
	std::ifstream inputFile("Persons.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Не удалось открыть файл для чтения" << std::endl;
		return 1;
	}

	std::vector<Person> people;
	deserializePeopleVector(inputFile, people, GenderSerializationOption::String);
	inputFile.close();

	if (!people.empty())
	{
		people[0].Age += 1; 
	}

	Person newPerson = { "David", 28, Gender::Male };
	people.push_back(newPerson);

	std::ofstream outputFile("modified_data.txt");

	// Проверка на успешное открытие файла
	if (!outputFile.is_open())
	{
		std::cerr << "Не удалось открыть файл для записи" << std::endl;
		return 1;
	}

	serializePeopleVector(people, outputFile, GenderSerializationOption::String);
	outputFile.close();

	return 0;
}
