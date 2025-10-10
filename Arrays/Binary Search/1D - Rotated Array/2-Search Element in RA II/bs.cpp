#include <bits/stdc++.h>
using namespace std;

// Array is NON-DECREASING
// DUPLICATES might be present

bool searchInRotatedArray(vector<int> v, int target)
{
   int n = v.size();

   int s = 0, e = n - 1;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // element found :
      if (v[mid] == target)
         return true;

      // duplicates on "s,mid,e", SHRINK :
      if (v[s] == v[mid] && v[mid] == v[e])
      {
         s++;
         e--;
         continue; // **** add this
      }

      // LHS sorted?
      if (v[s] <= v[mid])
      {
         if (v[s] <= target && target <= v[mid])
         {
            e = mid - 1;
         }
         else
            s = mid + 1;
      }
      // RHS sorted?
      else
      {
         if (v[mid] <= target && target <= v[e])
         {
            s = mid + 1;
         }
         e = mid - 1;
      }
   }

   return false;
}
int main()
{
   vector<int> v1 = {4, 4, 5, 6, 6, 1, 2, 2, 2, 2, 3, 3};
   cout << " 1 present ? : " << searchInRotatedArray(v1, 1) << endl; // 1 - true

   vector<int> v2 = {4, 4, 4, 4, 2, 3, 4, 4};
   cout << "3 present ? : " << searchInRotatedArray(v2, 3); // 1 - true

   return 0;
}