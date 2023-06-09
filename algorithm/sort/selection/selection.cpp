#include <iostream>
#include <bits/move.h>
#include <algorithm> // for random suffle 


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

void selection_sort(int * _array, int _size)
{
  for(int sorted =_size; sorted > 1 ; sorted--)
  {
    int idx_max = 0;
    for(int idx = 1; idx < sorted; idx++)
    {
        idx_max = (_array[idx_max] < _array[idx] ? idx : idx_max );
    }
    std::swap(_array[idx_max], _array[sorted-1]);
  }
     
}

int main(int argc , char ** argv)
{

  srand(argc > 1 ? std::stoi(argv[1]) : 0 );
  int * array = gen_array(10);
  show_array(array,10 );
  std::cout << "sort " << std::endl;

  selection_sort(array, 10);
  show_array(array,10);

  return 0;
}