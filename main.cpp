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
//Task 2. Fruits classes
//=========================================================================================================================

class Fruit
{
protected:
	std::string fName;
	std::string fColour;
public:
	Fruit(std::string Colour, std::string Name) : fName(Name), fColour(Colour) {}
	
	std::string getName()
	{
		return fName;
	}

	std::string getColor()
	{
		return fColour;
	}
};

class Apple : public Fruit
{
public:
	Apple(std::string Colour = "green", std::string Name = "apple") : Fruit(Colour, Name) {}
};

class Banana : public Fruit
{
public:
	Banana(std::string Colour = "yellow", std::string Name = "banana") : Fruit(Colour, Name) {}
};

class GrannySmith : public Apple
{
public:
	GrannySmith(std::string Colour = "green", std::string Name = "Granny Smith apple") : Apple(Colour, Name) {}
};

//=========================================================================================================================
//Task 3. Blackjack game code ideas
//=========================================================================================================================




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

	std::cout << std::endl;

	{
		Apple a("red");
		Banana b;
		GrannySmith c;

		std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
		std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
		std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	}
	
	return 0;
}