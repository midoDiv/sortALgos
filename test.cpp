#include<iostream>
using namespace std;


main()
{
	int tab[6]={1,2,2,3,4,5};
	int n=6,k=0,cmpt=0;
	
	for(int i=0;i<n;i++)
	{
		int element=tab[i];
		for(int j=0;j<n;j++)
		{
			tab[k]=tab[j];
			if(tab[j]!=element)
				k++;
			else
				{
					cmpt++;
					if(cmpt<=1)
						k++;
				}
		}
		n=k;
					
	}
	
	for(int i=0;i<k;i++)
		cout<<tab[i]<<" ; ";
}
