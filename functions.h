// объявления функций
struct Answers {
	int amount;
	double roots[2];
};


struct Coefficients {
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
