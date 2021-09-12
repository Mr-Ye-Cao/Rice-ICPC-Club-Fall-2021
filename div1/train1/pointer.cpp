#include <bits/stdc++.h>

int main(){
   /** -------- Array and pointer --------**/
   // p is pointer to the beginning slot [1]
   int  p[6]={1,2,3,4,5,6};

   // address of slot [1]
   // 140732718962880
   printf("%ld\n",p);

   // dereference the content of slot [1]: 1
   // 1
   printf("%ld\n",*p);


   /** -------- Pointer Arithmetics --------**/
   // (p+2) moves 2 unit(here int) address forward the array p
   // then cast (int *) the address and store it in pointer q
   // here q points at address of slot [3]
   int  *q=(int *)(p+2);

   // address of slot [3]
   // 140732718962888
   // note that address difference is 140732718962888-140732718962880=8
   // this is because each unit length of int  is 4 bytes
   // on the other hand, if long, the unit length would be 8 bytes
   printf("%ld\n",q);

   // derefence pointer q 
   // 3
   printf("%ld\n",*q);

   // amazingly result of pointer difference directly without dereference
   // is same as content difference after dereference
   // 2
   printf("%ld\n",q-p);
   // 2
   printf("%ld\n",*q-*p);



   /** -------- Another example of array & pointer --------**/
   int  var[3] = {10, 100, 200};
   int  *ptr;

   // let us have array address in pointer.
   ptr = var;
   
   for (int i = 0; i < 3; i++) {
      // address is incremented 4 bytes each time
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;

      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;

      // pointer arithmetic increments the address inside array one slot at a time
      ptr++;
   }


   return 0;
}