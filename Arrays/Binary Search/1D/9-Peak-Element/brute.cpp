#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr)
{
   int n = arr.size();

   for (int i = 0; i < n; i++)
   {
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
         return arr[i];
   }
   return -1;
}

int main()
{
   vector<int> v = {1, 2, 3, 6, 3, 2, 1};
   cout << peakElement(v);

   return 0;
}