#include <stdio.h>
#include <math.h>
void vvod(double *a, double*b, double*c); // для ввода данных
void eatline(); // для отбрасывания отсальной части строки, если данные будут введены с мусором
void glupii(); // на случай неправильного ввода
void a_0(double* b, double* c); // если а == 0
void b_0(double* a, double* c); // если b == 0
void c_0(double* a, double* b); // если c == 0
void classic(double*, double*, double*); // решение через дискриминант
double dabs(double a, double b);
const double zero = 1e-20;
int main(void) {
	double a, b, c;
	printf("Privet! Eta programma reshaet uravnenia vida a*x^2 + b*x + c = 0 \n");
	vvod(&a, &b, &c);
	printf("Uravnenie imeet vid: %lg*x^2 + %lg*x + %lg = 0 \n", a, b, c);
	if (dabs(a, 0) < zero) {
		a_0(&b, &c);
	}
	else if (dabs(b, 0) < zero) {
		b_0(&a, &c);
	}
	else if (dabs(c, 0) < zero) {
		c_0(&a, &b);
	}
	else {
		classic(&a, &b, &c);
	}
	printf("Uravnenie resheno :)");
	return 0;
}

void vvod(double* a, double* b, double* c) {
	printf("Teper' vvedite znachenia a, b, c \n");
	printf("vvedite a \n");
	scanf("%lf", a);
	eatline();
	printf("vvedite b \n");
	scanf("%lf", b);
	eatline();
	printf("vvedite c \n");
	scanf("%lf", c);
	eatline();
	return;
}

void eatline() {
	while (getchar() != '\n') {
		continue;
	}
}

void glupii() {
	printf("Vvedi prosto chislo, dura4ok \n");
}

void a_0(double* b, double* c) {
	if (dabs(*c, 0) < zero) {
		
		if (dabs(*b, 0) < zero) {
			printf("Uravnenie verno pri lubom x \n");
		}
		else {
			printf("Uravnenie imeet odin koren' x = 0 \n");
		}
	}
	else if (dabs(*b, 0) < zero) { //следовательно с != 0
		printf("Reshenii net \n");
	}
	else {
		printf("Uravnenie imeet odno reshenie x = %lg \n", - *c / *b);
	}
}

void b_0(double* a, double* c) {
	if (dabs(*c, 0) < zero) {
		
		if (dabs(*a, 0) < zero) {
			printf("Uravnenie verno pri lubom x \n ");
		}
		else {
			printf("Uravnenie imeet odno reshenie x = 0 \n");
		}
	}
	else if (dabs(*a, 0) < zero) { // следовальено с != 0
		printf("Reshenii net \n ");
	}
	else if ((*a * *c) > 0) {
		printf("Reshenii net \n ");
	}
	else {
		printf("Uravnenie imeet dva reshenia x1 = %lg, x2 = %lg \n ", +sqrt(- *c / *a), -sqrt(- *c / *a));
	}
}

void c_0(double* a, double* b) {
	if (dabs(*a, 0) < zero) {
		
		if (dabs(*b, 0) < zero) {
			printf("Uravnenie verno pri lubom x \n");
		}
		else{
			printf("Uravnenie immet odno reshenie x = 0 \n");
		}
	}
	else if (dabs(*b, 0) < zero) { // следовательно а != 0
		printf("Uravnenie imeet odno reshenie x = 0 \n");
	}
	else {
		printf("Uravnenie imeet dva reshenia x1 = 0, x2 = %lg \n ", - *b / *a);
	}
}

void classic(double* a, double* b, double* c) {
	double diskr;
	diskr = (*b) * (*b) - 4 * (*a) * (*c);
	if (diskr < 0) {
		printf("Uravnenie ne imeet reshenii \n");
	}
	else if (dabs(diskr, 0) < zero) {
		printf("Uravnenie imeet odno reshenie x = %lg \n", -(*b) / (2 * (*a)));
	}
	else {
		printf("Uravnenie imeet dva reshenia x1 = %lg, x2 = %lg \n", (-(*b) - sqrt(diskr)) / (2 * (*a)), (-(*b) + sqrt(diskr)) / (2 * (*a)));
	}
}

double dabs(double a, double b) {
	return (a > b) ? (a - b) : (b - a);
}
