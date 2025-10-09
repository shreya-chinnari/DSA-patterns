#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &v)
{
   int n = v.size();

   // check for single element
   if (n == 1)
      return v[0];

   for (int i = 0; i < n; i++)
   {
      // first element
      if (i == 0)
      {
         if (v[i] != v[i + 1])
            return v[0];
      }

      // last element
      if (i == n - 1)
      {
         if (v[i] != v[i - 1])
            return v[n - 1];
      }

      // for other elements
      if (v[i] != v[i - 1] && v[i] != v[i + 1])
         return v[i];
   }

   return -1;
}

// TC - O(n), SC - O(1)

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