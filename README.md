This C++ program performs addition and multiplication of two polynomials using a different method than the one taught in class.

Header Includes: The code includes several header files like <iostream>, <stdio.h>, <conio.h>, <ctype.h>, and <malloc.h>. These headers provide functionality for input/output, character manipulation, and dynamic memory allocation.

polinom Structure: A structure called polinom is defined to represent a polynomial. It includes two members: grad (the degree of the polynomial) and coef (an array of integer coefficients).

citpol Function: This function is used to read the degree and coefficients of a polynomial. It takes a pointer to a polinom structure (pol) and a character (ch) to represent the polynomial. It dynamically allocates memory for the coefficient array and then reads the coefficients from the user.

afispol Function: This function is used to display a polynomial. It takes a polinom structure (p) as input and prints the polynomial in a readable format. It skips terms with zero coefficients and avoids printing unnecessary terms like "1*x^0."

suma Function: This function calculates the sum of two polynomials (p and q) and stores the result in a third polynomial (r). It handles cases where the two polynomials have different degrees or where they have the same degree. It dynamically allocates memory for the result polynomial.

produs Function: This function calculates the product of two polynomials (p and q) and stores the result in a third polynomial (r). It allocates memory for the result polynomial and initializes it with zeros before performing the multiplication.

main Function: The main function serves as the entry point of the program. It provides a menu for the user to choose between addition, multiplication, or exiting the program. It repeatedly loops until the user chooses to exit.

For addition, it calls the citpol function to read two polynomials, then calls the suma function to calculate their sum, and finally displays the result using afispol.

For multiplication, it calls the citpol function to read two polynomials, then calls the produs function to calculate their product, and finally displays the result using afispol.

The program uses dynamic memory allocation to manage memory for the coefficients of the polynomials and frees the memory when it's no longer needed to avoid memory leaks.





