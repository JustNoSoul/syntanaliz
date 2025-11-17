#include "MainClass.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



int main()
{
	MainClass analysis;
	analysis.load();
	while (1) {
		char n;
		cout << "\nWhat do you want to check?" << endl;
		cout << "1 - To check 'break'" << endl;
		cout << "2 - To check '(){}'" << endl;
		cout << "3 - To output the code '(){}'" << endl;
		cout << "4 - To exit" << endl;
		n = _getch();
		switch (n) {
		case '1':
		{
			system("cls");
			int l = 0;
			int k = 0;
			analysis.forbreak();
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case '2':
		{
			system("cls");
			if(analysis.checkskob())
				cout << "Vse ok ";
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case '3':
		{
			system("cls");
			analysis.vivod();
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case '4':
		{
			system("cls");
			exit(0);
		}
		}
	}
}