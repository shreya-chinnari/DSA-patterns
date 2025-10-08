#include <bits/stdc++.h>
using namespace std;

int first(vector<int> v, int key)
{
   int n = v.size();
   int pos = -1;

   // search from beginning
   for (int i = 0; i < n; i++)
   {
      if (v[i] == key)
      {
         pos = i;
         break; // important, otherwise will keep looping and show firstOcc = 6
      }
   }
   return pos;
}

int last(vector<int> v, int key)
{
   int n = v.size();
   int pos = -1;

   // search from end
   for (int i = n - 1; i >= 0; i--)
   {
      if (v[i] == key)
      {
         pos = i;
         break;
      }
   }

   return pos;
}

int main()
{
   vector<int> v = {2, 6, 6, 9, 3, 4, 6, 8, 9};
   cout << "first occ : " << first(v, 6) << endl; // 1
   cout << "last occ : " << last(v, 6);           // 6

   return 0;
}

// tc = O(2n)