#include <bits/stdc++.h>
using namespace std;

int countOcc(vector<int> &v, int key)
{
   int count = 0;
   for (int i = 0; i < v.size(); i++)
   {
      if (v[i] == key)
         count++;
   }
   return count;
}

// TC - O(n)

int main()
{
   vector<int> v = {2, 6, 3, 8, 2, 3, 7, 2, 3, 6, 8, 2};
   int count = countOcc(v, 2);
   cout << count;

   return 0;
}