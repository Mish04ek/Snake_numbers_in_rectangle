#include <iostream>
#include <string>
using namespace std;

int getValue(string line, int min = 0, int max = 100) {
	while (true) {
		cout << line << endl;
		int num;
		cin >> num;

		if (cin.fail()) {
			cout << "Invalid input!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else {
			if (num < min || num > max) {
				cout << num << " is not in range(" << min << "," << max << ")" << endl;
			}
			else return num;
		}
	}
}

string reapetedStr(string str, int value) {
	string newLine;
	for (int i = 0; i < value; i++) {
		newLine = newLine + str;
	}
	return newLine;
}

int main() {
	int rows = getValue("Enter the number of ROWS(0, 100)", 0, 100), cols = getValue("Enter the number of COLS(0, 100)", 0, 100);
	
	const int maxNum = rows * cols;
	const int maxNumLength = to_string(maxNum).size();

	cout << "Max number: " << maxNum << endl;
	cout << "Max length: " << maxNumLength << endl;


	int** array = new int*[rows];

	for (int i = 0; i < rows; ++i) {
		array[i] = new int[cols];
	}

	// filling
	int count = 1;
	int direction = 1;
	for (int i = 0; i < cols; i++) {
		//down
		if (direction == 1) {
			for (int j = 0; j < rows; j++) {
				array[j][i] = count;
				count++;
				//cout << array[j][i] << endl;
			}
			direction = -1;
		}
		//up
		else if (direction == -1) {
			for (int j = rows-1; j >= 0; j--) {
				array[j][i] = count;
				count++;
				//cout << array[j][i] << endl;
			}
			direction = 1;
		}
	}
	
	// output 
	for (int i = 0; i < rows; i++) {
		//определение/переопределение новой пустой строки
		string line;
		for (int j = 0; j < cols; j++) {
			string strNum = to_string(array[i][j]);
			string spaceLine = reapetedStr(" ", maxNumLength - strNum.size());
			//cout << maxNumLength << " " << a << " _" << spaceLine <<"_"<< strNum<< endl;
			line = line + " " + spaceLine + strNum;
		}
		// вывести рядок
		cout << line << endl;
	}
	
	return 0;
}
