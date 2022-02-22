#include "functios.h"
#include <string>

void inputFile(char* name)
{
	string line;
	ofstream outfile(name);
	if (!outfile.is_open()) {
		cout << "Oops! Cannot open the file.";
	}
	else {
		cout << "Write your text here, to start a new line press Enter, to finish press Ctrl+z or any control key:" << endl;
		char key;
		while (cin.get(key) && (key == 10 || key > 31) && key < 128) {
			outfile.put(key);
		}
	}
	outfile.close();
}

void outputFile(char* name)
{
	ifstream file(name);
	if (!file) {
		cout << "Oops! Cannot open the file.";
	}
	else {
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
	}
	file.close();
}

int NumOfLines(char* name, int numLines) {
	string line;
	ifstream infile(name);
	int totalNumLines = 0;
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, line);
			totalNumLines++;
		}
		infile.close();
	}
	return totalNumLines;
}

void createNewFile(char* name, char* newname, int numLines)
{
	string line;
	ifstream infile(name);
	ofstream outFile(newname);
	int pos = NumOfLines(name, numLines) - numLines, count = 0;
	while (getline(infile, line)) {
		if(pos<=count)
			outFile << line << endl;
		count++;
	}
	cout << "\n New file:\n";
	outputFile(newname);
	infile.close();
	outFile.close();
}

void deleteDoubleLines(char* name, int numLines)
{
	string line;
	ifstream infile(name);
	ofstream outfile("outfile.txt");
	int num = NumOfLines(name, numLines);
	const char** lines;
	lines = new const char* [num];
	while (!infile.eof()) {
		for (int i = 0; i < num; i++)
		{
			string str = lines[i];
			getline(infile, str);
			
			bool found = false;
		}
	}

	
}


