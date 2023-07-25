#include "main.h"

/**
 * _printf - Print formatted output to stdout.
 * @format: Format string containing text and conversion specifiers.
 * This function parses the format string and prints output
 * based on any conversion specifiers. Supported specifiers are
 * c, s, and %.
 * Return: Number of characters printed.
*/

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *p = format;
va_start(args, format);
while (*p != '\\0')
{
switch (*p)
{
case '%':
p++;
switch (*p)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
count += puts(va_arg(args, char *));
break;
case '%':
count += putchar('%');
break;
default:
printf("Error: invalid specifier %c\\n", *p);
break;
}
p++;
break;
default:
count += putchar(*p);
p++;
break;
}
}
va_end(args);
return (count);
}
