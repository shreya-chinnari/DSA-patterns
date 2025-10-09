#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &v)
{
   int n = v.size();

   // edge cases :

   // single element
   if (n == 1)
      return v[0];
   // first element
   if (v[0] != v[1])
      return v[0];
   // last element
   if (v[n - 1] != v[n - 2])
      return v[n - 1];

   // for other elements, check whether they are on LHS or RHS of the single element
   // LHS of single element : (even,odd) indexed duplicate pairs
   // RHS of single element : (odd,even) indexed duplicate pairs
   //    eliminate that part

   int s = 1, e = n - 2; // **

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // single element
      if (v[mid] != v[mid - 1] && v[mid] != v[mid] + 1)
         return v[mid];

      // LHS of single element,
      if ((mid % 2 == 1 && v[mid] == v[mid - 1]) || (mid % 2 == 0 && v[mid] == v[mid + 1]))
      {
         s = mid + 1; // eliminate LHS
      }
      // RHS of single element,
      if ((mid % 2 == 1 && v[mid] == v[mid + 1]) || (mid % 2 == 0 && v[mid] == v[mid - 1]))
      {
         e = mid - 1;
      }
   }

   return -1;
}

// TC - O(log n), SC - O(1)

int main()
{
   vector<int> v1 = {1, 1, 2, 2, 3, 4, 4, 5, 5};
   cout << singleElement(v1) << endl;

   vector<int> v2 = {1, 2, 2, 3, 3, 4, 4, 5, 5};
   cout << singleElement(v2) << endl;

   vector<int> v3 = {1, 1, 2, 2, 3, 3, 4, 4, 5};
   cout << singleElement(v3) << endl;

   return 0;
}