// Compulsory 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

long int factorial(long int number) {
	
	cout << "before" << number << "\n";
	if (number == 0) {
		return 1;
		//factorial of 0 is 1... don't ask me why. Someone smarter than me could explain it. (too lazy to google it at 4 AM)
	}
	else {
		number = number * factorial(number - 1);
		//because a factorial n! = n*(n-1)*(n-2)*(n-3).... we can have it be recursive and just subtract 1 from the number we're multiplying the number with.
		//it will do so until it reaches 0, then it returns 1 and it starts multiplying instead of creating more recursiveness.
		cout << "after" << number << "\n";
	}

	return number;
}

int polynomial() {
	return 0;
}

int calculator() {
	return 0;
}


int main()
{
	cout << "Calculator program.\nPlease input number to select an option.\n 1: Factorial \n 2: Polynomial \n 3: Simple math equations \n 4: Exit\n";
	int select;
	cin >> select;
	if (!cin) { cout << "Woops!"; return 0; }
	switch (select) {
		case 1:
			long int input;
			cout << "Please input an integer below 13:\n";
			cin >> input;
			if (input > 12 || factorial(input) == 0) { 
				cout << "Number too big!";
				//12 is the cutoff point for where the answer would cause an overflow. I tried using long integers, but for some reason it keeps overflowing
				//like a 32-bit integer. if you know why, please comment.
				return 0;
			}
			cout << factorial(input);
			break;
		case 2:
			long inputa;
			cout << "Please input an integer:\n";
			cin >> input;
			cout << factorial(input);
			polynomial();
			break;
		case 3:
			calculator();
			break;
		case 4:
			return 0;
	}
}