#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <mcheck.h>

#define SWAP(pPtr,rPtr,tmpPtr) \
	{ \
		tmpPtr = *(char **) pPtr; \
		*(char **)pPtr = *(char **)rPtr; \
		*(char **)rPtr = tmpPtr; \
	}

#define SWAP1(a, b, size)                                                      \
  do                                                                              \
    {                                                                              \
      size_t __size = (size);                                                      \
      char *__a = (a), *__b = (b);                                              \
      do                                                                      \
        {                                                                      \
          char __tmp = *__a;                                                      \
          *__a++ = *__b;                                                      \
          *__b++ = __tmp;                                                      \
        } while (--__size > 0);                                                      \
    } while (0)

#define STRCMP(a,b) strcmp(*(char **)a,*(char **)b)

static int MAX_STRING_LENGTH = 22;
static int MAX_THRESH = 5;
static char *outFileName = "b.out";
struct stackNode{
	int startIdx ;
	int endIdx;
	struct stackNode *last_ptr;
	struct stackNode *next_ptr;
};
int swapTimes=0,partitionTime=0;

void quickSortString(int,char []);
int randQuickSortString(char *dataArray[MAX_STRING_LENGTH],int p,int r);
int randPartition(char *dataArray[MAX_STRING_LENGTH ],int p,int r);
int midPartition(char *dataArray[MAX_STRING_LENGTH ],int p,int r,int size);
int insertSort(char *dataArray[MAX_STRING_LENGTH ],int p,int r);
char *strdup1(char const *string);
struct stackNode *addNode(int p,int r);

int main(int argc,char *argv[]){
	char *fileName, dataType;
	int dataSize = 0;

    int ret = mcheck(NULL);
	if (ret){
		fprintf(stderr, "mcheck() failed!n");
		exit(EXIT_FAILURE);
	}


	if(argc == 4){
		dataType = argv[1][0];
		dataSize = atoi(argv[2]);
		fileName = argv[3];
	}else
		printf("Usage:%s s|i|f n fileName\n",argv[0]);

	switch(dataType){
		case 's':
			quickSortString(dataSize,fileName);
			break;
		default:
			printf("Wrong input type :%c \n",dataType);
	}
	return 0;
}

char *strdup1(char const *string){
	char *new_string;

	new_string = malloc( (strlen( string) + 1) * sizeof(char) );
	if( new_string != NULL)
		strcpy(new_string, string);
	return new_string;
};

struct stackNode *addNode(int p,int r){
	struct stackNode *node = (struct stackNode *)malloc( sizeof(struct stackNode));
	node->startIdx = p;
	node->endIdx=r;
	node->last_ptr = NULL;
	node->next_ptr = NULL;
	return node;
}

void quickSortString(int dataSize,char fileName[]){
	char **stringData = (char **)malloc(dataSize * sizeof(char *));
	char tmpString[MAX_STRING_LENGTH]; 
	FILE *fp = fopen(fileName,"r");
	FILE *fpw = fopen(outFileName,"w");
	int i=0,p=0,r=dataSize-1,k=0,j=0;
	int size = sizeof(char *);
	long usednsec;
	struct timespec startTime,endTime;
	struct stackNode *first=NULL,*second=NULL,*current=NULL,*begin=NULL,*tmp1=NULL,*tmp2=NULL;

	for(i=0;fgets(tmpString,MAX_STRING_LENGTH,fp) != NULL;i++){
		stringData[i] = strdup1(tmpString);
	//	printf("%d  %s   %p  \n",i,stringData[i],stringData[i]);
	}

	clock_gettime(CLOCK_REALTIME,&startTime);

	//randQuickSortString(stringData,0,dataSize-1);

	k=0;
	current=addNode(p,r);
	begin=current;
	do{
		tmp1 = current;
		if(current != NULL){
			p = current->startIdx;
			r = current->endIdx;
			if((r-p) > MAX_THRESH){
				i = midPartition(stringData,p,r,size);
				partitionTime++;
				tmp1=current;
				current=current->last_ptr;
				if(p != r-1){
					if(p<i-1)
						first=addNode(p,i-1);
					if(i<r-1)
						second=addNode(i+1,r);
					if (first != NULL){
						if(current != NULL)
							current->next_ptr=first;
						first->last_ptr=current;
						current=first;
					}
					if(second !=NULL){
						if(current != NULL)
							current->next_ptr=second;
						second->last_ptr=current;
						current=second;
					}
				}
				if(tmp1 != NULL){
					free(tmp1);
					tmp1 = NULL;
				}
			}else{
				insertSort(stringData,p,r);
				current=current->last_ptr;
			}
		}else
			break;
		first = NULL;
		second = NULL;
		i=0;
	}while(1);

	clock_gettime(CLOCK_REALTIME,&endTime);
	usednsec = (endTime.tv_sec-startTime.tv_sec)*1000000000+endTime.tv_nsec-startTime.tv_nsec;
	printf("use time : %ld ns\n",usednsec);
	printf("swap times : %ld ns\n",swapTimes);
	printf("partition times : %ld ns\n",partitionTime);
	for(i=0;i<dataSize;i++){
	//	printf("%d  %s   %p  \n",i,stringData[i],stringData[i]);
		fputs(stringData[i],fpw);
		if(stringData[i] != NULL)
			free(stringData[i]);
	//	printf("%d  %s \n",i,stringData[i]);
	}

	printf("2");
	free(stringData);
	/*
	while(current!=NULL){
		first = current->last_ptr;
		free(current);
		current=first;
	}
	*/
	if((i=fclose(fp))!=0)
		printf("close failed,err code %d",i);
	fclose(fpw);
}

