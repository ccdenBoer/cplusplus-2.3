// week1.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int SIZE = 4;
double sumColumn(const double m[][SIZE], int rowSize, int columnIndex);

int main()
{
	const double matrix[3][SIZE] = { {1.5, 2, 3, 4},{5.5, 6, 7, 8},{9.5, 1, 3, 1} };

	std::cout << "Sum of the elements at column 0 is " << sumColumn(matrix, 3, 0) << "\n";
	std::cout << "Sum of the elements at column 1 is " << sumColumn(matrix, 3, 1) << "\n";
	std::cout << "Sum of the elements at column 2 is " << sumColumn(matrix, 3, 2) << "\n";
	std::cout << "Sum of the elements at column 3 is " << sumColumn(matrix, 3, 3) << "\n";

}

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex) {
	double sum = 0;
	for (int i = 0; i < rowSize; i++) {
		sum += m[i][columnIndex];
	}

	return sum;
}

