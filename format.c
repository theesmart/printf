#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int my_printf(const char* format, ...)
{
    va_list arg_list;
    va_start(arg_list, format);

    int count = 0;
    char c;
    const char* s;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    c = (char) va_arg(arg_list, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    s = va_arg(arg_list, const char*);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // ignore unknown conversion specifiers
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(arg_list);
    return count;
}

