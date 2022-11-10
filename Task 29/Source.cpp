#include<iostream>
#include<string>
#include<fstream> 

using namespace std;



// задача 2

bool overwrite(string path, string word) {
	ofstream out;
	out.open(path, ios::out);
	if (out.is_open()) {
		out << word << '\n';
		out.close();
		return true;
	}
	out.close();
	return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	// задача 1
	ofstream out;
	out.open("file.txt", ios::app);
	if (out.is_open()) {
		string input;
		do {
			cout << "Input string:\n ";
			getline(cin, input);
			out << input << '\n';
		} while (input != "end");
	}
	else
		cout << "File opening error\n";
	out.close();
	ifstream in;
	in.open("file.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			string str;
			getline(in, str);
			cout << str << '\n';
		}
	}
	else
		cout << "File opening error\n";
	in.close();
	remove("file.txt");

	// задача 2
	string Path = "file.txt";
	string str;
	getline(cin, str);
	if (overwrite(Path, str))
		cout << "успешно записано\n\n";
	else
		cout << "ошибка записи\n\n";
	return 0;
}
