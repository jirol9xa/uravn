#include <stdio.h> 
#include <math.h>

struct Answers{
	int amount;
	double x[2];
	double coefficient_a;
	double coefficient_b;
	double coefficient_c;
};

void input(struct Answers*); // для ввода данных
void eatline(); // для отбрасывания отсальной части строки, если данные будут введены с мусором
void wrong_input(); // на случай неправильного ввода
void solve_equation(struct Answers* ans); // решение уравнения
void linear_equation(struct Answers* ans); // если а == 0
void the_quadratic_equation(struct Answers* ans); // решение через дискриминант
void print_answers(struct Answers*);
const double zero = 1e-20;



int main(void) {
	struct Answers ans = { 0,
		                  {0, 0},
	                       0, 0 }; // первый элемент является числом решений
	// второй и третьий равны значениям х, если они существуют
	// последние три отвечают за коэффициенты уравнения
	printf("Hi! This program solves quadratic equations a*x^2 + b*x + c = 0 \n");
	input(&ans);
	printf("Quadratic equation: %lg*x^2 + %lg*x + %lg = 0 \n", ans.coefficient_a, ans.coefficient_b, ans.coefficient_c);
	solve_equation(&ans);
	print_answers(&ans);
	printf("The equation is solved :)");
	return 0;
}




void input(struct Answers* ans) {
	printf("Now enter the values a, b, c \n");
	printf("enter a \n");
	scanf("%lf", &(ans->coefficient_a));
	eatline();
	printf("enter b \n");
	scanf("%lf", &(ans->coefficient_b));
	eatline();
	printf("enter c \n");
	scanf("%lf", &(ans->coefficient_c));
	eatline();
	return;
}


void eatline() {
	while (getchar() != '\n') {
		continue;
	}
}


void wrong_input() {
	printf("Just enter a number \n");
}


void solve_equation(struct Answers* ans) {
	if (fabs(ans->coefficient_a) < zero) {
		linear_equation(ans);
	}
	else {
		the_quadratic_equation(ans);
	}
}


void linear_equation(struct Answers* ans) {
	if (fabs((*ans).coefficient_b) < zero) {
		if (fabs((*ans).coefficient_c) < zero) {
			(*ans).amount = 3;
		}
	}
	else {
		(*ans).amount = 1;
		(*ans).x[0] = -(*ans).coefficient_c / (*ans).coefficient_b;
	}
}


void the_quadratic_equation(struct Answers* ans) {
	double diskr = ans->coefficient_b * ans->coefficient_b -4 * ans->coefficient_a * ans->coefficient_c;
	if (diskr < 0) {
		ans->amount = 0;
	}
	else if (fabs(diskr - 0) < zero) {
		ans->amount = 1;
		ans->x[0] = -(ans->coefficient_b) / (2 * (ans->coefficient_a));
	}
	else {
		ans->amount = 2;
		ans->x[0] = (-(ans->coefficient_b)-sqrt(diskr)) / (2 * (ans->coefficient_a));
		ans->x[1] = (-(ans->coefficient_b)+sqrt(diskr)) / (2 * (ans->coefficient_a));
	}
}

void print_answers(struct Answers* ans) {
	if (ans->amount == 3) {
		printf("The equation has an infinite number of solutions \n");
	}
	else {
		printf("The equation has %d solutions ", ans->amount);
		for (int i = 0; i < ans->amount; i++) {
			printf("x%d = %lg ", i + 1, ans->x[i]);
		}
		printf("\n");
	}
}
