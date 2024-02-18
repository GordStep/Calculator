#include <iostream>
#include <string>
using namespace std;
static const double pi = 3.14159265358979323846;

void print(int a, int b, string oper, float answ)
{
	cout << a << ' ' << oper << ' ' << b << " = " << answ << endl;
}

int getLen(int a)
{
	int res = 0;

	while (a > 0)
	{
		res++;
		a /= 10;
	}
	return res;
}

int getInt(string task, int ind_s)
{
	int res = 0;
	for (int i = ind_s; i < task.size(); i++)
	{
		if (task[i] == ' ')
			i++;
		if ( task[i] >= '0' && task[i] <= '9')
		{
			res *= 10;
			res += task[i] - '0';
		}
		else
			break;
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите пример: ";
	string task, oper = "";
	getline(cin, task);
	int a = 1, b = 0;
	a = getInt(task, 0);

	cout << a << endl;

	int ind = 0;
	for (ind = getLen(a); ind < task.size(); ind++)
	{
		if (task[ind] == ' ')
			ind++;
		if (task[ind] < '0' || task[ind] > '9')
			oper += task[ind];
		else
			break;
	}
	cout << oper << endl;
	b = getInt(task, ind);
	cout << b << endl;

	try
	{
		if (oper == "/" && b == 0)
		{
			throw "Деление на 0";
		}
		if (oper == "+")
		{
			print(a, b, oper, a + b);
			return 0;
		}
		else if (oper == "-")
		{
			print(a, b, oper, a - b);
			return 0;
		}
		else if (oper == "*")
		{
			print(a, b, oper, a * b);
			return 0;
		}
		else if (oper == "/")
		{
			print(a, b, oper, float(a) / float (b));
			return 0;
		}
		else if (oper == "sin")
		{
			if (a == 0)
				a = 1;
			print(a, b, oper, a * sin(b * pi / 180.0));
			return 0;
		}
		else if (oper == "cos")
		{
			if (a == 0)
				a = 1;
			print(a, b, oper, a * cos(b * pi / 180.0));
			return 0;
		}
		else
		{
			throw "Неправильная операция";
		}
	}
	catch (const char * ex)
	{
		cout << ex << endl;
	}
	

	return 0;
}
