#include "RSA.h"

int main(){
	LL n,e,d;
	generateKey(n,e,d);

	encDecNum(e,n);
	
	return 0;
}
