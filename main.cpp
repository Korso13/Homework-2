#include <iostream>
#include <string>
using namespace std;

//=========================================================================================================================
//Task 1. Division by zero
//=========================================================================================================================

class DivisionByZero
{
	std::string error;
public:
	DivisionByZero(std::string description) :  error(description) {}
	~DivisionByZero() {}

	void what() const noexcept
	{
		std::cerr << "\nDivisionByZero exception! " << error << std::endl;
		return;
	}
};

template <class N, class D>
double div(N n, D d)
{
	if (d == 0)
		throw DivisionByZero("Denominator cant be zero");
	else
		return (n / d);
}

//=========================================================================================================================
//Task 2. Bar and Ex exceptions
//=========================================================================================================================

class Ex
{
public:
	Ex(double _x) : x(_x) {}
	~Ex() {}
	double x;
};

class Bar
{
private:
	double y;
public:
	Bar(double _y = 0.0) : y(_y) {}
	~Bar() {}
	double set(double a)
	{
		if ((y + a) > 100)
			throw Ex(a * y);
		else
			y = a;
	}
};

//=========================================================================================================================
//Task 3. Driving robot, hitting walls
//=========================================================================================================================

class IllegalCommand
{
private:
	std::string errMessage;
	int posY, posX, moveY, moveX;
public:
	IllegalCommand(std::string descr, int y, int x, int _y, int _x) : errMessage(descr), posY(y), posX(x), moveY(_y), moveX(_x) {}
	~IllegalCommand() {}
	void const what() noexcept
	{
		std::cerr << std::endl << errMessage;
		std::cerr << "\nRobot's position was X:" << (posX + 1) << " Y:" << (posY + 1);
		std::cerr << "\nRobot was ordered to move to coordinates X:" << (posX + moveX + 1) << " and Y:" << (posY + moveY + 1);
		std::cerr << "\nRobot does not support diagonal movement!" << std::endl;
		return;
	}
};

class OffTheField 
{
private:
	std::string errMessage;
	int posY, posX, moveY, moveX;
public:
	OffTheField(std::string descr, int y, int x, int _y, int _x) : errMessage(descr), posY(y), posX(x), moveY(_y), moveX(_x) {}
	~OffTheField() {}

	void const what() noexcept 
	{
		std::cerr << std::endl << errMessage;
		std::cerr << "\nRobot's position was X:" << (posX + 1) << " Y:" << (posY + 1);
		std::cerr << "\nRobot was ordered to move ";
		if (moveX < 0)
			std::cerr << "left to coordinates X : " << (posX + moveX + 1) << " and Y : " << (posY + moveY + 1);
		else if(moveX > 0)
			std::cerr << "right to coordinatesX : " << (posX + moveX + 1) << " and Y : " << (posY + moveY + 1);
		else if (moveY < 0)
			std::cerr << "up to coordinatesX : " << (posX + moveX + 1) << " and Y : " << (posY + moveY + 1);
		else
			std::cerr << "down to coordinatesX : " << (posX + moveX + 1) << " and Y : " << (posY + moveY + 1);
		std::cerr << "\nRobot can't move out of field's bounds!" << std::endl;
		return;
	}

};

class Robot
{
private:
	int x{ 0 };
	int y{ 0 };
	bool field[10][10];
public:
	Robot() : field{false} {
		x = 4;
		y = 4;
		field[y][x] = true;
	}
	~Robot() {}
	void Move(int _x, int _y)  //params - how far should robot move on x y grid (relative movement)
	{
		if ((_x > 0) && (_y > 0)) //robot moves diagonally 
			throw IllegalCommand("Incorrect movement command - wrong direction!", y, x, _y, _x);
		if ((x + _x) > 9 || (x + _x) < 0 || (y + _y) > 9 || (y + _y) < 0)
			throw OffTheField("Incorrect command - out of field's bounds!", y, x, _y, _x);
		else
		{
			field[y][x] = false;
			x = x + _x;
			y = y + _y;
			field[y][x] = true;
		}
		print();
	}

	void print()
	{
		std::cout << std::endl << "X   1   2   3   4   5   6   7   8   9   10   " << std::endl;
		std::cout << "Y___________________________________________" << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << (i + 1);
			if(i != 9) 
				std::cout << " |";
			else
				std::cout << "|";
			for (size_t k = 0; k < 10; k++)
			{
				if (field[i][k] == true)
					std::cout << " X |";
				else
					std::cout << "   |";
			}
			std::cout << std::endl << "____________________________________________" << std::endl;
		}
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");
	//=========================================================================================================================
	//Task 1. Division by zero
	//=========================================================================================================================
	std::cout << "Task 1" << std::endl << std::endl;
	try
	{
		std::cout << "Результат деления 15 на 3.5: "; 
		std::cout << div<int, double>(15, 3.5) << std::endl;
		std::cout << "Результат деления 13 на 0: ";
		std::cout << div<int, int>(15, 0) << std::endl;
	}
	catch (DivisionByZero errstr)
	{
		errstr.what();
	}

	//=========================================================================================================================
	//Task 2. Bar and Ex exceptions
	//=========================================================================================================================

	std::cout << "Task 2" << std::endl << std::endl;
	Bar bar1;
	int n{ 1 };
	try
	{
		do
		{
			std::cin >> n;
			bar1.set(n);
		} while (n != 0);
	}
	catch (Ex error) { std::cerr << "Ex exception " << showpoint << error.x << std::endl; }
	

	//=========================================================================================================================
	//Task 3. Driving robot, hitting walls
	//=========================================================================================================================
	std::cout << "Task 3" << std::endl << std::endl;

	try
	{
		Robot robot1;
		robot1.print();
		int x, y;
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << "На сколько переместить робота по оси Х? ";
			std::cin >> x;
			std::cout << "На сколько переместить робота по оси Y? ";
			std::cin >> y;
			robot1.Move(x, y);
		}
	}
	catch (IllegalCommand err1)
	{
		err1.what();
	}
	catch (OffTheField err2)
	{
		err2.what();
	}
	catch (...) { std::cerr << "\nUnidentified exception" << std::endl; }

	std::cout << "Program sucsesfully closes!" << std::endl;
	return 0;
}