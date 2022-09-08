struct arrayADT
{
	int capacity;
	int lastIndex;
	int *ptr;
};

struct arrayADT* createArray(int capacity);
int getItem(struct arrayADT *arr, int index);
int setItem(struct arrayADT*, int index, int value);
int editItem(struct arrayADT* , int index, int newValue);
int countItems(struct arrayADT* );
int removeItem(struct arrayADT* , int index);
int search(struct arrayADT*, int item);
void sort(struct arrayADT* arr);
struct arrayADT* createArray(int capacity)
{
	struct arrayADT *arr;
	arr=(struct arrayADT*) malloc(sizeof(struct arrayADT));
	arr->capacity=capacity;
	arr->lastIndex=-1;
	arr->ptr=(int*) malloc(arr->capacity* sizeof(int));
	return(arr);
}

int getItem(struct arrayADT* arr, int index)
{
	if(arr->lastIndex<index<0)
	{
		printf("\n Invalid Index");
		return -1;
	}
	else
	{
		return(arr->ptr[index]);
	}
}

int setItem(struct arrayADT* arr, int index, int value)
{
	int i;
	if(arr->lastIndex==arr->capacity-1)
	{
		printf("overflow");
		return(0);
	}
	if(index<0 || index>arr->lastIndex+1)
	{
		printf("Invalid Index");
		return(0);
	}
	if(index<=arr->lastIndex)
	{
		arr->lastIndex=arr->lastIndex+1;
		i=arr->lastIndex;
		while(i!=index)
		{
			arr->ptr[i]=arr->ptr[i-1];
			i--;
		}
		arr->ptr[index]=value;
		return 1;
	}
	if(index==arr->lastIndex+1)
	{
		arr->lastIndex=arr->lastIndex+1;
		arr->ptr[arr->lastIndex]=value;
		return(1);
	}
}

int editItem(struct arrayADT* arr, int index, int newValue)
{
	if(index<0 || index>arr->lastIndex)
	{
		printf("Invalid Index");
		return(0);
	}
	else
	{
		arr->ptr[index]=newValue;
		return(1);
	}
}

int countItems(struct arrayADT *arr)
{
	return(arr->lastIndex+1);
}

int removeItem(struct arrayADT* arr, int index)
{
	if(index<0 || index>arr->lastIndex)
	{
		printf("Invalid Index");
		return 0;
	}
	if(index<arr->lastIndex)
	{
		int i;
		i=index;
		while(i<arr->lastIndex)
		{
			arr->ptr[i]=arr->ptr[i+1];
			i++;
		}
		arr->lastIndex=arr->lastIndex-1;
		return(1);
	}
	if(index==arr->lastIndex)
	{
		arr->lastIndex=arr->lastIndex-1;
		return 1;
	}
}

int search(struct arrayADT* arr, int item)
{
	int i;
	if(arr->lastIndex==-1)
	return -1;
	for(i=0; i<=arr->lastIndex;i++)
	if(arr->ptr[i]==item)
	return i;
	return -1;
}

void sort(struct arrayADT* arr)
{
	int r,n,i,t;
	n=arr->lastIndex+1;
	for(r=1;r<=n-1;r++)
	{
		for(i=0;i<=n-1-r;i++)
		{
			if(arr->ptr[i]>arr->ptr[i+1])
			{
				t=arr->ptr[i];
				arr->ptr[i]=arr->ptr[i+1];
				arr->ptr[i+1]=t;
			}
		}
	}
}


main()
{
	int i;
	struct arrayADT *arr;
	arr=createArray(5);
	setItem(arr,0,10);
	setItem(arr,1,20);
	setItem(arr,2,30);
	setItem(arr,3,40);
	setItem(arr,1,50);
	editItem(arr,0,90);
	removeItem(arr,4);
	for(i=0; i<countItems(arr);i++)

		printf("%d ", getItem(arr,i));
		sort(arr);
		printf("\n");

	for(i=0; i<countItems(arr);i++)

		printf("%d ", getItem(arr,i));
		sort(arr);
		printf("\n");

		i=search(arr,40);
		if(i==-1)
		//if(search(arr,40)==-1)
		printf("\nItem not found");
		else

			printf("\n Item found at index %d",i);
			getch();
}
