#include <bits/stdc++.h>
using namespace std;
/***
 * 
Test output (on my machine):
   Merge sort practice tests
   1000000 elements 0.25 sec
      + 0.21
   2000000 elements 0.46 sec
      + 0.20
   3000000 elements 0.66 sec
      + 0.22
   4000000 elements 0.88 sec
      + 0.22
   5000000 elements 1.10 sec
      + 0.22
   6000000 elements 1.31 sec
      + 0.18
   7000000 elements 1.50 sec
      + 0.20
   8000000 elements 1.70 sec
      + 0.25
   9000000 elements 1.95 sec
      + 0.21
   10000000 elements 2.15 sec 
 * 
 * 
 **/

template <typename T>
void merge(T* a, std::size_t begin, std::size_t center, std::size_t end) {
   // imagine three pointers (i,j,t) pointing to start of subarray A & subarray B and buf
   std::size_t i = begin, j = center+1, t = 0;
   // end & begin are inclusive so size = their difference +1
   T* buf = new T[end-begin+1];

   // as long as neither of two pointers reach the end of either array A & B
   while (i <= center && j <= end) {
      // A[i] < B[j] -> move A[i] to buf
      // and increment the pointer to A by 1: i++
      if (a[i] < a[j])
         buf[t++] = a[i++];
      // A[i] >= B[j] -> move B[i] to buf
      // and increment the pointer to B by 1: j++
      else
         buf[t++] = a[j++];
   }

   // at this point, one of two pointers reach end of array A or B
   // just copy and paste the rest of array
   while (j <= end)  buf[t++] = a[j++];
   while (i <= center)  buf[t++] = a[i++];

   // update the whole array
   for (t = 0; t < end-begin+1; t++)
      a[begin+t] = buf[t];

   // delete the temperary array
   delete [] buf;
}

template <typename T>
void merge_sort(T* a, std::size_t begin, std::size_t end) {
   // as long as the array a can be subdivided
   if (begin < end) {
      // split the array into halves: [begin,split] [split+1,end]
      // and split the halves into further halves if possible
      std::size_t split = (begin+end)/2;
      merge_sort(a, begin, split);
      merge_sort(a, split+1, end);
      // once array cannot be subdivided, merge them
      merge(a, begin, split, end);
   }
}

#define SIZE         10000000
#define START        1000000
#define DIFF         1000000

/* merge sort testing */
void test_merge_sort() {

   printf("\nMerge sort practice tests\n");
   uint8_t * a = new uint8_t [SIZE];
   for (uint8_t * i = a; i < a+SIZE; ++i)
      *i = rand()%256;
   float elapsed_time, prev_elapsed_time = 0;

   for (size_t size = START; size <= SIZE; size += DIFF) {
      clock_t begin = clock();
      merge_sort(a, 0, size-1);
      clock_t end = clock();

      elapsed_time = float(end - begin) / CLOCKS_PER_SEC;

      if (prev_elapsed_time != 0)
         printf("\t+ %.2f\n", elapsed_time-prev_elapsed_time);

      prev_elapsed_time = elapsed_time;

      for (uint8_t * i = a; i+1 < a+size; ++i) assert(*i <= *++i);

      printf("%d elements %.2f sec\n", size, elapsed_time);
   }
}

int main(){  
   test_merge_sort();

   return 0;
}