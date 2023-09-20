#include <iostream>
#include <fstream>
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
	double efficiency;
};
//Check input
void checkinput(int& x) {
	cin >> x;
	while (cin.fail() || x <= 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again!" << endl;
		cin >> x;
	}
}
void checkinput(double& x) {
	cin >> x;
	while (cin.fail() || x <= 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again!" << endl;
		cin >> x;
	}
}
void checkinput(bool& x) {
	int variable;
	cin >> variable;
	while (cin.fail() || !(variable == 0 || variable == 1))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Try again!" << endl;
		cin >> variable;
	}
	x = variable == 1;
}
//User input for new pipe
pipe inputpipe() {
	pipe p;
	cout << "Enter pipe name: " << endl;
	cin >> p.name;
	cout << "Enter pipe length: " << endl;
	checkinput(p.length);
	cout << "Enter pipe diameter: " << endl;
	checkinput(p.diameter);
	cout << "Is the pipe being repaired? (1 - yes, 0 - no): " << endl;
	checkinput(p.inrepair);
	return p;
}
//User input of compressor station data
cstation inputcstation() {
	cstation cs;
	cout << "Enter the name of the compressor station: " << endl;
	cin >> cs.name;
	cout << "Enter the number of workshops: " << endl;
	checkinput(cs.workshop);
	cout << "Enter the number of workshops in operation: " << endl;
	checkinput(cs.workingwshop);
	while (cs.workshop < cs.workingwshop) {
		cout << "The number of operating compressor stations can't be more than the total number of stations!" << endl << "Try again!" << endl;
		cin >> cs.workingwshop;
	}
	cout << "Enter performance indicator: " << endl;
	checkinput(cs.efficiency);
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
pipe changeinrepair(pipe p) {
	p.inrepair = !p.inrepair;
	cout << "The status 'under repair' has been changed" << endl;
	return p;
}
//Starting and stopping workshops in a compressor station
cstation changeworkshop(cstation cs) {
	cout << "The number of workshops: " << cs.workshop << endl;
	cout << "The number of working workshops: " << cs.workingwshop << endl;
	cout << "Enter new number of working workshops: " << endl;
	checkinput(cs.workingwshop);
	while (cs.workshop < cs.workingwshop) {
		cout << "The number of operating compressor stations can't be more than the total number of stations!" << endl << "Try again!" << endl;
		cin >> cs.workingwshop;
	}
	return cs;
}
//Saving pipe data to a file
void ofilepipe(pipe p) {
	ofstream fout;
	fout.open("pipe.txt", ofstream::app);
	fout << p.name << "\t" << p.length << "\t" << p.diameter << "\t" << p.inrepair << endl;
	fout.close();
}
//Saving compressor station data to a file
void ofilecstation(cstation cs) {
	ofstream fout;
	fout.open("cstation.txt", ofstream::app);
	fout << cs.name << "\t" << cs.workshop << "\t" << cs.workingwshop << "\t" << cs.efficiency << endl;
	fout.close();
}
//Reading pipe data from a file
void ifilepipe() {
	ifstream fin;
	fin.open("pipe.txt");
	char ch;
	while (fin.get(ch)) {
		cout << ch;
	}
	fin.close();
}
//Reading data about compressor stations from a file
void ifilecstation() {
	ifstream fin;
	fin.open("cstation.txt");
	char ch;
	while (fin.get(ch)) {
		cout << ch;
	}
	fin.close();
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
		cin >> choice;
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
			cout << "Pipe: " << endl;
			outputpipe(p);
			cout << "Compressor station: " << endl;
			outputcstation(cs);
			break;
		}
		case 4: {
			p = changeinrepair(p);
			outputpipe(p);
			break;
		}
		case 5: {
			cs = changeworkshop(cs);
			break;

		}
		case 6: {
			ofilepipe(p);
			ofilecstation(cs);
			break;
		}
		case 7: {
			cout << "Pipes: " << endl;
			ifilepipe();
			cout << "Compressor stations: " << endl;
			ifilecstation();
			break;
		}
		case 0: {
			return 0;
			break;
		}
		default:
			cout << "Wrong choice! Try again!" << endl;
			break;
		}
	}
}