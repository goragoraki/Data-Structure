#include <iostream>
using namespace std;
typedef int ItemType;
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void Split(ItemType values[], int first, int last, int& splitPoint)
{
  ItemType splitVal = values[first]; // pivot point
  int saveFirst = first;
  bool onCorrectSide;

  first++;
  do
  {
    onCorrectSide = true;
    while (onCorrectSide)         // Move first toward last.
      if (values[first] > splitVal)
        onCorrectSide = false;
      else
      {  
        first++;
        onCorrectSide = (first <= last);
      }

    onCorrectSide = (first <= last);
    while (onCorrectSide)             // Move last toward first.
      if (values[last] <= splitVal)
        onCorrectSide = false;
      else
      {
        last--;
        onCorrectSide = (first <= last);
      }
   
    if (first < last)
    {
      Swap(values[first], values[last]);
      first++;
      last--;
    }
  } while (first <= last);

  splitPoint = last;
  Swap(values[saveFirst], values[splitPoint]);
}


template<class ItemType>
void QuickSort(ItemType values[], int first, int last)
{
  if (first < last)
  {
    int splitPoint;

    Split(values, first, last, splitPoint);
    // values[first]..values[splitPoint-1] <= splitVal
    // values[splitPoint] = splitVal
    // values[splitPoint+1]..values[last] > splitVal

    QuickSort(values, first, splitPoint-1);
    QuickSort(values, splitPoint+1, last);
  }
}
int main() {
    int arr[9] = { 1,4,6,3,2,9,8,7,5 };
    QuickSort(arr, 0, 8);
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
    return 0;
}
