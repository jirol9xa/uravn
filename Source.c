#include <stdio.h> 
#include <math.h>
void input(double *a, double*b, double*c); // для ввода данных
void eatline(); // для отбрасывания отсальной части строки, если данные будут введены с мусором
void wrong_input(); // на случай неправильного ввода
struct answers{
	int amount;
	double x1;
	double x2;
};

void solution(struct answers* ans, double, double, double); // решение уравнения
void solution_without_a(struct answers* ans, double b, double c); // если а == 0
void solution_without_b(struct answers* ans, double a, double c); // если b == 0
void solution_without_c(struct answers* ans, double a, double b); // если c == 0
void classic(struct answers* ans, double, double, double); // решение через дискриминант
void print_answers(struct answers*);
const double zero = 1e-20;


int main(void) {
	double a = 0, b = 0, c = 0;
	struct answers ans = { 0, 0, 0 }; // первый элемент является числом решений
	// второй и третьий равны значениям х, если она существуют
	printf("Hi! This program solves quadratic equations a*x^2 + b*x + c = 0 \n");
	input(&a, &b, &c);
	printf("Quadratic equation: %lg*x^2 + %lg*x + %lg = 0 \n", a, b, c);
	solution(&ans, a, b, c);
	print_answers(&ans);
	printf("The equation is solved :)");
	return 0;
}



void input(double* a, double* b, double* c) {
	printf("Now enter the values a, b, c \n");
	printf("enter a \n");
	scanf("%lf", a);
	eatline();
	printf("enter b \n");
	scanf("%lf", b);
	eatline();
	printf("enter c \n");
	scanf("%lf", c);
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

void solution(struct answers* ans, double a, double b, double c) {
	if (fabs(a - 0) < zero) {
	    solution_without_a(ans,  b, c);
	}
	else if (fabs(b - 0) < zero) {
		solution_without_b(ans, a, c);
	}
	else if (fabs(c - 0) < zero) {
		solution_without_c(ans, a, b);
	}
	else {
		classic(ans, a, b, c);
	}
}

void solution_without_a(struct answers* ans, double b, double c) {
	if (fabs(c - 0) < zero) {
		
		if (fabs(b - 0) < zero) {
			(*ans).amount = 3;
		}
		else {
			(*ans).amount = 1;
			(*ans).x1 = 0;
		}
	}
	else if (fabs(b - 0) < zero) { //следовательно с != 0
		(*ans).amount = 0;
	}
	else {
		(*ans).amount = 1;
		(*ans).x1 = -c / b;
	}
}

void solution_without_b(struct answers* ans, double a, double c) {
	if (fabs(c - 0) < zero) {
		
		if (fabs(a - 0) < zero) {
			ans->amount = 3;
		}
		else {
			ans->amount = 1;
			ans->x1 = 0;
		}
	}
	else if (fabs(a - 0) < zero) { // следовальено с != 0
		ans->amount = 0;
	}
	else if ((a * c) > 0) {
		ans->amount = 0;
	}
	else {
		ans->amount = 2;
		ans->x1 = +sqrt(-c / a);
		ans->x2 = -sqrt(-c / a);
	}
}

void solution_without_c(struct answers* ans, double a, double b) {
	if (fabs(a - 0) < zero) {
		
		if (fabs(b - 0) < zero) {
			ans->amount = 3;
		}
		else{
			ans->amount = 1;
			ans->x1 = 0;
		}
	}
	else if (fabs(b - 0) < zero) { // следовательно а != 0
		(*ans).amount = 1;
		(*ans).x1 = 0;
	}
	else {
		(*ans).amount = 2;
		(*ans).x1 = 0;
		(*ans).x2 = -b / a;
	}
}

void classic(struct answers* ans, double a, double b, double c) {
	double diskr;
	diskr = (b) * (b) - 4 * (a) * (c);
	if (diskr < 0) {
		ans->amount = 0;
	}
	else if (fabs(diskr - 0) < zero) {
		ans->amount = 1;
		ans->x1 = -(b) / (2 * (a));
	}
	else {
		ans->amount = 2;
		ans->x1 = (-(b)-sqrt(diskr)) / (2 * (a));
		ans->x2 = (-(b)+sqrt(diskr)) / (2 * (a));
	}
}



void print_answers(struct answers* ans) {
	if (ans->amount == 0) {
		printf("The equation has no solutions \n");
	}
	else if (ans->amount == 1) {
		printf("The equation has one solution x = %lg \n", (*ans).x1);
	}
	else if (ans->amount == 2) {
		printf("The equation has two solution x1 = %lg, x2 = %lg \n", (*ans).x1, (*ans).x2);
	}
	else {
		printf("The equation has an infinite number of solutions \n");
	}
}