int randQuickSortString(char *dataArray[MAX_STRING_LENGTH ],int p,int r){
	int i =0;

	if(p<r){
		i = randPartition(dataArray,p,r);
	//	printf("p  %d  r  %d  rand  %d\n",p,r,i);
		randQuickSortString(dataArray,p,i);
		randQuickSortString(dataArray,i+1,r);
	}
}

int randPartition(char *dataArray[MAX_STRING_LENGTH ],int p,int r){
	int randVal =0,k=0;
	char *mainVal,*tmpVal;
	int i=p,j=p;

	if(p == r-1 && strcmp(dataArray[p],dataArray[r])){
		swapTimes++;
		tmpVal = dataArray[p];
		dataArray[p] = dataArray[r];
		dataArray[r] = tmpVal;
		return r;
	}
	randVal = p + (r-p)>>1;
	mainVal = dataArray[randVal];
	dataArray[randVal] = dataArray[r];
	dataArray[r] = mainVal;
	//printf("p  %d  r  %d  rand  %d\n",p,r,randVal);
	//for(k=p;k<=r;k++)
	//	printf("%s",dataArray[k]);
	for(j=p;j<r;j++){
	//	printf("array : j %d , %s ; mainval : %s  i  %d  \n",j,dataArray[j],mainVal,i);
		if(strcmp(dataArray[j],mainVal) <= 0){
			if(j != i){
				swapTimes++;
	//			printf("i  %d  j  %d\n",i,j);
				tmpVal = dataArray[i];
				dataArray[i] = dataArray[j];
				dataArray[j] = tmpVal;
			}
			i++;
		}
	}
	tmpVal = dataArray[i];
	dataArray[i] = dataArray[r];
	dataArray[r] = tmpVal;
	//for(k=p;k<=r;k++)
	//	printf("%s",dataArray[k]);
	return i;
}

int midPartition(char *dataArray[MAX_STRING_LENGTH ],int p,int r,int size){
	int i=p+1,j=r-1,k=p;
	register char * mainPtr = NULL;
	char * midPtr = NULL;
	char * firstPtr= ((char *)dataArray)+size*p,* lastPtr= ((char *)dataArray) + size*r;
	register char * tmpPtr = NULL;


	mainPtr = lastPtr;
	if(p == r-1 && strcmp(firstPtr,lastPtr)<0){
		SWAP1(firstPtr,lastPtr,size);
		return p;
	}
	midPtr = firstPtr + size*((r-p)>>1);
	if(STRCMP(firstPtr,midPtr)>0)
		SWAP1(firstPtr,midPtr,size);
	if(STRCMP(firstPtr,lastPtr)>0)
		SWAP1(firstPtr,lastPtr,size);
	if(STRCMP(midPtr,lastPtr)>0)
		SWAP1(midPtr,lastPtr,size);

	SWAP1(midPtr,lastPtr,size);
	mainPtr = lastPtr;
	midPtr = lastPtr;
	firstPtr+=size;
	lastPtr-=size;
	while(1){
		while(STRCMP(firstPtr,mainPtr) < 0  && (i <= j)){
			i++;
			firstPtr+=size;
		}
		while(STRCMP(lastPtr,mainPtr)>=0 && j >=i){
			j--;
			lastPtr-=size;
		}
		if(i < j){
			SWAP1(firstPtr,lastPtr,size);
		}else
			break;
	}
	SWAP1(firstPtr,midPtr,size);

    return i;
}
int insertSort(char *dataArray[MAX_STRING_LENGTH ],int p,int r){
	char *tmpVal =NULL;
	int i=0,j=0;

	for(i=p+1;i<=r;i++){
		tmpVal = dataArray[i];
		j=i-1;
	//	printf("array : j %d , %s ; array  :  %d  %s \n",j,dataArray[j],i,dataArray[i]);
		while(j >= p && strcmp(dataArray[j],tmpVal) > 0){
	//		printf("array : j %d , %s ; array  :  %d  %s \n",j,dataArray[j],i,dataArray[i]);
			dataArray[j+1] = dataArray[j];
			j = j-1;
		}
		dataArray[j+1] = tmpVal;
	}
}
