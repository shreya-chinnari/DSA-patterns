#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n, int key)
{
   int s = 0, e = n - 1;
   while (s <= e)
   {
      int mid = s + (e - s) / 2;
      if (arr[mid] == key)
         return mid;
      else if (arr[mid] < key)
         // return s = mid + 1; ❌
         s = mid + 1;
      else
         // return e = mid - 1; ❌
         e = mid - 1;
   }
   return -1;
}

int main()
{

   int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
   int key = 6;
   int n = sizeof(arr) / sizeof(arr[0]);

   // return findElement(arr, n, key); ❌
   int index = findElement(arr, n, key);
   cout << "Index of key: " << index << endl;

   return 0;
}