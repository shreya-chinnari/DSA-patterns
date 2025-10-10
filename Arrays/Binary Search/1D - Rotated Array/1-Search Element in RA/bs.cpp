#include <bits/stdc++.h>
using namespace std;

// Array is ASCENDING
// no duplicates, only DISTINCT elements

// ---------------------------

// check which side (LHS/RHS) is sorted,
// check if the [KEY] is present in the sorted part,
//    - if yes, eliminate the unsorted part
//    - if no, eliminate the sorted part

// returning the INDEX of the element
int searchInRotatedArray(vector<int> &v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (v[mid] == key)
         return mid;

      // LHS sorted?
      if (v[s] <= v[mid])
      {
         // "key" present in LHS?
         if (v[s] <= key && key <= v[mid])
         {
            e = mid - 1; // YES : search in LHS
         }
         else
            s = mid + 1; // NO : search in RHS
      }

      // RHS sorted?
      else
      {
         if (v[mid] <= key && key <= v[e])
         {
            s = mid + 1;
         }
         else
            e = mid - 1;
      }
   }
   return -1;
}

int main()
{
   vector<int> v = {4, 5, 6, 1, 2, 3, 3};

   cout << "index of 1 : " << searchInRotatedArray(v, 1);

   return 0;
}