#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Header.h"
#include <assert.h>
using namespace std;
/// Opens File.
void GB::openFile(string Path)
{
	tFile.open(Path);
}
///Calculate the Aggregate.
double GB::aggregateCalc(double q_1, double q_2, double q_3, double a_1, double a_2, double a_3, double oht1, double oht2, double ese)
{
	double q, A, O, E, agg;
	q = (((q_1 + q_2 + q_3) * 100) / 30) * 0.1;
	A = (((a_1 + a_2 + a_3) * 100) / 30) * 0.1;
	O = (oht1 + oht2) * (0.4);
	E = ese*0.4;
	agg = q + A + O + E;
	assert(agg != NULL);
	return agg;
}
///Updates the Initial Vectors - aggregate/Full-Last Names/CMSIDs
void GB::Vadd(string f, string l, double a, int cms)
{
	aggregate.push_back(a);
	FnLnames.push_back(f + l);
	cmsId.push_back(cms);
}

///Creates File and Writes to them
void GB::createFiles()
{
	aG.open("A.csv");

	bpG.open("B+.csv");

	bG.open("B.csv");

	cpG.open("C+.csv");

	cG.open("C.csv");

	dpG.open("D+.csv");

	dG.open("D.csv");

	fail.open("F.csv");


	for (int i = 0; i < G.size(); i++)
	{
		if (G[i] == "A")
		{

			aG << Id[i] << "," << Cname[i] << "," << agg[i] << "," << G[i] << endl;
		}
		else if (G[i] == "B+")
		{

			bpG << Id[i] << "," << Cname[i] << "," << agg[i] << "," << G[i] << endl;
		}
		else if (G[i] == "B")
		{

			bG << Id[i] << "," << Cname[i] << "," << agg[i] << "," << G[i] << endl;
		}
		else if (G[i] == "C+")
		{

			cpG << Id[i] << "," << Cname[i] << "," << agg[i] << "," << G[i] << endl;
		}
		else if (G[i] == "C")
		{

			cG << Id[i] << "," << Cname[i] << "," << agg[i] << "," << G[i] << endl;
		}
		else if (G[i] == "D+")
		{

			dpG << Id[i] << "," << Cname[i] << "," << agg[i] << "," << G[i] << endl;
		}
		else if (G[i] == "D")
		{

			dG << Id[i] << "," << Cname[i] << "," << agg[i] << "," << G[i] << endl;
		}
		else
		{

			fail << Id[i] << "," << Cname[i] << "," << agg[i] << "," << G[i] << endl;
		}
	}

}
///filters the names according to aggregate
void GB::filter()
{
	int tempSize = aggregate.size();
	//double tempAvg = avg / nos;
	for (int i = 0; i < tempSize; i++)
	{
		if (aggregate[i] >= 80)
		{
			G.push_back("A");
			Cname.push_back(FnLnames[i]);
			agg.push_back(aggregate[i]);
			Id.push_back(cmsId[i]);
		}
		else if (aggregate[i] >= 75 && aggregate[i] < 80)
		{
			G.push_back("B+");
			Cname.push_back(FnLnames[i]);
			agg.push_back(aggregate[i]);
			Id.push_back(cmsId[i]);
		}
		else if (aggregate[i] >= 70 && aggregate[i] < 75)
		{
			G.push_back("B");
			Cname.push_back(FnLnames[i]);
			agg.push_back(aggregate[i]);
			Id.push_back(cmsId[i]);
		}
		else if (aggregate[i] >= 65 && aggregate[i] < 70)
		{
			G.push_back("C+");
			Cname.push_back(FnLnames[i]);
			agg.push_back(aggregate[i]);
			Id.push_back(cmsId[i]);
		}
		else if (aggregate[i] >= 60 && aggregate[i] < 65)
		{
			G.push_back("C");
			Cname.push_back(FnLnames[i]);
			agg.push_back(aggregate[i]);
			Id.push_back(cmsId[i]);
		}
		else if (aggregate[i] >= 55 && aggregate[i] < 60)
		{
			G.push_back("D+");
			Cname.push_back(FnLnames[i]);
			agg.push_back(aggregate[i]);
			Id.push_back(cmsId[i]);
		}
		else if (aggregate[i] >= 50 && aggregate[i] < 55)
		{
			G.push_back("D");
			Cname.push_back(FnLnames[i]);
			agg.push_back(aggregate[i]);
			Id.push_back(cmsId[i]);
		}
		else
		{
			G.push_back("F");
			Cname.push_back(FnLnames[i]);
			agg.push_back(aggregate[i]);
			Id.push_back(cmsId[i]);
		}

	}
}

///For Class Average
void GB::classAvr(double a)
{
	serial += 1;
	cAvg += a;
}

///Boolean Decider
bool GB::emptyStrThenF(string s)
{
	if (s != "")
		return false;
	else
		return true;
}

///Reads data from .csv
void GB::readData()
{
	int tC = 0;
	string Temp, lnr;

	while (getline(tFile, lnr))
	{
		if (tC >= 2)
		{
			stringstream ss(lnr);
			getline(ss, Temp, ',');
			cms = stoi(Temp);
			getline(ss, fname, ',');
			getline(ss, lname, ',');
			getline(ss, Temp, ',');
			if (!emptyStrThenF(Temp))
				q1 = stod(Temp);
			else
				q1 = 0;
			getline(ss, Temp, ',');
			if (!emptyStrThenF(Temp))
				a1 = stod(Temp);
			else
				a1 = 0;
			getline(ss, Temp, ',');
			if (!emptyStrThenF(Temp))
				a2 = stod(Temp);
			else
				a2 = 0;
			getline(ss, Temp, ',');
			if (!emptyStrThenF(Temp))
				a3 = stod(Temp);
			else
				a3 = 0;
			getline(ss, Temp, ',');
			if (!emptyStrThenF(Temp))
				q2 = stod(Temp);
			else
				q2 = 0;
			getline(ss, Temp, ',');
			if (!emptyStrThenF(Temp))
				q3 = stod(Temp);
			else
				q3 = 0;
			getline(ss, Temp, ',');
			if (!emptyStrThenF(Temp))
				oht1 = stod(Temp);
			else
				oht1 = 0;
			getline(ss, Temp, ',');
			if (!emptyStrThenF(Temp))
				oht2 = stod(Temp);
			else
				oht2 = 0;
			getline(ss, Temp, '\n');
			if (!emptyStrThenF(Temp))
				ese = stod(Temp);
			else
				ese = 0;
			double agg = aggregateCalc(q1, q2, q3, a1, a2, a3, oht1, oht2, ese);
			classAvr(agg);
			Vadd(fname, lname, agg, cms);


		}
		tC += 1;
	}
}

///Closes Files
void GB::closeFile()
{
	tFile.close();
}