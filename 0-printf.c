#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * _printf - produces output according to a format.
 * @format : const char
 */ 
int _printf(const char *format, ...)
{
char *str = "", *string = "", *ch = "", *final;
int i, j, k, l = 0, n, m;
va_list valist;
va_start(valist, format);
 i = 0;
 l = 0;
for (i = 0; format[i]; i++)
{
if (format[i] != '%')
{
str[l] = format[i];
l++;
}
else
{
k = i;
for (j = 0; j <= 1; j++)
{
ch[j] = format[k];
k++;
}
switch (ch[1])
{
case '%':
{
str[l] = '%';
l++;
i = i + 2;
break;
}
case 's':
{
string = va_arg(valist, char *);
for ( n = 0; string[n]; n++)
{
str[l] = string[n];
}
l = l + n - 1;
break;
}
case 'c':
{
str[l] = va_arg(valist, int);
l++;
break;
}
}
}
}
final = malloc(sizeof(char) * l);
for (m = 0; m <= l; m++)
final[m] = str[m];
puts(final);
free (final);
va_end(valist);
return (l);
}
