Proyect: Simple shell for Holberton School Uruguay


Description
This project is a simplified version of a shell in C. It interpretes UNIX command lines and handle commands with arguments such as the PATH. Also we implement an exit command to exits the shell and a env command that prints the current enviroment.

Authors

Bruno Dos Santos
Santiago Fernandez

Function implemented 

1) My_getenv

Output: 

2) recorrer_string

Description: A helper function that processes the format string, handling specifiers like %c, %s, %d, %i, and %%. It traverses the format string and calls the appropriate functions to print the corresponding values.

Input: A format string and a list of arguments.

Output: Writes the processed characters or values to the standard output and returns the number of characters printed.

3) manejar_c_s

Description: Handles the %c, %s, and %% format specifiers by printing a character, a string, or a literal %, respectively.

Input: A format specifier and a list of arguments.

Output: Writes the corresponding character or string to the standard output and updates the character count.

4) manejar_casos_i_d

Description: Handles the %d and %i format specifiers by converting an integer to a string and printing it.

Input: A list of arguments (an integer to be printed).

Output: Writes the integer to the standard output, handles special cases like zero and INT_MIN, and updates the character count.

5) contar_digitos

Description: Counts the number of digits in an integer.

Input: An integer.

Output: Returns the number of digits in the integer.

6) crear_espacio

Description: Allocates memory for an integer's string representation based on its size.

Input: An integer and the number of characters needed to store it.

Output: Returns a dynamically allocated string to store the integer, or NULL if memory allocation fails

Requirements:

- C compiler (e.g., GCC)
- Basic knowledge of C programming, including:
- Pointers
- Arrays
- Strings
- malloc and free
- Variadic functions

CASOS DE PRUEBA

A continuación, se muestran algunos ejemplos de uso y los resultados esperados cuando se llama a la función _printf.

Ejemplo 1: Imprimir un carácter
int count;
count = printf("%c\n", 'A');
printf("Caracteres impresos: %d\n", count);

Resultado esperado:

A
Caracteres impresos: 2

Ejemplo 2: Imprimir una cadena de texto
count = printf("%s\n", "Hola Mundo");
printf("Caracteres impresos: %d\n", count);

Resultado esperado:

Hola Mundo
Caracteres impresos: 11

Ejemplo 3: Imprimir un símbolo de porcentaje
count = printf("%%\n");
printf("Caracteres impresos: %d\n", count);

Resultado esperado:

%
Caracteres impresos: 2

Ejemplo 4: Imprimir un número entero
count = printf("%d\n", 123);
printf("Caracteres impresos: %d\n", count);

Resultado esperado:

123
Caracteres impresos: 4

Ejemplo 5: Imprimir un número negativo
count = printf("%i\n", -456);
printf("Caracteres impresos: %d\n", count);

Resultado esperado:

-456
Caracteres impresos: 5

Ejemplo 6: Imprimir un puntero nulo
count = printf("%s\n", NULL);
printf("Caracteres impresos: %d\n", count);

Resultado esperado:

(null)
Caracteres impresos: 7

Ejemplo 7: Imprimir un cero
count = printf("%d\n", 0);
printf("Caracteres impresos: %d\n", count);

Resultado esperado:

0
Caracteres impresos: 2

Ejemplo 8: Imprimir el número cero como entero
count = printf("%i\n", 0);
printf("Caracteres impresos: %d\n", count);

Resultado esperado:

0
Caracteres impresos: 2


Diagrama de flujo del proyecto:
