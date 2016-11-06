#include<stdio.h>
#include<stdlib.h>

int stringLength(char *str)
{
        int len = 0;
        while(*(str+len) != '\0')   //str[len]
        {
                len++;
        }

        return len;
}

int searchPattern(char *str,char *pat,int strLen,int patLen)
{
        int i = 0,k = 0;
        while(i<strLen)
        {
                k = 0;
                if(*(str+i) == *(pat+k))
                {
                        while(k<patLen)
                        {
                                if(*(pat+k) == *(str+i+k))
                                        k++;
                                else
                                        break;
                        }

                        if(k == patLen)
                                return i;
                }
                i++;
        }

        return -1;
}

int replacePattern(char *str,char *rep,int strLen,int patLen,int repLen,int position)
{
        int i = 0,j = 0;

        while(i<patLen)
        {
                j = position;
                while(j<strLen)
                {
                        *(str+j) = *(str+j+1);
                        j++;
                }
                strLen--;
                i++;
        }

        //printf("Main String:%s\n",str);

        i = 0;
        while(i<repLen)
        {
                j = strLen-1;
                while(j>=position)
                {
                        *(str+j+1) = *(str+j);
                        j--;
                }
                *(str+position) = *(rep+i);
                position++;
                strLen++;
                i++;
        }

        return strLen;
}

char *readString()
{

}

main()
{
        char *str,*pat,*rep;
        str = (char *)(malloc(1000*sizeof(char)));
        pat = (char *)(malloc(1000*sizeof(char)));
        rep = (char *)(malloc(1000*sizeof(char)));

        int strLen = 0,patLen = 0,repLen = 0,position;

        printf("\n\nSTRING OPERATIONS\n\n");
        printf("Enter the main string:\n");
        gets(str);
        printf("Enter the pattern string:\n");
        gets(pat);
        printf("Enter the replace string:\n");
        gets(rep);

        printf("Length\n\n");
        strLen = stringLength(str);
        patLen = stringLength(pat);
        repLen = stringLength(rep);

        printf("Searching\n\n");
        position = searchPattern(str,pat,strLen,patLen);

        if(position == -1)
                printf("Pattern:%s\nNot present in main string:%s\n\n",pat,str);

        else
        {
                printf("Replace\n\n");
                strLen = replacePattern(str,rep,strLen,patLen,repLen,position);
        }

        printf("Main String:%s\n",str);
        printf("Pattern String:%s\n",pat);
        printf("Replace String:%s\n",rep);

}
