#include <bits/stdc++.h>

int main(){

/**------std::sort(begin,end)----------*/
   int ARR_SIZE = 7;
   int arr[] = {1231,311,1231,31,21314,12,1};

   // std::sort(array_begin,array_end)
   std::sort(arr, arr+ARR_SIZE);

   // check pointer.cpp if confused of the syntax of this for loop 
   for(int* ar=arr ; ar<arr+ARR_SIZE ; ar++)
      cout<<*ar<<endl;

/**------std::upper_bound(begin,end)----------*/
   int ARR1_SIZE = 7;
   int arr1[] = {1231,311,1231,31,21314,12,1};

   // note upper_bound assumed the array is sorted
   // and uses binary search to optimize number of comparisons
   // so this following line without sorting wouldn't work what you expected
   cout<<std::upper_bound(arr1,arr1+ARR1_SIZE,311)-arr1<<endl;

   // after array being sorted
   // 1 12 31 311 1231 1231 21314
   std::sort(arr1,arr1+ARR1_SIZE);
   /** 
    Returns an iterator to the first element in the range [first,last)
    which compares greater than val
    an Iterator is a fancy name for pointer in the context of container 
    and shares very similar properties as a pointer
   */ 
   // to obtain the index, need to do (iterator) pointer arithmetics
   cout<<std::upper_bound(arr1,arr1+ARR1_SIZE,1231)-arr1<<endl;

/**------std::lower_bound(begin,end)----------*/
   /** 
    Returns an iterator to the first element in the range [first,last)
    which compares no less than val
   */ 
   cout<<std::lower_bound(arr1,arr1+ARR1_SIZE,1231)-arr1<<endl;

/**------Bonus: number of appearances of x?----------*/
   /** 
    Combining upper and lower bound, one can find how many times an
    element x appears within the array
   */ 
   cout<<std::upper_bound(arr1,arr1+ARR1_SIZE,1231)-std::lower_bound(arr1,arr1+ARR1_SIZE,1231)<<endl;
   cout<<std::upper_bound(arr1,arr1+ARR1_SIZE,31)-std::lower_bound(arr1,arr1+ARR1_SIZE,31)<<endl;
   cout<<std::upper_bound(arr1,arr1+ARR1_SIZE,2)-std::lower_bound(arr1,arr1+ARR1_SIZE,2)<<endl;


/**------std::lower_bound(begin,end)----------*/


   return 0;
}