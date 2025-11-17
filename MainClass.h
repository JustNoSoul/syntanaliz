#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
class MainClass
{
	string fullfile[10000];
	string clearedfile[10000];
	int wordscount = 0;
	int countforoutput = 0;
public:
	void load();
	void forbreak();
	void vivod();
	int checkskob();
};