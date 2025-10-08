// lower bound = smallest number >= key

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   // 'n' when no LB is present
   int lb = n;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (v[mid] >= key)
      {
         lb = mid;    // potential answer
         e = mid - 1; // might have a smaller LB on LHS
      }

      else
         s = mid + 1; // check RHS
   }
   return lb;
}

int main()
{
   vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

   int lb = lowerBound(v, 5);
   cout << lb; // 4
}