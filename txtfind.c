#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
int getLine(char s[])
{
    int i;
    char chline = '\0';
    for (i = 0; i <LINE ; ++i)
    {
        scanf("%c",&chline);
        if (chline!='\r')
        {
            *(s+i)=chline;
        }
        if(chline=='\n')
        {
            *(s+i)='\0';
            break;
        }
    }
    return strlen(s);
}
int getword(char w[]){
    int i;
    char chword = '\0';
    for (i = 0; i <WORD ; i++)
    {
        scanf("%c",&chword);
        if (chword!='\r')
        {
            *(w+i)=chword;
        }
        if(chword=='\n' ||  chword=='\t' || chword==' ')
        {
            *(w+i)='\0';
            break;
        }
    }
    return strlen(w);
}
int substring(char*str1, char*str2)
{
    int lenstr1=strlen(str1);
    int lenstr2=strlen(str2);
    int i,j,counter;
    for ( i = 0; i <=(lenstr1-lenstr2); i++)
    {
        counter=0;
        for ( j = 0; j < lenstr2; j++)
        {
            if (*(str1+i+j)==*(str2+j))
            {
                counter++;
            }
            if (counter==lenstr2)
            {
                return 1;
            }
        }
    }
return 0;
}   
int similar(char*s , char*t , int n )
{
    int lens=strlen(s);
    int lent=strlen(t);
    if (lens-lent!=n)
        return 0;
    int i=0,j=0;
    for(i=0;i<lens;i++)
    {
        if(j<lent)
        {
            if(*(s+i)==*(t+j))
             j++;
        }
        else break;
    }
    if (lent==j)
    return 1;
return 0;
}
void print_lines(char *str)
{
    char printline[LINE]={0};
    int size = getLine(printline);
    while( size > 0)
    {
        if (substring(printline,str))
        {
            printf("%s\n",printline);
        }
        size = getLine(printline);
    }
}
void print_similar_words(char * str) {
     char wordprint[WORD] = {0};
     int size=getword(wordprint);
     while(size>0)
     {
     if (similar(wordprint, str, 1) ==1|| similar(wordprint, str, 0)==1)
     printf("%s\n", wordprint);
     size=getword(wordprint);
     }
}
int main()
{
    char arrword[WORD]={ 0 };
    char yourchoice;
    getword(arrword);
    scanf("%c\n",&yourchoice);
    if (yourchoice=='a')
    {
        print_lines(arrword);
    }
    else if (yourchoice=='b')
    {
        print_similar_words(arrword);
    }
    return 0;
}
