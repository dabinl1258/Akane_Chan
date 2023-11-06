#include <iostream>
#include <algorithm> // for random suffle 
#include <cstring>
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
		
		if(high - low == 1 && array[low] > array[high]) // at size 2 
		{
				SWAP(array[low], array[high]);
		}
		if(high - low <= 1)
				return;
		int pivot = (rand() %  (high - low + 1 )) + low;

		SWAP(array[pivot], array[low]);
		pivot = low;
		int i = low + 1;
		int j = high;
		while(i < j)
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
		
		
}
int main(int argc , char ** argv)
{
	int size = 12;
	srand(argc > 1 ? std::stoi(argv[1]) : 0 );
	int * array = gen_array(size);
	int * sort = array;
	show_array(array,size );
	quick(array,0, size -1);
	std::cout << "sorted " << std::endl;
	
	show_array(sort , size);

	return 0; 
}