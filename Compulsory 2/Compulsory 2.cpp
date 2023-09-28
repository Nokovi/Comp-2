///<PropertyGroup>
///<GenerateDocumentationFile>true< / GenerateDocumentationFile>
///</ PropertyGroup>

#include <iostream>
using namespace std;

/// <summary>
/// Uses a recursive function to find the factorial of a number.
/// Because a factorial n! = n*(n-1)*(n-2)*(n-3).... we can have it be recursive and just subtract 1 from the number we're multiplying the number with.
/// it will do so until it reaches 0, then it returns 1 and it starts multiplying instead of creating more recursiveness.
/// </summary>
/// <param name="number"></param>
/// <returns></returns>
long factorial(long number) {
	
	cout << "before" << number << "\n";
	if (number == 0) {
		return 1;
		//factorial of 0 is 1... don't ask me why. Someone smarter than me could explain it. (too lazy to google it at 4 AM)
	}
	else {
		number = number * factorial(number - 1);
		cout << "after" << number << "\n";
	}

	return number;
}
/// <summary>
/// Uses the numbers from the array eq2 to either multiply, add, derivate or subtract, depending on what type user chose in main.
/// </summary>
/// <param name="eq2"></param>
/// <param name="type"></param>
/// <returns></returns>
double polynomial(double eq2[8], char type) {
	cout << "The solution is: \n";
	if (type == 'd') {
		double solution[3];
		for (int i = 0; i < 3; i++) {
			solution[2 - i] =  (3 - i) * eq2[i];
		}
		cout << solution[2] << "x^2 + " << solution[1] << "x + " << solution[0] << endl;
		return 0;
	}
	if (type == 'm') {
		double solutionComplex[7] = { 0,0,0,0,0,0,0 };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				solutionComplex[6 - i - j] += eq2[i] * eq2[4 + j]; 
				//multiplies and stores constants in an array with positions relative to their power.
			}
		}
		cout << "\n";
		//print out values:
		for (int i = 6; i > 1; i--) {
			//if statetement removes redundant addends (value equals 0). It does not remove the last constant (cx^0), because I don't want to check if everything is 0, and I also don't want it to print nothing if everything is zero.
			if (solutionComplex[i] != 0) cout << solutionComplex[i] << "x^" << i << " + ";
		}
		if (solutionComplex[1] != 0) cout << solutionComplex[1] << "x + ";
		cout << solutionComplex[0];
		return 0;
	}
	//because multiplication is a lot more complicated than addition and subtraction,
	//it can't share a printout. (it could tbf, I'm just lazy).

	double solution[4] = { 0,0,0,0 };
	if (type == 'a') {
		for (int i = 0; i < 4; i++) {
			solution[3-i] = eq2[i] + eq2[4 + i];
		}
	}
	if (type == 's') {
		for (int i = 0; i < 4; i++) {
			solution[3-i] = eq2[i] - eq2[4 + i];
		}
	}

	//printout addition and subtraction
	for (int i = 3; i > 1; i--) {
		if (solution[i] != 0) cout << solution[i] << "x^" << i << " + ";
	}
	if (solution[1] != 0) cout << solution[1] << "x + ";
	cout << solution[0] << "\n";
	return 0;
}

/// <summary>
/// prints a set of equations (+, -, *, /) using n1 and n2.
/// </summary>
/// <param name="n1"></param>
/// <param name="n2"></param>
/// <returns></returns>
int calculator(double n1, double n2) {
	//reason I'm doing all of these at once is just because I don't want to make another menu system.
	//Or make 4 different functions for these things.
	cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
	cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
	cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;
	cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
	return 0;
}

/// <summary>
/// main function. basic menu system and inputs.
/// </summary>
/// <returns></returns>
int main()
{
	cout << "Calculator program.\nPlease input number to select an option.\n 1: Factorial \n 2: Polynomial \n 3: Simple math equations \n 4: Exit\n";
	int select;
	cin >> select;
	if (!cin) { cout << "Whoops! Only input valid numbers (1-4)"; return 0;}
	//basic error handling function. It's not ideal.
	switch (select) {
		case 1:
			long input;
			cout << "Please input an integer below 13:\n";
			cin >> input;
			if (input > 12 || factorial(input) == 0 || input < 0) { 
				cout << "Number too big or invalid";
				//12 is the cutoff point for where the answer would cause an overflow. I tried using long integers, but for some reason it seems to keep overflowing
				//like a 32-bit integer. if you know why, please comment.
				return 0;
			}
			cout << factorial(input);
			break;
		case 2:
			char type;
			double eq1[8];
			cout << "This part of the program adds (a), derivates (d), subtracts (s) or multiplies (m) third grade polynomial equations. Please select one by typing the corresponding character.";
			cin >> type;
			if (type != 'a' && type != 's' && type != 'm' && type != 'd') {
				cout << "please only use a, s, or m.";
				return 0;
			}
			cout << "Please input the four constants of the first equation (ax^3 + bx^2 + cx + d)\n";
			cin >> eq1[0] >> eq1[1] >> eq1[2] >> eq1[3];
			if (!cin) {
				cout << "Oops! Please write only numbers into the equation";
				return 0;
			}
			if (type != 'd') {
				cout << "Please input the four constants of the second equation. \n";
				cin >> eq1[4] >> eq1[5] >> eq1[6] >> eq1[7];
				if (!cin) {
					cout << "Oops! Please write only numbers into the equation";
					return 0;
				}
			}
			polynomial(eq1, type);
			break;
		case 3:
			cout << "Please type out two numbers which shall be added, subtracted, multiplied and divided:" << endl;
			double n1; double n2;
			cin >> n1;
			cin >> n2;
			cout << "\n";
			calculator(n1, n2);
			break;
		case 4:
			return 0;
	}
}