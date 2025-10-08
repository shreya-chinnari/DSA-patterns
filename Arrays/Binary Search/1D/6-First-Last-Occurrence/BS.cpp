#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   int pos = -1; // element doesn't exist

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

int lastOcc(vector<int> v, int key)
{
   int n = v.size();
   int s = 0, e = n - 1;

   int pos = -1; // element doesn't exist

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

pair<int, int> first_last_occ(vector<int> &v, int key)
{
   int first = firstOcc(v, key);
   int last = lastOcc(v, key);

   return make_pair(first, last);
}

int main()
{
   vector<int> v = {1, 3, 5, 2, 7, 5, 2, 9, 5, 2, 6};
   pair<int, int> first_last = first_last_occ(v, 5);
   int key = 5;

   cout << "for key: " << key << endl;
   cout << "first : " << first_last.first << endl;
   cout << "last : " << first_last.second;

   return 0;
}