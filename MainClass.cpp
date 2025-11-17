#include "MainClass.h"
void MainClass::load()
{
	string a = " ();\n\t{}";
	extern HANDLE hConsole;
	FILE* file;
	int i = 0;
	char c;
	int j = 0;
	file = fopen("text", "r");
	if (file == NULL) {
		SetConsoleTextAttribute(hConsole, 20);
		cout << "File is clear or an error occuried. Restart the programm. If problem wasn't solved, check the path to the file" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		exit(0);
	}
	int k = 0;
	while ((c = getc(file)) != EOF) {
		if (a.find(c) < 9) {
			if (k == 1)
				j++;
			fullfile[j] += c;
			j++;
			k = 0;
		}
		if (a.find(c) > 9) {
			k = 1;
			fullfile[j] += c;
		}
		countforoutput++;
	}
	fullfile[0] = fullfile[0];
	fclose(file);
	for (int i = 0; i < j; i++) {
		if (fullfile[i] != " " && fullfile[i] != "" && fullfile[i] != "\t" && fullfile[i] != "\n") {
			clearedfile[wordscount] = fullfile[i];
			wordscount++;
		}
	}
}
void MainClass::vivod()
{
	for (int i = 0; i < countforoutput; i++)
		cout << fullfile[i];
}

void MainClass::forbreak()
{
	if (checkskob())
	{
		int l[100];
		int countbreaksforoutput = 0;
		int k = 0; 
		extern HANDLE hConsole;
		for (int i = 0; i < wordscount; i++)
		{
			int j = 0;
			if ((clearedfile[i] == "for") || (clearedfile[i] == "while") || (clearedfile[i] == "switch"))
			{
				int countsk = -1; 
				int countfig = -1; 
				for (j = i + 1; j < wordscount; j++)
				{
					if (countsk != 0) { 
						if (clearedfile[j] == "(") {
							if (countsk == -1)
								countsk++;
							countsk++;
						}
						if (clearedfile[j] == ")") {
							if (countsk == -1) {
								countsk++;
								countsk++;
							}
							countsk--;
						}
						else
							if (clearedfile[j] == "break")
								if (j < wordscount - 1)
									if (clearedfile[j + 1] == ";")
										countbreaksforoutput++;
					}
					else
						if (countfig != 0) { 
							if (clearedfile[j] == "{") {
								if (countfig == -1)
									countfig++;
								countfig++;
							}
							else if (clearedfile[j] == "}") {
								if (countfig == -1) {
									countfig++;
									countfig++;
								}
								countfig--;
							}
							else
							{
								if (countfig == -1) {
									countfig++;
									if (clearedfile[j] == "break")
										if (j < wordscount - 1)
											if (clearedfile[j + 1] == ";")
												countbreaksforoutput++;
								}
								else {

									if (clearedfile[j] == "break")
										if (j != wordscount - 1)
											if (clearedfile[j + 1] == ";")
											{
												countbreaksforoutput++;
											}
								}
							}
						}
						else
						{
							break;
						}
				}
				i = j;
			}
			if ((clearedfile[i] == "do"))
			{
				int countfig = -1;
				int countbreak = 0; 
				for (j = i + 1; j < wordscount; j++)
				{
					if (countfig != 0) {
						if (clearedfile[j] == "{") {
							if (countfig == -1)
								countfig++;
							countfig++;
						}
						else if (clearedfile[j] == "}") {
							if (countfig == -1) {
								countfig++;
								countfig++;
							}
							countfig--;
						}
						else
						{
							if (countfig == -1) {
								countfig++;
								if (clearedfile[j] == "break")
									if (j < wordscount - 1)
										if (clearedfile[j + 1] == ";")
											countbreaksforoutput++;
							}
							else {

								if (clearedfile[j] == "break")
									if (j != wordscount - 1)
										if (clearedfile[j + 1] == ";")
										{
											countbreaksforoutput++;
										}
							}
						}
					}
					else
					{
						break;
					}
				}
				i = j;
			}
			if (clearedfile[i] == "break")
				if (i != wordscount - 1)
					if (clearedfile[i + 1] == ";")
					{
						countbreaksforoutput++;
						l[k] = countbreaksforoutput;
						k++;
					}
		}
		int p = 0;
		int j = 0;
		for (int i = 0; i < countforoutput; i++)
		{
			if (fullfile[i] == "break")
			{
				if (i != countforoutput - 1)
					if (fullfile[i + 1] == ";") {
						p++;
						if (j <= k)
							if (l[j] == p)
							{
								SetConsoleTextAttribute(hConsole, 20);
								j++;
							}
					}
			}
			cout << fullfile[i];
			SetConsoleTextAttribute(hConsole, 7);
		}
	}
}


int MainClass::checkskob()
{
	int countsk = 0;
	int countfig = 0;
	for (int i = 0; i < wordscount; i++) {
		if (clearedfile[i] == "{")
			countfig++;
		if (clearedfile[i] == "}")
			countfig--;
		if (clearedfile[i] == "(")
			countsk++;
		if (clearedfile[i] == ")")
			countsk--;
		if (countfig < 0)
		{
			cout << "Lishnie zakrivaushie figurnie skobki";
			return 0;
		}
		if (countsk < 0)
		{
			cout << "Lishnie zakrivaushie kruglie skobki";
			return 0;
		}
	}
	if (countfig > 0)
	{
		cout << "Lishnie otkrivaushie figurnie skobki";
		return 0;
	}
	if (countsk > 0)
	{
		cout << "Lishnie otkrivaushie kruglie skobki";
		return 0;
	}
	return 1;
}