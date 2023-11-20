#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef STRING
#define STRING
#include <string.h>
#endif

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef True
#define True 1
#endif

#ifndef False
#define False 0
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

int read_map(char* name);
/*
 * DESCRIPTION:搜索两个相同字符中间的长度
 * PARAMETER:
 * @str	要搜索的字符串
 * @c	要查找的字符
 * EXAMPLE: @str = "*find*"
 * 			@c = '*'
 * 			return = 4
 * RETURN:返回两个相同字符中间的长度
 */
long duplicate_length(char *str,char c);

extern char* f_part;
int read_map(char* name)
{
	FILE* f = NULL;
	f = fopen(name,"r");
	if(f == NULL)
		return -1;
	while(f != NULL)
	{
		;
	}
	fclose(f);
	return 0;
}
long duplicate_length(char *str,char c)
{
	long length = 0;
	int t = 0;
	while(*str != '\0')
	{
		length++;
		if(*str == c)
		{
			t++;
			length--;
			if(t == 2)
				break;	
		}
	}
	return length;
}
