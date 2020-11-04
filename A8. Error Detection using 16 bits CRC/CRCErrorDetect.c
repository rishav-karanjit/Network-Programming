# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define MAX 30

/* crc(dividend , divisor, remainder) */
void crc(char *data, char *gen, char *rem)
{
    int i, j ;
    int dwordSize = strlen(data)-(strlen(gen)-1) ; // dataword size
    char out[MAX]; // xored val after each step

    strcpy(out, data);
    
    /* Perform XOR on the msg */
    for(i=0; i<dwordSize ; i++) //i=XOR value in each step
    {
        if(out[i]=='0') continue ; //If dividend is 0 quentient is 0
        for(int j = 0 ; j<strlen(gen) ; j++){ //j is each digit of diviend
            out[i+j] = (gen[j] == out[i+j] ? '0' : '1') ; 
        }
    }

    // strncpy(destination, start_idx, size) 
    strncpy(rem , out+dwordSize , strlen(gen)-1); // rem = last strlen(gen)-1 bits of out
    rem[strlen(gen)-1] = '\0' ;
}

int main()
{
    int i, j;
    char dword[MAX]; // dataword
    char augWord[MAX]; // augmented dataword
    char cword[MAX]; // codeword
    char rem[MAX]; // remainder from crc
    char recv[MAX]; // received message 
    char gen[MAX] = "10001000000100001"; // crc-16 (17 bits)

    printf("\nCRC-16 Generator : x^16 + x^12 + x^5 + 1 ");
    printf("\nBinary Form      : %s", gen);

    printf("\n\nEnter Dataword   : ");
    scanf("%s", dword);

    strcpy(augWord, dword);
    for(i=0; i<strlen(gen)-1; i++)
    {
        strcat(augWord, "0");
    }
    printf("\nAugmented dataword is   : %s",augWord);

    crc(augWord, gen, rem);

    strcpy(cword, dword);
    strcat(cword, rem);
    printf("\n\nFinal data transmitted  : %s", cword);

    printf("\n\nEnter the data received : ");
    scanf("%s", recv);
    if(strlen(recv) < strlen(cword))
    {
        printf("\n Invalid input \n");
        exit(0);
    }

    crc(recv, gen, rem);

    printf("\nSyndrome = %s ", rem);

    for(i=0; i<strlen(rem); i++)
    {    
        if( rem[i] == '1') 
        {
            printf("\nError occured !!! Corrupted data received.\n");
            exit(0);
        }
    }
    printf("\nNo Error. Data received successfully.\n");
}
