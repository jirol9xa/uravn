#include <stdio.h> 
#include <math.h>

struct Answers{
	int amount;
	double x[2];
};

struct Coefficients{
	double a;
	double b;
	double c;
};

void input(struct Coefficients*); // для ввода данных
void eatline(); // для отбрасывания отсальной части строки, если данные будут введены с мусором
void wrong_input(); // на случай неправильного ввода
void solve_equation(struct Answers* ans, struct Coefficients* Coef); // решение уравнения
void linear_equation(struct Answers* ans, struct Coefficients* Coef); // если а == 0
void the_quadratic_equation(struct Answers* ans, struct Coefficients* Coef); // решение через дискриминант
void print_answers(struct Answers*);
const double zero = 1e-20;



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




void input(struct Coefficients* Coef) {
	printf("Now enter the values a, b, c \n");
	printf("enter a \n");
	scanf("%lf", &(Coef->a));
	eatline();
	printf("enter b \n");
	scanf("%lf", &(Coef->b));
	eatline();
	printf("enter c \n");
	scanf("%lf", &(Coef->c));
	eatline();
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
		(*ans).x[0] = -(*Coef).c / (*Coef).b;
	}
}


void the_quadratic_equation(struct Answers* ans, struct Coefficients* Coef) {
	double diskr = Coef->b * Coef->b -4 * Coef->a * Coef->c;
	if (diskr < 0) {
		ans->amount = 0;
	}
	else if (fabs(diskr - 0) < zero) {
		ans->amount = 1;
		ans->x[0] = -(Coef->b) / (2 * (Coef->a));
	}
	else {
		ans->amount = 2;
		ans->x[0] = (-(Coef->b)-sqrt(diskr)) / (2 * (Coef->a));
		ans->x[1] = (-(Coef->b)+sqrt(diskr)) / (2 * (Coef->a));
	}
}

void print_answers(struct Answers* ans) {
	switch (ans->amount) {
	case 0:
		printf("The equation has no solutions \n");
		break;
	case 1:
		printf("The equation has one solution x = %lg \n", ans->x[0]);
		break;
	case 2:
		printf("The equation has one solution x1 = % lg   x2 = %lg \n", ans->x[0], ans->x[1]);
		break;
	default:
		printf("The equation has an infinite number of solutions \n");

	}
}
