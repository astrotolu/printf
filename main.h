#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * Done by Ibrahim and Segun
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *x,
va_list lists, char buffer[], int flag, int breath, int accur, int sizes);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int counted_char(va_list types, char buffer[],
	int flag, int breath int accur, int sizes);
int print_string(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);
int print_percent(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);
int print_binary(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);
int print_unsigned(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);
int print_octal(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);
int print_hexadecimal(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);
int print_hexa_upper(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);

int print_hexa(va_list types, char map_to[],
char buffer[], int flag, char flag_ch, int breath, int accur, int sizes);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);

/* Funciotns to handle other specifiers */
int get_flag(const char *format, int *x);
int get_breath(const char *format, int *x, va_list lists);
int get_accur(const char *format, int *x, va_list lists);
int get_sizes(const char *format, int *x);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flag, int breath, int accur, int sizes);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flag, int breath, int accur, int sizes);
int write_number(int is_positive, int ind, char buffer[],
	int flag, int breath, int accur, int sizes);
int write_num(int ind, char bff[], int flag, int breath, int accur,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int breath, int flag, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flag, int breath, int accur, int sizes);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
