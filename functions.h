// ���������� �������
struct Answers {
	int amount;
	double roots[2];
};


struct Coefficients {
	double a;
	double b;
	double c;
};


void input(struct Coefficients*); // ��� ����� ������
void eatline(); // ��� ������������ ��������� ����� ������, ���� ������ ����� ������� � �������
void wrong_input(); // �� ������ ������������� �����
void solve_equation(struct Answers* ans, struct Coefficients* Coef); // ������� ���������
void linear_equation(struct Answers* ans, struct Coefficients* Coef); // ���� � == 0
void the_quadratic_equation(struct Answers* ans, struct Coefficients* Coef); // ������� ����� ������������
void print_answers(struct Answers*);

const double zero = 1e-20;
