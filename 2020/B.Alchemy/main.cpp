#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool solution(string shards)
{
	int A_count = 0;
	int B_count = 0;
	int N = shards.length();
	for (int i = 0; i < N; i++)
	{
		if (shards[i] == 'A') A_count++;
		else if (shards[i] == 'B') B_count++;
		else _ASSERT(false);
	}

	return abs(A_count - B_count) == 1;
}

int main()
{
	int T = 0;
	std::ifstream in("alchemy_input.txt");
	std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("alchemy_output.txt");
	std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cin >> T;
	for (int i=0; i < T; i++)
	{
		int N = 0;
		cin >> N;
		string shards;
		cin >> shards;

		cout << "Case #" << i+1 << ": ";
		cout << (solution(shards)? 'Y' : 'N');
		cout << endl;
	}
}