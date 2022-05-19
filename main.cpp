#include <iostream>
#include <string>

//=========================================================================================================================
//Task 1. Student class
//=========================================================================================================================

class Person
{
protected:
	std::string _name;
	uint16_t _age;
	std::string _gender;
	uint16_t _weight;
public:
	Person(std::string name, uint16_t age, std::string gender, uint16_t weight) : _name(name), _age(age), _gender(gender), _weight(weight) {}
	
	void setName(std::string name)
	{
		_name = name;
	}

	void setAge(uint16_t age)
	{
		_age = age;
	}

	void setWeight(uint16_t weight)
	{
		_weight = weight;
	}
};

class Student : public Person
{
private:
	static uint16_t studentCount;
protected:
	uint16_t _stYear;
	friend void print(Student& s);
public:
	Student(std::string name, uint16_t age, std::string gender, uint16_t weight, uint16_t stYear = 1) : Person(name, age, gender, weight), _stYear(stYear) { std::cout << "Всего студентов: " << ++studentCount << std::endl; }

	void setStudyYear(uint16_t year)
	{
		_stYear = year;
	}

	void incYear()
	{
		_stYear++;
	}
};

void print(Student &s)
{
	std::cout << s._name << "/" << s._gender << "/" << s._age << " лет/" << s._stYear << " год обучения" << std::endl;
}

uint16_t Student::studentCount = 0;

//=========================================================================================================================
//Task 2. Apples
//=========================================================================================================================

/*
- Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
- У Fruit есть две переменные-члена: name (имя) и color (цвет). 
- Добавить новый класс GrannySmith, который наследует класс Apple.
*/



int main()
{
	setlocale(LC_ALL, "Russian");
	
	{
		Student Jon("Jon", 18, "male", 80, 1);
		print(Jon);
		Student Mac("Mac", 19, "male", 90, 1);
		print(Mac);
		Student Jane("Jane", 20, "female", 70, 2);
		print(Jane);
	}

	{
		Apple a("red");
		Banana b;
		GrannySmith c;

		std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
		std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
		std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	}
	
	/*
	Код, приведенный выше, должен давать следующий результат:

	My apple is red.
	My banana is yellow.
	My Granny Smith apple is green.
	*/
	
	return 0;
}