#include <iostream>
#include <string>
#include "BJ_Classes_Functions.h"
using namespace std;

//=========================================================================================================================
//Task 1. Template class Pair1 for similar data types
//=========================================================================================================================

template <typename T>
class Pair1
{
private:
	T m_num1;
	T m_num2;
public:
	Pair1(T number1, T number2) : m_num1(number1), m_num2(number2) {};
	T first() const
	{
		return m_num1;
	}

	T second() const
	{
		return m_num2;
	}
};

//=========================================================================================================================
//Task 2. Template class Pair for different data types
//=========================================================================================================================
template <typename T1, typename T2>
class Pair
{
protected:
	T1 m_num1;
	T2 m_num2;
public:
	Pair(T1 number1, T2 number2) : m_num1(number1), m_num2(number2) {}
	T1 first() const
	{
		return m_num1;
	}

	T2 second() const
	{
		return m_num2;
	}
};

//=========================================================================================================================
//Task 3. StringValuePair class for string and random type input
//=========================================================================================================================

template <typename T2>
class StringValuePair : public Pair<string, T2>
{
public:
	StringValuePair(string value1, T2 value2) : Pair<string, T2>(value1, value2) {};
};

//=========================================================================================================================
//Task 4. Creating class GenericPlayer
//=========================================================================================================================

class GenericPlayer : public Hand
{
protected:
	string m_name;
public:
	GenericPlayer(string name) : Hand(), m_name(name) {}
	virtual ~GenericPlayer() {}
	
	virtual bool IsHitting() = 0;
	
	bool IsBoosted() const
	{
		if (GetValue() > 21)
			return true;
		else
			return false;
	};

	void Bust() const
	{
		std::cout << "У игрока " << m_name << " перебор!" << std::endl;
	};
};



int main()
{
	setlocale(LC_ALL, "Russian");
	
	{
		/*
		должен производить результат:
		Pair: 6 9
		Pair: 3.4 7.8
		*/
		Pair1<int> p1(6, 9);
		cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

		const Pair1<double> p2(3.4, 7.8);
		cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}
	
	{
		/*
		должен производить следующий результат:
		Pair: 6 7.8
		Pair: 3.4 5
		*/
		Pair<int, double> p1(6, 7.8);
		cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

		const Pair<double, int> p2(3.4, 5);
		cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}

	{
		/*
		должен производить следующий результат:
		Pair: Amazing 7
		*/
		StringValuePair<int> svp("Amazing", 7);
		std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	}


	return 0;
}