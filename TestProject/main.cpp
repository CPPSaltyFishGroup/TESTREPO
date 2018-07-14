#include<cstdio>
int main(int n,char*arg) {
	int*p;// = &n;
	//scanf_s("%d", &n);
	if(n>1)
		printf_s("hello world!");
	else {
		p = 0x0000000000000000;
		*p = 123;
	}
	//getchar();
	//getchar();
	return 0;
}
