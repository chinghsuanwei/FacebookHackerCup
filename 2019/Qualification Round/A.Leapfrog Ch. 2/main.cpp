#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool solution(string lilypads)
{
	int count_B = 0;
	int size = lilypads.length();
	for (int i = 0; i < size; i++)
	{
		if (lilypads[i] == 'B')
		{
			count_B++;
		}
	}

	int space = size - 1;
	int min = (space/2) + (space%2);

	return (count_B >= min || count_B >= 2) && count_B < space;
}

int main()
{
	int T = 0;
	std::ifstream in("leapfrog_ch_2_input.txt");
	std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("leapfrog_ch_2_output.txt");
	std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cin >> T;
	for (int i=0; i < T; i++)
	{
		string lilypads;
		cin >> lilypads;


		cout << "Case #" << i + 1 << ":";
		cout << (solution(lilypads)? 'Y' : 'N');
		cout << endl;
	}
}