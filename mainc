#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>
#include "functions.h"
#include "functions_body.h"



int main(void) {
	struct Answers ans = { 0,
						  {0, 0} }; // первый элемент является числом решений
	// второй и третьий равны значениям х, если они существуют
	struct Coefficients Coef = { 0, 0, 0 };
	printf("Hi! This program solves quadratic equations a*x^2 + b*x + c = 0 \n");
	input(&Coef);
	printf("Quadratic equation: %lg*x^2 + %lg*x + %lg = 0 \n", Coef.a, Coef.b, Coef.c);
	solve_equation(&ans, &Coef);
	print_answers(&ans);
	printf("The equation is solved :)");
	return 0;
}
