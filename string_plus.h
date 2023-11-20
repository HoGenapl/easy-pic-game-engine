#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif


#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif


#ifndef STRING
#define STRING
#include <string.h>
#endif

//每次分配多增加的长度
#ifndef STRING_INCREMENT
#define STRING_INCREMENT 100
#endif

int fgets_p(char*,int, FILE*, int);


int fgets_p(char* s,int l, FILE* f, int increment)
{
	fgets(s,l,f);
	if(s[l - 1] != '\n')
	{
		//创建一个用于复制内容.
		char *cp = (char *)(malloc(sizeof(char) * l));
		memcpy(cp,s,l);
		l = l + increment;
		if (realloc(s,sizeof(char) * l) == NULL)
		{
			perror("error:Fail to open file");
			return -1;
		}
		memcpy(s,cp,l - increment);
		free(cp);
		s[l - 1] = '\n';
		fgets_p(s + l - increment - 1,increment,f,increment);
	}
	
	return l;
}
