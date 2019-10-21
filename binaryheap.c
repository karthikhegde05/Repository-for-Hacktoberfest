//MINIMUM HEAP
#include<stdio.h>
void topdownheapify(int A[], int, int);
void bottomupheapify(int A[], int);
void BuildHeap(int A[], int);
void Add(int A[], int* , int);   //int* to update n
void deletemin(int A[], int*); //int* to update n
void decreasekey(int A[], int, int); //2nd int= position of the node(in array), 3rd is updatedkey
void delete(int A[], int, int*); //int=index
int main()
{
	int n=5;
	int A[100]={5,4,3,2,1};
	BuildHeap(A, n);
	//Add(A, &n ,35);
	//deletemin(A, &n);
	//decreasekey(A, 5, 8);
	//delete(A, 1, &n);
	for(int i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}

}
void topdownheapify(int A[], int i, int n)
{
	int l;
	while(2*i+2<n)
	{
		if(A[2*i+1]<=A[2*i+2])
		l=2*i+1;
		else
			l=2*i+2;
		if(A[l]<A[i])
		{
			int t=A[l];
			A[l]=A[i];
			A[i]=t;
			i=l;
		}
		else
			break;
	}
	if(2*i+1==n-1 && A[i]>A[2*i+1])
	{
		int t=A[i];
		A[i]=A[2*i+1];
		A[2*i+1]=t;
	}
}
void bottomupheapify(int A[], int i)
{
	int p=(i-1)/2;
	while(p>=0)
	{
		if(A[i]<A[p])
		{
			int t=A[i];
			A[i]=A[p];
			A[p]=t;
			i=p;
			p=(i-1)/2;
		}
		else 
			break;
	}
}
void BuildHeap(int A[], int n)
{
	for(int i=n/2; i>=0;i--)
		topdownheapify(A, i, n);
}
void Add(int A[], int* n, int k)
{
	A[*n]=k;
	*n+=1;
	bottomupheapify(A, *n-1);
}
void deletemin(int A[], int* n)
{
	int x=A[0];
	*n-=1;
	A[0]=A[*n];
	topdownheapify(A, 0, *n);
}
void decreasekey(int A[], int i, int f)
{
	A[i]=f;
	bottomupheapify(A, i);
}
void delete(int A[], int i, int* n)
{
	decreasekey(A, i, -100000000);
	deletemin(A, n);
}
