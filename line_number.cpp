#include <iostream>
#include <unistd.h>
using namespace std;
/*
	This program will number every line to stdout, which is read from stdin.
	-C will color those lines.
	-D will delay those output.

	example:
	"ls -l -a | ./line_number -C -D"
*/
int main(int argc, char* argv[])
{
	string q;
	bool color_flag = false, delay_flag = false;
	if (argc > 1)
	{
		string c = "-C", d = "-D";
		for (int i = 1; i < argc; i++)
		{
			if (argv[i] == c) color_flag = true;
			if (argv[i] == d) delay_flag = true;
		}
	}

	for (int i = 1; getline(cin, q); i++)
	{
		if (color_flag)
		{
			cout << "\e[1;" << (31+i%8) << "m";

		}
		cout << i << ". " << q;
		if (color_flag)
		{
			cout << "\e[0m";
		}
		cout << endl;
		if (delay_flag) usleep(200000);
	}
	return 0;
}