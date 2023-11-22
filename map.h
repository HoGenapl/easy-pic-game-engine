
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

#ifndef STRING_PLUS
#define STRING_PLUS
#include "string_plus.h"
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
long duplicate_length(char* str, char c);

extern char* f_part;
int read_map(char* name)
{
	long s_l;	//两字符之间的长度
	FILE* f = NULL;
	int l_tem_text = 2;
	char* tem_text = (char*)malloc(sizeof(char) * l_tem_text);	//存储fgets的字符串

	*(tem_text + l_tem_text - 1) = '\n';
	f = fopen(name, "r");

	if (f == NULL)
	{
		perror("error:Fail to open file");
		return -1;
	}
	while (f != NULL)
	{
		l_tem_text = fgets_p(&tem_text, l_tem_text, f, 0, 100);
		if (!l_tem_text)
			break;
		s_l = duplicate_length(tem_text, '!');
		printf("%ld\n", s_l);
	}
	fclose(f);
	free(tem_text);
	return 0;
}
long duplicate_length(char* str, char c)
{
	long length = 0;
	int t = 0;
	while (*str != '\0')
	{
		if (t == 1)
			length++;
		if (*str == c)
		{
			t++;
			length--;
			if (t == 2)
				return ++length;
		}
		str++;
	}
	return length;
}
