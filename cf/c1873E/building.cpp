#include <iostream>
#include <algorithm> // for random suffle 
#include <cstring>
#define SWAP(a,b) if(a != b ) {a ^= b; b ^= a; a ^=b;}

void quick(long long * array, long long low , long long high)
{
		
		if(high - low +1  == 2 && array[low] > array[high]) // at size 2 
				SWAP(array[low], array[high]);
		if(high - low + 1 <= 2)
				return;
		long long pivot = (rand() %  (high - low + 1 )) + low;

		SWAP(array[pivot], array[low]);
		pivot = low;
		long long i = low + 1;
		long long j = high;
		while(i <= j)
		{
		
				while(array[i] < array[pivot] )
				{
						i++;
						if(i > j)
						{
								SWAP(array[pivot], array[j]);
								quick(array, low, j-1);
								quick(array, j+1, high);
								return;
						}
				}
				while(array[j] > array[pivot])
				{
						j--;
						if(i > j)
						{   
								SWAP(array[pivot], array[j]);
								quick(array, low, j-1);
								quick(array, j+1, high);
								return;
						}
				}
        
				SWAP(array[i], array[j]);
        j--;
        i++;
				
						
		}

    SWAP(array[pivot], array[j]);
    quick(array, low, j - 1);
    quick(array, j + 1, high);
}

int solve() 
{
    long long coral;
    long long water;
    std::cin >> coral;
    std::cin >> water;
    long long corals[200005];
    for(long long i =0 ; i < coral;i++ )
    {
        std::cin >> corals[i];
    }
    quick(corals,0, coral -1);
    
    long long height = corals[0];
    if(coral == 1)
    {
        std::cout << height +water<< "\n";
        return 0;
    }
    
    for(long long i =1 ; i < coral;i++ )
    {
        long long dh = corals[i] - corals[i- 1];
        water -= i * dh;
        if(water <= 0)
        {
            water += i * dh;
            height += water / (i);
            std::cout << height << "\n";
            return 0;
        }
        height += dh;


    }
    height +=  water / coral ;
    
    std::cout << height << "\n";
    return 0;


}
int main()
{
    long long testcase ;
    std::cin.sync_with_stdio(false);
    std::cin >> testcase;
    for(long long i =0; i < testcase; i++)
    {
        solve();
    }
}