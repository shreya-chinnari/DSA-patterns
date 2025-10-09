#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &v)
{
   int n = v.size();

   int ans = 0;

   for (int i = 0; i < n; i++)
   {
      ans = ans ^ v[i];
   }
   return ans;
}

// TC - O(n)

int main()
{
   vector<int> v1 = {1, 1, 2, 2, 3, 4, 4, 5, 5};
   cout << singleElement(v1) << endl;

   return 0;
}