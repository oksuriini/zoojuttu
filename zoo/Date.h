#pragma once
#include <string>
using namespace std;
class Date
{
private:
	int d;
	int m;
	int y;
public:
	Date(int d=1, int m=1, int y=2000);
	int getD() { return d; }
	int getM() { return m; }
	int getY() { return y; }
	bool checkValues(int d, int m, int y);
	bool setValues(int d, int m, int y);
	string toString() { return to_string(d) + "." + to_string(m) + "." + to_string(y); }
};

