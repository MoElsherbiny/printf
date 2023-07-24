#include <stdio.h>
#include <stdarg.h>

/**
 * _printf Prints formatted output
 * This function is similar to the standard printf function, but
 * supports only a limited set of conversion specifiers: c, s, and %.
 * @param format A constant character pointer that contains the format string.
 * @return The number of characters printed (excluding the null byte).
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
