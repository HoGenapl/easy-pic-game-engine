#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif


#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

//每次分配多增加的长度
#ifndef STRING_INCREMENT
#define STRING_INCREMENT 100
#endif
int fgets_p(char* s,long* l, FILE* f,long increment);


int fgets_p(char* s,long* l, FILE* f,long increment=STRING_INCREMENT)
{
	fgets(s,*l,f);
	if(s[*l - 1] != '\n')
	{
		*l = *l + increment;
		//创建一个复制内容.
		if (realloc(s,sizeof(char) * *l) == NULL)
		{
			
			perror("error:Fail to open file");
			return -1;
		}
		s[*l - 1] = '\n';
		fgets_p(s,l,f);
	}
	return 0;
}
