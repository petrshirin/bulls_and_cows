// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "pch.h"
#include <ctime>
#include <iostream>

using namespace std;


int create_number() {
	int num, digit, number = 0, factor = 1000, list_of_number[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	num = rand() % (10);					 //
	digit = list_of_number[num];			 //
	list_of_number[num] = list_of_number[9]; //чтобы ноль не был певым
	list_of_number[9] = digit;				 //
	number += digit * factor;				 //
	factor /= 10;							 //

	for (int i = 1; i < 4; i++) {
		srand(time(0));
		num = rand() % (10 - i);
		digit = list_of_number[num];
		list_of_number[num] = list_of_number[9 - i];
		list_of_number[9 - i] = digit;
		number += digit * factor;
		factor /= 10;
	}
	return number;
}

int main()
{

	int number, check_number, user_number, n, count_bulls, count_cows, count=0;
	bool check = true;
	number = create_number();
	//while ((number > 10000) && (number < 1000))
	//	srand(time(NULL));
	//	number = create_number(); // генерация случайного числа 
	//cout << "create_number " << number << endl;

	while (check)
	{
		count_bulls = 0;
		count_cows = 0;
		count++;
		cout << "Enter num: ";
		cin >> user_number;

		//проверяем быков
		n = user_number;
		check_number = number;
		for (int i = 0; i < 4; i++) {
			if (check_number % 10 == n % 10) {
				count_bulls++;

			}
			n = n / 10;
			check_number = check_number / 10;

		}
		//проверяем коров

		check_number = number;
		for (int i = 0; i < 4; i++) {
			n = user_number;
			for (int j = 0; j < 4; j++) {
				//проверка на то чтобы быки не были коровами
				if ((n % 10 == check_number % 10) && (i != j))
					count_cows++;
				n = n / 10;
			}
			check_number = check_number / 10;

		}

		if (count_bulls == 4) {
			if (count < 4)
				cout << "You are lucky!";
			if (count < 6)
				cout << "Well done";
			if (count < 9)
				cout << "Good:)";
			else
				cout << "You should practice" << endl;
			cout << number << endl;
			check = false;
			return 0;
		}
		else {
			cout << "count bulls: " << count_bulls << endl;
			cout << "count cows: " << count_cows << endl;
		}
	}
}