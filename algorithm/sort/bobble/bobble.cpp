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

void bobble_sort(int * _array, int _size)
{
  for(int un_sort =_size; un_sort > 1 ; un_sort--)
    for(int j = 0; j+1 < un_sort; j++)
    {
      if(_array[j] > _array[j + 1] )
      std::swap(_array[j], _array[j+1]);
    }
      
}

void bobble_sort2(int * _array, int _size)
{
  for(int sort = 0; sort <= _size; sort++)
    for(int idx = _size -1; idx - 1 >= 0; idx--)
    {
      if(_array[idx-1] > _array[idx])
        std::swap(_array[idx], _array[idx-1]);
    }
}
int main(int argc , char ** argv)
{

  srand(argc > 1 ? std::stoi(argv[1]) : 0 );
  int * array = gen_array(10);
  show_array(array,10 );
  std::cout << "sort " << std::endl;

  bobble_sort2(array, 10);
  show_array(array,10);

  return 0;
}