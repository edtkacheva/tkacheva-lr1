#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Pipe structure
struct pipe {
	string name;
	double length;
	double diameter;
	bool inrepair;
};
//Compressor station structure
struct cstation {
	string name;
	int workshop;
	int workingwshop;
	string efficiency;
};
//Check input
void inputint(int& x) {
	cin >> x;
	while (cin.fail() || x < 0 || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Try again!" << endl;
		cin >> x;
	}
}
void inputdouble(double& x) {
	cin >> x;
	while (cin.fail() || x < 0 || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Try again!" << endl;
		cin >> x;
	}
}
void inputbool(bool& x) {
	cin >> x;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Try again!" << endl;
		cin >> x;
	}
}
void inputstring(string& x) {
	cin >> x;
	while (!(x >= "A" && x <= "G" && x.length() == 1)) {
		cout << "Try again! " << endl;
		cin >> x;
	}
}
//User input for new pipe
pipe inputpipe() {
	pipe p;
	cout << "Enter pipe name: " << endl;
	cin.ignore();
	getline(cin, p.name);
	cout << "Enter pipe length: " << endl;
	inputdouble(p.length);
	cout << "Enter pipe diameter: " << endl;
	inputdouble(p.diameter);
	cout << "Is the pipe being repaired? (1 - yes, 0 - no): " << endl;
	inputbool(p.inrepair);
	return p;
}
//User input of compressor station data
cstation inputcstation() {
	cstation cs;
	cout << "Enter the name of the compressor station: " << endl;
	cin.ignore();
	getline(cin, cs.name);
	cout << "Enter the number of workshops: " << endl;
	inputint(cs.workshop);
	cout << "Enter the number of workshops in operation: " << endl;
	inputint(cs.workingwshop);
	while (cs.workshop < cs.workingwshop) {
		cout << "The number of operating compressor stations can't be more than the total number of stations!" << endl << "Try again!" << endl;
		inputint(cs.workingwshop);
	}
	cout << "Enter performance indicator from A to G: " << endl;
	inputstring(cs.efficiency);
	return cs;
}
//Outputting information about a pipe to the console
void outputpipe(pipe p) {
	cout << "Pipe name: " << p.name << endl;
	cout << "Pipe length: " << p.length << endl;
	cout << "Pipe diameter: " << p.diameter << endl;
	cout << "Condition 'under repair': " << p.inrepair << endl;
}
//Outputting information about the compressor station to the console
void outputcstation(cstation cs) {
	cout << "Compressor station name: " << cs.name << endl;
	cout << "The number of workshops: " << cs.workshop << endl;
	cout << "The number of working workshops: " << cs.workingwshop << endl;
	cout << "Performance indicator: " << cs.efficiency << endl;
}
//Changing the "under repair" status for a pipe
void changeinrepair(pipe& p) {
	if (p.name.empty()) {
		cout << "Pipe data doesn't exist" << endl;
	}
	else {
		p.inrepair = !p.inrepair;
		cout << "The status 'under repair' has been changed" << endl;
	}
}
//Starting and stopping workshops in a compressor station
void changeworkshop(cstation& cs) {
	if (cs.name.empty()) {
		cout << "Compressor station data doesn't exist" << endl;
	}
	else {
		cout << "The number of workshops: " << cs.workshop << endl;
		cout << "The number of working workshops: " << cs.workingwshop << endl;
		cout << "Enter new number of working workshops: " << endl;
		inputint(cs.workingwshop);
		while (cs.workshop < cs.workingwshop) {
			cout << "The number of operating compressor stations can't be more than the total number of stations!" << endl << "Try again!" << endl;
			inputint(cs.workingwshop);
		}
	}
}
//Saving pipe data to a file
void ofilepipe(pipe p) {
	ofstream fout;
	fout.open("data.txt", ofstream::app);
	if (fout.is_open()) {
		if (!p.name.empty()) {
			fout << "Pipe: " << endl;
			fout << p.name << endl << p.length << endl
				<< p.diameter << endl << p.inrepair << endl;
		}
		else {
			cout << "There is no data about the pipe" << endl;
		}
		fout.close();
	}
	else {
		cout << "File couldn't be open" << endl;
	}
}
//Saving compressor station data to a file
void ofilecstation(cstation cs) {
	ofstream fout;
	fout.open("data.txt", ofstream::app);
	if (fout.is_open()) {
		if (!cs.name.empty()) {
			fout << "Compressor station: " << endl;
			fout << cs.name << endl << cs.workshop
				<< endl << cs.workingwshop << endl << cs.efficiency << endl;
		}
		else {
			cout << "There is no data about compressor station" << endl;
		}
		fout.close();
	}
	else {
		cout << "File couldn't be open" << endl;
		}
}
//Reading data from a file
void ifile(pipe& p, cstation& cs) {
	ifstream fin;
	string line;
	fin.open("data.txt");
	if (fin.is_open()) {
		while (getline(fin, line)) {
			if (line == "Pipe: ") {
				cout << line << endl;
				fin >> p.name;
				fin >> p.length;
				fin >> p.diameter;
				fin >> p.inrepair;
				outputpipe(p);
			}
			else if (line == "Compressor station: ") {
				cout << line << endl;
				fin >> cs.name;
				fin >> cs.workshop;
				fin >> cs.workingwshop;
				fin >> cs.efficiency;
				outputcstation(cs);
			}
		}
		if (p.name.empty() && cs.name.empty()) {
			cout << "Data doesn't exist" << endl;
		}
		fin.close();
	}
	else {
		cout << "File couldn't be open" << endl;
	}
}
int main() {
	pipe p;
	cstation cs;
	while (true) {
		cout << "Menu: " << endl;
		cout << "1. Add pipe." << endl;
		cout << "2. Add a compressor station." << endl;
		cout << "3. View all objects." << endl;
		cout << "4. Edit pipe." << endl;
		cout << "5. Edit compressor station." << endl;
		cout << "6. Save." << endl;
		cout << "7. Load data from file." << endl;
		cout << "0. Exit." << endl;
		cout << "Enter the required number: ";
		int choice;
		inputint(choice);
		switch (choice) {
		case 1: {
			p = inputpipe();
			break;
		}
		case 2: {
			cs = inputcstation();
			break;
		}
		case 3: {
			if (p.name.empty() && cs.name.empty()) {
				cout << "Object data does't exist." << endl;
			}
			else {
				if (p.name.empty()) {
					cout << "Pipe data doesn't exist." << endl;
				}
				else {
					cout << "Pipe: " << endl;
					outputpipe(p);
				}
				if (cs.name.empty()) {
					cout << "Cstation data doesn't exist." << endl;
				}
				else {
					cout << "Compressor station: " << endl;
					outputcstation(cs);
				}
			}
			break;
		}
		case 4: {
			changeinrepair(p);
			break;
		}
		case 5: {
			changeworkshop(cs);
			break;

		}
		case 6: {
			ofilepipe(p);
			ofilecstation(cs);
			if (!p.name.empty() || !cs.name.empty()) {
				cout << "Data successfully saved to file" << endl;
			}
			break;
		}
		case 7: {
			ifile(p, cs);
			break;
		}
		case 0: {
			return 0;
		}
		default:
			cout << "Wrong choice! Try again!" << endl;
			break;
		}
	}
	return 0;
}