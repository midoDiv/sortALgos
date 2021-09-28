#include<iostream>
#include<time.h>
#include <windows.h>




using namespace std;



void selectionSort(int *tab,const int & length)
{
	for(int i=0;i<=length-2;i++)
	{
		int ppe=i;
		for(int j=i+1;j<=length-1;j++)
		{
			if(tab[j]<tab[ppe])
				ppe=j;
		}
		
		int c=tab[i];
		tab[i]=tab[ppe];
		tab[ppe]=c;
	}
}

void insertionSOrt(int *tab,const int & length){
	for(int i=1;i<length;i++)
	{
		int j=i-1;
		int key=tab[i];
		
		while(j>=0 && tab[j]>key)
		{
			tab[j+1]=tab[j];
			j--;
		}
		tab[j+1]=key;
	}
}

void bubleSort(int *tab,const int &length){
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-1;j++)
		{
			if(tab[j]>tab[j+1])
				{
					int c=tab[j];
					tab[j]=tab[j+1];
					tab[j+1]=c;
				}
		}
	}
}
void rapidSort(int *tab,const int & length){
	int pivot=tab[length-1];
	int c=0,m=0,temp;
	
	if(length<2)
		return;
	while(c<length)
	{
		if(tab[c]<=pivot)
		{
			if(c!=m)
			{
				temp=tab[c];
				tab[c]=tab[m];
				tab[m]=c;
			}
			m++;
		}
		c++;
	}
	rapidSort(tab,m-1);
	rapidSort(tab+m-1,length-m+1);
}

int linearSearch(int *tab,const int & length,const int &element){
	int found=-1;
	
	for(int i=0;i<length;i++)
	{
		if(element==tab[i])
			{
				found=i;
				break;
			}
	}
	
	return found;
}
int binarySearch(int *tab,const int & length,const int & start,const int &element){
	
	if(start<=length)
	{
			int midd=(length-start)/2+start;
			if(tab[midd]==element)
				return midd+1;
		
	else
		{
			if(tab[midd]<element)
				binarySearch(tab,length,midd+1,element);
			else
				binarySearch(tab,length-midd-1,0,element);
		}
	}
	else
			return -1;
	

}

main()
{
	int tab[7]={1,2,3,7,9,19};
	 clock_t tStart = clock();


    	bubleSort(tab,7);


	
	

	cout << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
	
}
