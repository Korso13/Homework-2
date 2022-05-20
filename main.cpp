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

/*
	Игру Blackjack можно реализовать через инициализацию нескольких классов и последовательный вызов в main() дополнительных функций игровой логики, а также методов из этих классов.
	При инициализации программы у игрока будет запрошены стартовые параметры: кол-во игроков людей, а также кол-во используемых колод. На основании этой информации будет инициализирован объект класса Decks, а так же массив состоящий из объектов дочерних классов класса Player.
	Описания классов нужных для игры:
	
	Базовый класс Player будет иметь поля: 
	- private поле hand ("рука" - массив с картами игрока или крупье)
	- private поле chips (фишки доступные игроку или же "банк" в случае с крупье)
	- public метод метод GetCard();, который будет обращаться к методу переданного по ссылке объекта класса Decks и возвращать значение полученной карты
	- public метод ClearHand(); - метод для сброса руки.
	- public метод CheckHand(); который возвращает сумму значений карт в "руке"
	- public методы setChips(bet); и getChips(); для изменения кол-ва фишек при выигрыше\проигрыше, а также для возврата кол-ва имеющихся фишек.
	
	Дочерний класс Dealer основаный на Player будет иметь свой конструктор с специальной инициализацией поля chips. Объект класса Dealer будет инициализован в нулевом индексе массива игроков длинна которого будет равна кол-ву игроков указанному при запуске программы + 1.

	Дочерний класс Human Player основаный на Player будет тоже иметь отдельный конструктор, а также несколько дополнительных методов и дополнительное поле:
	- private поле bet (текущая ставка)
	- public метод SetBet (установка ставки, а также очистка этого поля после выигрыша, проигрыша)
	- public метод DoubleDown (удвоение ставки)
	(возможно в конечном вар-те будут дополнительные методы для отражения особых случаев в правилах, например "страховки")

	Базовый класс Decks имеет:
	- private поле decks. Это будет динамический двумерный массив [n][52] инициализируемый конструктором и уничтожаемый деструктором. n - равен указанному кол-ву используемых колод. 
	- private метод ResetDeck(i); который сбрасывает колоду i
	- public метод ResetAllDecks; который вызывает метод ResetDeck через цикл n раз и сбрасывает все колоды.
	- public метод DrawCard(); который по вызову от объекта класса Player (а точнее его дочерних классов) будет извлекать из поля decks карту по случайным "координатам" предварительно проверив не равна ли ячейка 0. Обнуляет успешно выбранную ячейку.

	В конце партии("шаффла"), проводится проверка полей chips у игроков и крупье (чтобы понять может ли игра продолжаться) а также выводится запрос игрокам, хотят ли они продолжать играть. При удовлетворении всех условий, игровой процесс рестартуется для нового шаффла (при необходимости вызывается метод Decks.ResetAllDecks(); )
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