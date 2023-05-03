#include <iostream>
#include <bits/move.h>
#include <algorithm> // for random suffle 
#include <type_traits>
#include <bits/stdc++.h>

int * gen_array(int _size)
{
  int * ret = new int[_size];
  for(int i  = 1 ; i <= _size; i++)
    ret[i -1] = i;
  std::random_shuffle<int *>(ret, ret + _size);
  return ret;
}

void show_array(int * array, int _size)
{
  for(int i = 0; i < _size; i++)
    std::cout << array[i] << (i < _size -1 ? " , " : "");
  std::cout << std::endl;
}

void shift_array(int * _array, int _index , int len)
{
  for(int index = _index + len - 1; index >= _index; index-- )
    _array[index +1] = _array[index];
  
}

void insert(int * _array, int _size, int value)
// _size is sorted size 
{
  if(_size <= 0 ){
    _array[0] = value;  
    return;
  }
  for(int i = 0; i < _size; i++)
  {
    if(_array[i] <= value)
      continue;
    shift_array(_array, i , _size - i );
    _array[i] = value;
    return;
  }
  _array[_size] = value;
}


void insert_sort(int * _array, int _size)
{
  for(int i = 1 ; i < _size; i++)
    insert(_array, i, _array[i]);
    
}

int main(int argc , char ** argv)
{

  srand(argc > 1 ? std::stoi(argv[1]) : 0 );
  int * array = gen_array(10);
  show_array(array,10 );
  std::cout << "sort " << std::endl;

  insert_sort(array, 10);
  show_array(array,10);

  return 0;
}