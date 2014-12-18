#include <stdio.h>

int lower(char c);

int main() {

	char s1[] = "AbcDefG";

	int i;
	for(i=0; s1[i] != '\0'; i++) {
		s1[i] = lower(s1[i]);
	}

	printf("%s\n", s1);


	return 0;
}

int lower(char c){
	return c >='A' && c<='Z' ? c+'a'-'A' : c;
}
