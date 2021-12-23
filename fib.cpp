#include<iostream>


using namespace std;

int Fibonacci(const int & n)
{
	if(n<=1)
		return 1;

	return Fibonacci(n-1)+Fibonacci(n-2);
	
}
main()
{
	int n=3;
	
	cout<<Fibonacci(n);
}
