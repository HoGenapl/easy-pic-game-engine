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
/*
* DESCRIPTION:从
* PARAMETER:
* @s:欲存放字符串的指针(在堆中,由malloc申请的内存)
* @l:总长度
* @f:欲读取的文本
* @offset:偏移量
* @increment:每次的增长量
*
*/
int fgets_p(char* s, int l, FILE* f, int offset, int increment);


int fgets_p(char** s, int l, FILE* f, int offset, int increment)
{
	if (fgets(*s + offset, l, f) == NULL)
	{
		return 0;
	}
	if ((*s)[l - 1] != '\n')
	{
		//创建一个用于复制内容.
		char* cp = (char*)(malloc(sizeof(char) * l));
		memcpy(cp, *s, l);
		l = l + increment;
		if ((*s = (char*)realloc(*s, sizeof(char) * l)) == NULL)
		{
			perror("error:Failed to allocate sufficient memory");
			return -1;
		}
		memcpy(*s, cp, l - increment);
		free(cp);
		(*s)[l - 1] = '\n';
		fgets_p(s, l, f, l - increment - 1, increment);
	}

	return l;
}
