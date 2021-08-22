//тела функций
#include "functions.h"

void input(struct Coefficients* Coef) {
	printf("Now enter the values a, b, c \n");
	printf("enter a \n");
	while(scanf("%lf", &(Coef->a)) !=1){
        wrong_input();
        eatline();
    }
	printf("enter b \n");
	while(scanf("%lf", &(Coef->b)) !=1){
        wrong_input();
        eatline();
    }
	eatline();
	printf("enter c \n");
	while(scanf("%lf", &(Coef->c)) !=1){
        wrong_input();
        eatline();
    }
}


void eatline() {
	while (getchar() != '\n') {
		continue;
	}
}


void wrong_input() {
	printf("Just enter a number \n");
}


void solve_equation(struct Answers* ans, struct Coefficients* Coef) {
	if (fabs(Coef->a) < zero) {
		linear_equation(ans, Coef);
	}
	else {
		the_quadratic_equation(ans, Coef);
	}
}


void linear_equation(struct Answers* ans, struct Coefficients* Coef) {
	if (fabs((*Coef).b) < zero) {
		if (fabs((*Coef).c) < zero) {
			(*ans).amount = 3;
		}
		else {
			(*ans).amount = 0;
		}
	}
	else {
		(*ans).amount = 1;
		(*ans).roots[0] = -(*Coef).c / (*Coef).b;
	}
}


void the_quadratic_equation(struct Answers* ans, struct Coefficients* Coef) {
	double diskr = Coef->b * Coef->b - 4 * Coef->a * Coef->c;
	if (diskr < 0) {
		ans->amount = 0;
	}
	else if (fabs(diskr - 0) < zero) {
		ans->amount = 1;
		ans->roots[0] = -(Coef->b) / (2 * (Coef->a));
	}
	else {
		ans->amount = 2;
		ans->roots[0] = (-(Coef->b) - sqrt(diskr)) / (2 * (Coef->a));
		ans->roots[1] = (-(Coef->b) + sqrt(diskr)) / (2 * (Coef->a));
	}
}

void print_answers(struct Answers* ans) {
	switch (ans->amount) {
	case 0:
		printf("The equation has no solutions \n");
		break;
	case 1:
		printf("The equation has one solution x = %lg \n", ans->roots[0]);
		break;
	case 2:
		printf("The equation has one solution x1 = % lg   x2 = %lg \n", ans->roots[0], ans->roots[1]);
		break;
	default:
		printf("The equation has an infinite number of solutions \n");

	}
}
