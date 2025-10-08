#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   // if no upper bound is found
   int ub = n; // n = outside array index range

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (v[mid] > key)
      {
         ub = mid; // potential answer
         e = mid - 1;
      }
      else
         s = mid + 1;
   }
   return ub;
}

int main()
{
   vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

   int ub = upperBound(v, 5);
   cout << ub; // 5

   return 0;
}