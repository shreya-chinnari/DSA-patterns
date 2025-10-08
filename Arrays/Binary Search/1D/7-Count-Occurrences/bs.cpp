#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   int pos = -1;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (v[mid] == key)
      {
         pos = mid;
         e = mid - 1;
      }
      else if (v[mid] < key)
         s = mid + 1;
      else
         e = mid - 1;
   }

   return pos;
}

int lastOcc(vector<int> &v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   int pos = -1;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (v[mid] == key)
      {
         pos = mid;
         s = mid + 1;
      }
      else if (v[mid] < key)
         s = mid + 1;
      else
         e = mid - 1;
   }

   return pos;
}

int countOcc(vector<int> &v, int key)
{
   int first = firstOcc(v, key);
   int last = lastOcc(v, key);

   int count = last - first + 1;

   return count;
}

// TC - O(2 * log(n)) = O(log n)
// because multiplying with 2 doesn't change the growth to exponential (like O(n))

int main()
{
   vector<int> v = {2, 6, 3, 8, 2, 3, 7, 2, 3, 6, 8, 2};
   sort(v.begin(), v.end());
   int count = countOcc(v, 2);
   cout << count;

   return 0;
}