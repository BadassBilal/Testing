#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class GB {
public:
	void openFile(string Path);
	void closeFile();
	double aggregateCalc(double, double, double, double, double, double, double, double, double);
	void createFiles();
	bool emptyStrThenF(string);
	void readData();
	void classAvr(double);
	void Vadd(string, string, double, int);
	void filter();

private:
	string fname, lname, path, fileName;
	int cms, serial, c;
	double aggr, cAvg, q1, q2, q3, a1, a2, a3, oht1, oht2, ese;
	ifstream tFile;
	ofstream aG, bpG, bG, cpG, cG, dpG, dG, fail;
	vector <int> cmsId;
	vector <string> FnLnames;
	vector <double> aggregate;
	//Final
	vector <string> G;
	vector <string> Cname;
	vector <int> Id;
	vector <double> agg;

};
