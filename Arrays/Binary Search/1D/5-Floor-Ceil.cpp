// floor = largest element <= KEY
// ceil = smallest element >= KEY ---> LowerBound

#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   int ans = -1;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (v[mid] <= key)
      {
         ans = mid;
         s = mid + 1; // check for larger number
      }
      else
         e = mid - 1;
   }
   return ans;
}

int ceil(vector<int> v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   int ans = n;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (v[mid] >= key)
      {
         ans = mid;
         e = mid - 1;
      }
      else
         s = mid + 1;
   }
   return ans;
}

// not necessary, just for practice

pair<int, int> FloorCeil(vector<int> &v, int key)
{
   int floor_value = floor(v, 3);
   int ceil_value = ceil(v, 3);

   return {floor_value, ceil_value};
   // return make_pair(floor_value, ceil_value);
}

int main()
{
   vector<int> v = {0, 1, 2, 3, 4, 5};
   pair<int, int> floor_ceil = FloorCeil(v, 3);
   cout << "floor: " << floor_ceil.first << ", ceil: " << floor_ceil.second << endl;

   return 0;
}