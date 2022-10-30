#include <iostream>
#include <stdio.h>
#include <string>
#include <regex>
#include <deque>

using namespace std;

int value(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;

	return -1;
}

int romanToDecimal(string &str)
{

	int res = 0;

	for (int i = 0; i < str.length(); i++)
	{

		int s1 = value(str[i]);

		if (i + 1 < str.length())
		{

			int s2 = value(str[i + 1]);

			if (s1 >= s2)
			{

				res = res + s1;
			}
			else
			{

				res = res + s2 - s1;
				i++;
			}
		}
		else
		{
			res = res + s1;
		}
	}
	return res;
}

string integer_to_Roman(int n)
{

	string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	string result = "";

	for (int i = 0; i < 13; ++i)
	{
		while (n - values[i] >= 0)
		{
			result += str_romans[i];
			n -= values[i];
		}
	}

	return result;
}

int main()
{

	string currentInput;
	string currentAction;

	deque<int> numbers;
	deque<string> actions;
	int result = 0;
	regex romanNumber("^(C|C|C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");

	while (currentInput != "exit" && currentAction != "exit")
	{
		cout << "Enter number" << endl;
		getline(cin, currentInput);
		if (regex_match(currentInput, romanNumber))
		{
			int arabic = romanToDecimal(currentInput);
			numbers.push_back(arabic);
			// cout << "roman " << currentInput << " in arabic = " << arabic << endl;
		}
		else
		{
			cout << "incorrect input " << currentInput << endl;
			continue;
		}

	action:
		cout << "Enter Action" << endl;
		getline(cin, currentAction);

		if (currentAction == "-" || currentAction == "+" || currentAction == "/" || currentAction == "*")
		{
			actions.push_back(currentAction);
		}
		else
		{
			if (currentAction == "exit")
			{
				break;
			}
			cout << "( -+*/ ) incorrect input " << currentAction << endl;
			goto action;
		}
	}

	result = numbers.front();
	numbers.pop_front();
	for (const int i : numbers)
	{
		string action = actions.front();
		actions.pop_front();
		if (action == "+")
		{
			result += i;
		}
		else if (action == "-")
		{
			result -= i;
		}
		else if (action == "*")
		{
			result *= i;
		}
		else if (action == "/")
		{
			result /= i;
		}
	}
	cout << "Result = " << integer_to_Roman(result) << "  ";
	getchar();
	return 0;
}