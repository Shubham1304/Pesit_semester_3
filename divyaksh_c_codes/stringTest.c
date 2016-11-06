#include<stdlib.h>
#include<stdio.h>

main()
{
        int len = 0;
        char *str;
        str = (char *)(malloc(sizeof(char)));
        printf("\nEnter the string:\n");
        gets(str);

        while(*(str+len) != '\0')
                len++;
        
        printf("Length:%d\n\n",len);
        printf("%c\n\n",*(str+len));
}
