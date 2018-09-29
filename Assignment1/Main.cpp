#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "Header.h"
using namespace std;

int main() {

	GB Run;
	Run.openFile("C:\\Users\\Administrator\\Documents\\Visual Studio 2015\\Projects\\Assignment1\\GBS.csv"); //Your Specified Path of your csv File.
	Run.readData();
	Run.closeFile();
	Run.filter();
	Run.createFiles();
	cout << "Processing Done." << endl;
	system("Pause");
	return 0;
}

