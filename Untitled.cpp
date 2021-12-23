#include<iostream>

using namespace std;



main()
{
  int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;
   
   cout<<*pptr<<endl<<ptr;
	
	
}
