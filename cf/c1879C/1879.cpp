#include <iostream>
#include <string.h>

void solve()
{
	char str[200002];
	static long long bin_count[200002];
	memset(bin_count,0, sizeof(long long ) * 200002);
	int bin_count_i = 0;
	std::cin >> str;
	bin_count[0] = 1;
	
	char current = str[0];
	
	for(int i = 1; str[i] != '\0'; i++)
	{
		if(str[i] != current)
		{
			
			current = str[i];
			bin_count_i++;
		}
		bin_count[bin_count_i]++;
	}
	long long change = 0;
	long long n = 0;
	long long changed_seq = 0;
	long long comb = 1;
	for(int i = 0; i <= bin_count_i; i++)
	{
		change += bin_count[i] -1;
		if(bin_count[i] >= 2)
			n += bin_count[i];

	}

}
int main()
{
	std::cin.sync_with_stdio(false);
	
	int testcase = 0;
	std::cin >> testcase;
		for(int i = 0; i < testcase; i++)
			solve();
}