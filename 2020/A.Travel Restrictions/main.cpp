#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool check_transfer(int from, int to, string incoming, string outgoing)
{
	if (from < to)
	{
		for (int i = from; i < to; i++)
		{
			if (outgoing[i] == 'N' || incoming[i + 1] == 'N') return false;
		}

		return true;
	}
	else
	{
		for (int i = from; i > to; i--)
		{
			if (outgoing[i] == 'N' || incoming[i - 1] == 'N') return false;
		}

		return true;
	}
}

void solution(int N, string incoming, string outgoing)
{
	bool** available = new bool* [N];
	for (int i = 0; i < N; ++i)
		available[i] = new bool[N];

	for (int i=0; i < N; i++)
	{
		for (int j=0; j < N; j++)
		{
			if (i == j) available[i][j] = true;
			else if (abs(i - j) == 1)
			{
				if (outgoing[i] == 'N' || incoming[j] == 'N')
				{
					available[i][j] = false;
				}
				else
				{
					available[i][j] = true;
				}
			}
			else
			{
				available[i][j] = check_transfer(i, j, incoming, outgoing);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << (available[i][j] ? 'Y' : 'N');
		}

		cout << endl;
	}

}

int main()
{
	int T = 0;
	std::ifstream in("travel_restrictions_input.txt");
	std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("travel_restrictions_output.txt");
	std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cin >> T;
	for (int i=0; i < T; i++)
	{
		int N = 0;
		cin >> N;
		string incoming;
		string outgoing;
		cin >> incoming;
		cin >> outgoing;

		cout << "Case #" << i+1 << ":" << endl;
		solution(N, incoming, outgoing);
	}
}