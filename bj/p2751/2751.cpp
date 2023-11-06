#include <iostream>
#include <algorithm> // for random suffle 
#include <cstring>


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

int * merge_sort(int * _array, int _size)
{
  int * array = new int[_size];
  std::memcpy(array,_array, sizeof(int) * _size);


   if(_size <= 1 )
    return array;

  int left_size = _size /2;
  int right_size = _size - _size/2;

  int * left_sort    = merge_sort(array, left_size);
  int * right_sort   = merge_sort(array+left_size, right_size);
  {
    int lidx = 0;
    int ridx = 0;
    
    while(lidx + ridx < _size)
    {
      if(lidx < left_size && ridx < right_size)
      {
        int min = (left_sort[lidx] < right_sort[ridx] ?
           left_sort[lidx++] : 
          right_sort[ridx++]);
        array[lidx + ridx -1 ] = min;
        continue;
      }
      if(!(lidx < left_size))
      {
        array[lidx + ridx] = right_sort[ridx];
        ridx++;
        continue;
      }
        


      if(!(ridx < right_size))
      {
        array[lidx + ridx] = left_sort[lidx];
        lidx++;
        continue;
      }

    }
    
  }
//   std::cout << "------------------- sort -------------" << std::endl;

// show_array(left_sort, left_size);
// show_array(right_sort, right_size);
//     show_array(array,_size);
  return array;

}
void solve()
{
    int array[1000002];
    int size;
    std::cin.sync_with_stdio(false);
    std::cin >> size;
    for(int i = 0; i < size; i++)
        std::cin >> array[i];
    int * arr_out = merge_sort(array, size);
    for(int i = 0; i< size; i++)
        std::cout << arr_out[i] << '\n';

}
int main()
{

//   srand(argc > 1 ? std::stoi(argv[1]) : 0 );
//   int * array = gen_array(10);
//   show_array(array,10 );
solve();
  return 0;
}