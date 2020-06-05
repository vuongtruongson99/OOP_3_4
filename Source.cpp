#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_application.h"

using namespace std;

int main() {
	string s;
	vector<string> ans, format;
	cl_application ob1, ob2, ob3;
	ob1.input(s);
	ob2.format_input(s, format);
	ob2.cal(ans, format);
	ob3.output(ans);

	system("pause");
	return 0;
}