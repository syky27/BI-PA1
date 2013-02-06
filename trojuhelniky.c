#include <stdio.h>
#include <stdlib.h>

void swap(double * s1, double * s2) {
	double t;
	t = *s1;
	*s1 = *s2;
	*s2 = t;
}

void sort3(double * s1, double * s2, double * s3) {
	if (*s1 > *s2) swap(s1, s2);
	if (*s1 > *s3) swap(s1, s3);
	if (*s2 > *s3) swap(s2, s3);
}

void harakiri(void) {
	printf("Nespravny vstup.\n");
	exit(1);
}

void check(double s) {
	if (s <= 0) harakiri();
}

void check3(double s1, double s2, double s3) {
	if ((s1+s2) <= s3) harakiri();
}

void loadTriangle(int triangle, double * side1, double * side2, double * side3) {
	printf("Zadejte velikost stran ");
	if (triangle == 1) { printf("prveho"); } else { printf("druheho"); }
	printf(" trojuhelniku:\n");
	// Nacti
	if (scanf("%lf %lf %lf",side1,side2,side3) != 3) harakiri();
	// Zkontroluj hodnoty
	check(*side1);
	check(*side2);
	check(*side3);
	// Srovnej
	sort3(side1,side2,side3);
	// Trojuhelni­kova nerovnost
	check3(*side1,*side2,*side3);
}

int equals(double s1, double s2) {
	double a = s1-s2;
	if (a<0) a *= -1;
	return (a <= 0.001);
}

void compare(double tA1, double tA2, double tA3, double tB1, double tB2, double tB3) {
	if (equals(tA1/tB1,tA2/tB2) && equals(tA1/tB1,tA3/tB3) && equals(tA3/tB3,tA2/tB2)) {
		printf("Trojuhelniky jsou podobne.\n");
	} else {
		printf("Trojuhelniky nejsou podobne.\n");
	}
}

int main(void) {
	double tA1, tA2, tA3;
	double tB1, tB2, tB3;
	loadTriangle(1, &tA1, &tA2, &tA3);
	loadTriangle(2, &tB1, &tB2, &tB3);
	compare(tA1, tA2, tA3, tB1, tB2, tB3);

	

	return 0;

}

