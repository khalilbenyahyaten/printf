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
  char *str, *string , ch, ch1;
  int j, i, l = 0, n;
va_list valist;
if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);
va_start(valist, format);
str = "";
for (i = 0; format[i] != '\0'; )
{
  if (format[i] != '%')
    {
    str[l] = format[i];
    l++;
    i++;
    }
  else
    {
      i++;
     ch =format[i];
      if (ch == '%')
	  {
	    str[l] = ch;
	    l++;
	  }
      else if (ch == 's')
	  {
	    i++;
	    string = va_arg(valist, char *);
	    if (string == NULL)
	      string = "(null)";
	    for (n = 0; string[n] != '\0'; n++)
	      {
		str[l] = string[n];
		l++;
	      }
	  }
      else if (ch == 'c')
	{
	  ch1 = va_arg(valist, int);  
	    str[l] = ch1;
	  l++;
	  i++;
	}
    }
 }
 for (j = 0; str[j] != '\0'; j++)
   {
     _putchar(str[j]);
   }
va_end(valist);
return (l);
}
