#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int W[100];

int solution(int N)
{
	int idx_head = 0;
	int idx_tail = N - 1;
	
	sort(W, W + N);

	int trips = 0;
	int weight_of_top_item = 0;
	int number_of_items = 0;

	while (idx_head <= idx_tail)
	{
		weight_of_top_item = W[idx_tail];

		if (weight_of_top_item >= 50) number_of_items = 1;
		else if (weight_of_top_item < 50)
		{
			number_of_items = 50 / weight_of_top_item;
			if(50 % weight_of_top_item != 0) number_of_items++;
		}
		
		if (idx_head + (number_of_items - 1) > idx_tail) //9, 19, 29, 39, 49, 59
		{
			if (weight_of_top_item * (idx_tail - idx_head + 1) >= 50) trips++; //If weight of bag in last trip is larger than 50, then it's counted.		
			break;
		}
		
		
		idx_head += (number_of_items - 1);
		trips++;
		idx_tail--;
	}

	return trips;
}

int main()
{
	int T = 0;
	std::ifstream in("lazy_loading_input.txt");
	std::streambuf* cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("lazy_loading_output.txt");
	std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cin >> T;
	for (int i=0; i < T; i++)
	{
		int N = 0;
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			cin >> W[j];
		}

		cout << "Case #" << i + 1 << ":";
		cout << solution(N);
		cout << endl;
	}
}