#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 100

typedef struct{
	int id;
	char data[MAX];
}frame;

// Fisher yates algorithm to shuffle the frame
void shuffleFrames(frame f[MAX], int n)
{
	int i;
	for(i=n-1; i>=0; i--)
	{
		int j = rand()%(i+1);

		frame temp = f[j];
		f[j] = f[i];
		f[i] = temp;
	}
}

// Insertion sort algorithm to sort frames based on id
void sortFrames(frame f[MAX], int n)
{
	int i, j;
	for(i=1; i<n; i++)
	{
		frame t = f[i];
		j = i-1;
		while(j>=0 && f[j].id > t.id)
		{
			f[j+1] = f[j];
			j = j-1;
		}
		f[j+1] = t;
	}
}

void showFrames(frame f[MAX] , int n ){
	int i;
	printf("\nframe_id \t frame_data \n");
	printf("----------------------------\n");
	for(i=0 ; i < n; i++)
	{
		printf("%d \t\t %s \n", f[i].id, f[i].data);
	}
}

int main()
{
	frame f[MAX];
	int n = 0;     // no of frames
	int fsize;      // size of frame

	char msg[MAX];
	int m = 0; // message iterator
	int i, j;

	printf("Enter a message : ");
	fgets(msg , MAX, stdin);
	msg[strlen(msg)-1] = '\0'; // to remove '\n' from string

	srand(time(NULL));
		// Divide the message into frames
	for(i=0 ; m < strlen(msg) ; i++)
	{
		f[i].id = i;
		fsize = rand()%5+1; // variable Frame size in range [1,5]
		n++;                // count number of frames
				
		strncpy(f[i].data , msg+m , fsize) ;
		m = m+fsize ;
	}
	shuffleFrames(f, n);
	printf("\nShuffled frames:");
	showFrames(f,n);
			
	sortFrames(f, n);
	printf("\nSorted frames:");
	showFrames(f,n);
			
	printf("\nfinal message : ");
	for(i=0; i< n; i++)
	{
		printf("%s", f[i].data);
	}
	printf("\n");
}