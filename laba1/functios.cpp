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
		printf("\n#################\nFile \"%s\"\n#################\n", name);
		while (getline(file, line)) {
			cout << line;
			if (!file.eof())
				cout << endl;
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
	string line, text = "";
	ifstream infile(name);
	ofstream outfile(newname);
	if (!infile || !outfile) {
		cout << "\nOops! Cannot open the file.\n";
	}
	int pos = NumOfLines(name, numLines) - numLines, count = 0;
	while (getline(infile, line)) {
		if (pos <= count) {
			outfile << line;
			if (!infile.eof())
				outfile << endl;
		}
		count++;
	}
	cout << "\n New file:";
	outfile.close();
	outputFile(newname);
	infile.close();
}

string deleteDoubleLines(char* name)
{
	string line, text = "";
	ifstream infile(name);
	if (!infile) {
		cout << "\nOops! Cannot open the file.\n";
	}
	int numOfDeletedLines = 0;
	while (getline(infile, line)) {
		int found = text.find(line);
		if (found == -1) {
			text += line;
			if (!infile.eof())
				text += '\n';
		}
		else
			numOfDeletedLines++;
	}
	printf("\n#################\nNumber of deleted lines: %d\n#################\n", numOfDeletedLines);
	infile.close();
	return text;
}

void AfterDeleting(char* name) {
	string text = deleteDoubleLines(name);
	ofstream outfile(name);
	if (!outfile) {
		cout << "\nOops! Cannot open the file.\n";
	}
	outfile << text;
	outfile.close();
	printf("\nAfter deleting duplicate lines:");
	outputFile(name);
}
