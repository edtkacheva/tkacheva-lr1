#include <iostream>
#include <fstream>
using namespace std;
//Структура трубы
struct pipe {
	string name;
	double length;
	double diameter;
	bool inrepair;
};
//Структура компрессорной станции 
struct cstation {
	string name;
	int workshop;
	int workingwshop;
	double efficiency;
};
//Ввод пользователем данных о новой трубе
pipe inputpipe() {
	pipe p;
	cout << "Enter pipe name: " << endl;
	cin >> p.name;
	do
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter pipe length: " << endl;
		cin >> p.length;
	} while (cin.fail());
	do
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter pipe diameter: " << endl;
		cin >> p.diameter;
	} while (cin.fail());
	do
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Is the pipe being repaired? (1 - yes, 0 - no): " << endl;
		cin >> p.inrepair;
	} while (cin.fail());
	return p;
}
//Ввод пользователем данных о компрессорной станции
cstation inputcstation() {
	cstation cs;
	cout << "Enter the name of the compressor station: " << endl;
	cin >> cs.name;
	do
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter the number of workshops: " << endl;
		cin >> cs.workshop;
	} while (cin.fail());
	do
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter the number of workshops in operation: " << endl;
		cin >> cs.workingwshop;
	} while (cin.fail() || cs.workingwshop > cs.workshop);
	do
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter performance indicator: " << endl;
		cin >> cs.efficiency;
	} while (cin.fail());
	return cs;
}
//Вывод информации о трубе в консоль
void outputpipe(pipe p) {
	cout << "Pipe name: " << p.name << endl;
	cout << "Pipe length: " << p.length << endl;
	cout << "Pipe diameter: " << p.diameter << endl;
	cout << "Condition 'under repair': " << p.inrepair << endl;
}
//Вывод информации о компрессорной станции в консоль
void outputcstation(cstation cs) {
	cout << "Compressor station name: " << cs.name << endl;
	cout << "The number of workshops: " << cs.workshop << endl;
	cout << "The number of working workshops: " << cs.workingwshop << endl;
	cout << "Performance indicator: " << cs.efficiency << endl;
}
//Изменение состояния "в ремонте" для трубы
pipe changeinrepair(pipe p) {
	p.inrepair = !p.inrepair;
	return p;
}
//Запуск и остановка цехов в компрессорной станции
cstation changeworkshop(cstation cs) {
	cout << "The number of workshops: " << cs.workshop << endl;
	cout << "The number of working workshops: " << cs.workingwshop << endl;
	do
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Enter new number of working workshops: " << endl;
		cin >> cs.workingwshop;
	} while (cin.fail());
	return cs;
}
//Сохранение данных о трубе в файл
void ofilepipe(pipe p) {
	ofstream fout;
	fout.open("pipe.txt", ofstream::app);
	fout << p.name << "\t" << p.length << "\t" << p.diameter << "\t" << p.inrepair << endl;
	fout.close();
}
//Сохранение данных о компрессорной станции в файл
void ofilecstation(cstation cs) {
	ofstream fout;
	fout.open("cstation.txt", ofstream::app);
	fout << cs.name << "\t" << cs.workshop << "\t" << cs.workingwshop << "\t" << cs.efficiency << endl;
	fout.close();
}
//Чтение данных о трубах из файла
void ifilepipe() {
	ifstream fin;
	fin.open("pipe.txt");
	char ch;
	while (fin.get(ch)) {
		cout << ch;
	}
	fin.close();
}
//Чтение данных о компрессорных станциях из файла
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