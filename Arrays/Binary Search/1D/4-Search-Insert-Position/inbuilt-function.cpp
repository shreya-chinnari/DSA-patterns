// 4 - Search - Insert - Position
// https://leetcode.com/problems/search-insert-position/description/

#include <bits/stdc++.h>
using namespace std;

// if same element found (v[mid] = key) -> return its index
// else find smallest element (v[mid] > key) -> return that index
// hence, (v[mid] >= key)

int insertPosition(vector<int> &v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;
   int pos = n; // if it's greater than last element

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (v[mid] >= key)
      {
         pos = mid;   // potential position
         e = mid - 1; // check LHS for smaller elements
      }
      else
         s = mid + 1;
   }
   return pos;
}

int main()
{
   vector<int> v = {1, 2, 4, 7, 9};

   cout << insertPosition(v, 4) << endl; // if same element found (v[mid] = key) -> return its index
   cout << insertPosition(v, 3);         // else find smallest element (v[mid] > key) -> return that index
   return 0;
}