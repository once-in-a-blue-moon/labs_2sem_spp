#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "functios.h"
using namespace std;

//Варіант 26
//Створити текстовий файл. Скопіювати останні N рядків вихідного файлу до нового тектового файлу.
//У новому файлі знайти повторювані рядки і видалити їх. Визначити кількість видалених рядків.
//Вивести вміст вихідного і створеного файлів.

int main(){
	setlocale(LC_ALL, "russian");
	char input[] = "initialFile.txt";
	char output[] = "newFile.txt";
	inputFile(input);
	int n;
	cout << "\nВведите количество последних рядков: "; cin >> n;
	createNewFile(input, output, n);
	AfterDeleting(output);
	return 0;
}
