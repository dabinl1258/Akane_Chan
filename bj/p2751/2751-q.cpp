#include <iostream>
#include <algorithm> // for random suffle 
#include <cstring>
#include <time.h>
#define SWAP(a,b) if(a != b ) {a ^= b; b ^= a; a ^=b;}

// #define SWAP(a,b) \
// { \
//     int temp = a; \ 
//     a = b; \
//     b = temp; \
// } \
// void SWAP(int & a , int &b)
// {
//     int temp = a;
//     a = b;
//     a = temp;
// }

int * gen_array(int _size)
{
	int * ret = new int[_size];
	for(int i  = 1 ; i <= _size; i++)
		ret[i -1] = i;
	std::random_shuffle(ret, ret + _size);
	return ret;
}

void show_array(int * _array, int _size)
{
	for(int i = 0; i < _size; i++)
		std::cout << _array[i] << (i < _size-1 ? ",\t": "\n");
}
void quick(int * array, int low , int high)
{
		
		if(high - low +1  == 2 && array[low] > array[high]) // at size 2 
				SWAP(array[low], array[high]);
		if(high - low + 1 <= 2)
				return;
		int pivot = (rand() %  (high - low + 1 )) + low;

		SWAP(array[pivot], array[low]);
		pivot = low;
		int i = low + 1;
		int j = high;
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
int main(int argc , char ** argv)
{
  srand(time(0));
    int array[1000002];
    int size;
    std::cin.sync_with_stdio(false);
    std::cin >> size;
    for(int i = 0; i < size; i++)
        std::cin >> array[i];
    quick(array,0,size-1);
    for(int i = 0; i< size; i++)
        std::cout << array[i] << '\n';
    return 0 ;
}