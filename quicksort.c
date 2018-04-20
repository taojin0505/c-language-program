#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

static int MAX_STRING_LENGTH = 22;
static char *outFileName = "b.out";

void quickSortString(int,char []);
int randQuickSortString(char *dataArray[MAX_STRING_LENGTH],int p,int r);
int randPartition(char *dataArray[MAX_STRING_LENGTH ],int p,int r);
char *strdup1(char const *string);

int main(int argc,char *argv[]){
	char *fileName, dataType;
	int dataSize = 0;

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

	new_string = malloc( (strlen( string)) * sizeof(char) );
	if( new_string != NULL)
		strcpy(new_string, string);
	return new_string;
};

void quickSortString(int dataSize,char fileName[]){
	char **stringData = (char **)malloc(dataSize * sizeof(char *));
	char tmpString[MAX_STRING_LENGTH]; 
	FILE *fp = fopen(fileName,"r");
	FILE *fpw = fopen(outFileName,"w");
	int i=0,p=0,r=dataSize-1,k=0,t=0;
	long usednsec;
	struct timespec startTime,endTime;
	long *positionArray = (long * )malloc(dataSize * sizeof(long));

	for(i=0;fgets(tmpString,MAX_STRING_LENGTH,fp) != NULL;i++){
		stringData[i] = strdup1(tmpString);
	//	printf("%d  %s",i+1,stringData[i]);
	}

	clock_gettime(CLOCK_REALTIME,&startTime);

	//randQuickSortString(stringData,0,dataSize-1);

	for(i=0;i<dataSize;i++)
		positionArray[i] = -1;
	k=r;
	while(p<r){
	//	printf("before: p  %d  k  %d  i %d\n",p,k,i);
		i = randPartition(stringData,p,k);
	//	printf("after :p  %d  k  %d  i %d\n",p,k,i);
	//	printf("out \n");
	//	for(t=p;t<=10 && k<10;t++)
	//		printf("  %d   %d ",t,positionArray[t]);
	//	printf("\n");
		if(k<p)
			exit(0);
		positionArray[i] = i;
		if(i == p+1){
			if( i == k || i == k-1){
				positionArray[p] = p;
			//	printf("in  \n");
			//	for(t=p;t<=10 && k<10;t++)
			//		printf("  %d   %d ",t,positionArray[t]);
			//	printf("\n");
				if(i == k-1)
					positionArray[k] = k;
				while(p++ < r)
					if(positionArray[p] <0 && positionArray[p+1] < 0 )
						break;
					else
						positionArray[p] = p;
				for(k = p ; positionArray[k] < 0 && k <= r;k++);
				k--;
			}else
				p = i+1;
		}else if( i > p+1){
			k = i-1;
		}else
			if(i<k-1)
				p = i+1;
			else{
				positionArray[k] = k;
				while(p++ < r)
					if(positionArray[p] <0 && positionArray[p+1] < 0 )
						break;
					else
						positionArray[p] = p;
				for(k = p ; positionArray[k] < 0 && k <= r;k++);
				k--;
			}
	}

	clock_gettime(CLOCK_REALTIME,&endTime);
	usednsec = (endTime.tv_sec-startTime.tv_sec)*1000000000+endTime.tv_nsec-startTime.tv_nsec;
	printf("use time : %ld ns\n",usednsec);
	for(i=0;i<dataSize;i++){
	//	printf("%d  %s \n",i,stringData[i]);
		fputs(stringData[i],fpw);
		free(stringData[i]);
	}

	free(*stringData);
	free(positionArray);
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
	struct timespec time_ns;

	clock_gettime(CLOCK_REALTIME,&time_ns);
	srand(time_ns.tv_nsec);
	randVal = p + abs(rand()%(r-p));
	mainVal = dataArray[randVal];
	dataArray[randVal] = dataArray[r];
	dataArray[r] = mainVal;
	//for(k=p;k<=r;k++)
	//	printf("%s",dataArray[k]);
	for(j=p;j<r;j++){
	//	printf("p  %d  r  %d  rand  %d\n",p,r,randVal);
	//	printf("array : j %d , %s ; mainval : %s  i  %d  \n",j,dataArray[j],mainVal,i);
		if(strcmp(dataArray[j],mainVal) <= 0){
			if(j != i){
	//			printf("i  %d  j  %d\n",i,j);
				tmpVal = dataArray[i];
				dataArray[i] = dataArray[j];
				dataArray[j] = tmpVal;
			}
			i = i + 1;
		}
	}
	tmpVal = dataArray[i];
	dataArray[i] = dataArray[r];
	dataArray[r] = tmpVal;
	//for(k=p;k<=r;k++)
	//	printf("%s",dataArray[k]);
	return i;
}
