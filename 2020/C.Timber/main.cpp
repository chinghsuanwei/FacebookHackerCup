#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

struct Tree {
	long long p;
	long long h;
};


long long solution(vector<Tree>& trees)
{
	int N = trees.size();
	long long max = 0;

	map<long, long> dict;
	map<long, long> left_landing;
	map<long, long> right_landing;
	set<long long> left_solved;
	set<long long> right_solved;

	for (int i = 0; i < N; i++)
	{
		long long h = trees[i].h;
		long long p = trees[i].p;

		dict.insert(std::pair<long, long>(p, h));
	}

	//right
	for (int i = 0; i < N; i++)
	{
		long long length = 0;
		long long cur_p = trees[i].p;
		
		if (right_solved.find(cur_p) != right_solved.end()) continue;

		do
		{
			length += dict[cur_p];
			right_solved.insert(cur_p);

			cur_p = cur_p + dict[cur_p];

			if (right_landing.find(cur_p) != right_landing.end())
			{
				if (length > right_landing[cur_p])
				{
					right_landing[cur_p] = length;
				}
			}
			else
			{
				right_landing.insert(std::pair<long, long>(cur_p, length));
			}

			if (length > max)
			{
				max = length;
			}

		} while ((dict.find(cur_p) != dict.end()));
	}

	//left
	for (int i = N-1; i >= 0; i--)
	{
		long long length = 0;
		long long cur_p = trees[i].p;

		if (left_solved.find(cur_p) != left_solved.end()) continue;

		
		do
		{
			length += dict[cur_p];
			left_solved.insert(cur_p);
			cur_p = cur_p - dict[cur_p];

			if (left_landing.find(cur_p) != left_landing.end())
			{
				if (length > left_landing[cur_p])
				{
					left_landing[cur_p] = length;
				}
			}
			else
			{
				left_landing.insert(std::pair<long, long>(cur_p, length));
			}


			if (length > max)
			{
				max = length;
			}

		} while ((dict.find(cur_p) != dict.end()));

	}

	//right + left
	for (std::map<long, long>::iterator it = right_landing.begin(); it != right_landing.end(); ++it)
	{
		if (left_landing.find(it->first) != left_landing.end())
		{
			long long length = it->second + left_landing[it->first];
			if (length > max)
			{
				max = length;
			}
		}
	}

	return max;
}

bool sortTreePosition(Tree t1, Tree t2)
{
	return (t1.p < t2.p);
}

int main()
{
	int T = 0;
	std::ifstream in("timber_input.txt");
	std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("timber_output.txt");
	std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cin >> T;

	
	for (int i=0; i < T; i++)
	{
		vector<Tree> trees;
		

		int N = 0;
		cin >> N;
		
		for (int j = 0; j < N; j++)
		{
			Tree tree;
			cin >> tree.p;
			cin >> tree.h;

			trees.push_back(tree);
		}

		sort(trees.begin(), trees.end(), sortTreePosition);
		cout << "Case #" << i+1 << ": ";
		cout << solution(trees);
		cout << endl;
	}
}