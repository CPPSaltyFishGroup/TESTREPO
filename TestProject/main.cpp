#include<cstdio>
#include<cstdlib>
#include<iostream>
int main(int n,char*arg[]) {
	int*p;// = &n;
	//scanf_s("%d", &n);
	char ok[30] = {};
	//std::cin>> ok;
	if (n>1) {
		printf_s("hello world!  argment:%s",arg[1]);
		//system("pause");
	}
	else {
		//getchar();
		p = 0x0000000000000000;
		*p = 123;
	}
	//getchar();
	//getchar();
	return 0;
}
