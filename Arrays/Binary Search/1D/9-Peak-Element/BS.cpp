#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr)
{
   int n = arr.size();

   // CHECK for single element
   if (n == 1)
      return arr[0];

   // FIRST element
   if (arr[0] > arr[1])
      return arr[0];

   // LAST element-- no peak element in between
   if (arr[n - 1] > arr[n - 2])
      return arr[n - 1];

   // Peak element in the middle somewhere :
   //    LHS of peak element are in ascending order + (even,odd) indexed pairs
   //    RHS of peak element are in descending order + (odd,even) indexed pairs

   int s = 1, e = n - 1; //**

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // peak element
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
         return arr[mid];

      // if [mid] is on LHS, eliminate LHS and move towards Peak
      if (arr[mid] < arr[mid + 1])
         s = mid + 1;
      // if [mid] is on LHS, eliminate LHS and move towards Peak
      else
         e = mid - 1;
   }

   return -1;
}

int main()
{
   vector<int> v1 = {1, 2, 3, 6, 3, 2, 1};
   cout << peakElement(v1);
   vector<int> v2 = {1, 2, 3, 3, 2, 1};
   cout << peakElement(v2);
   vector<int> v3 = {1, 2, 3, 6};
   cout << peakElement(v3);
   vector<int> v4 = {6, 5, 4, 3, 2, 1};
   cout << peakElement(v4);

   return 0;
}