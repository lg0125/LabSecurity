#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

typedef long long LL;

const int MAX_ROW = 50;

//KEY GENERATION
LL getPrime(){
	bool ifPrime = false;
	LL a = 0;
	int arr[MAX_ROW];

	for(int i = 0; i < MAX_ROW;++i){
		arr[i] = i + 3;
	}

	while(!ifPrime){
		srand((unsigned)time(0));
		ifPrime = true;
		a = (rand() % 1000) * 2 + 3;

		for(int j = 0;j < MAX_ROW;j++){
			if(a % arr[j] == 0){
				ifPrime = false;
				break;
			}
		}
	}

	return a;
}

bool checkIsPrime(LL n){
	if(n < 2) return false;

	LL i = 2;

	while(i <= n /2){
		if(!(n % i)) return false;
		i++;
	}
	
	return true;
}

bool checkCoPrime(LL n1,LL n2){
	LL lowest;

	if(n1 > n2) lowest = n1;
	else lowest = n2;

	LL i = 2;
	bool coPrime = true;

	while(i < lowest){
		if(!(n1 % i) && !(n2 % i)) coPrime = false;
		i++;
	}

	return coPrime;
}

LL findE(LL phi_n){
	LL e = 0;

	do{
		printf("Choose an integer number e\n");
		scanf("%lld",&e);
	}while(!checkCoPrime(phi_n,e));

	return e;
}

LL findD(LL phi_n,LL e){
	LL a = phi_n;
	LL b = e;
	LL x = 0,y = 1;
	LL u = 1,v = 0;
	LL gcd = b;
	LL m,n,q,r;

	while(a != 0){
		q = gcd / a;
		r = gcd % a;
		m = x - u * q;
		n = y - v * q;

		gcd = a;
		a = r;
		x = u;
		y = v;
		u = m;
		v = n;
	}

	if(y < 1){
		y = phi_n + y;
	}

	return y;
}



LL multiply(LL n1,LL n2){
	return n1 * n2;
}

int primeMenu(){
	int choice = 0;
	do{
		printf("------pq------\n");
		printf("1:auto\n");
		printf("2:myself\n");
		printf("choose:\n");
		scanf("%d",&choice);
		printf("--------------\n");
	}while(choice != 1 && choice != 2);
	return choice;
}

void autoPrime(LL& p,LL& q){
	printf("auto\n");
	do{
		p = getPrime();
		q = getPrime();
	}while(p == q);
	printf("p:%lld q:%lld\n",p,q);
}

void myselfPrime(LL& p,LL& q){
	printf("myself\n");
	do{
		scanf("%lld",&p);
	}while(!checkIsPrime(p));

	do{
		scanf("%lld",&q);
	}while(!checkIsPrime(q));
	printf("p:%lld q:%lld\n",p,q);
}

void generateKey(LL& n,LL& e,LL& d){
	LL p,q,phi_n;
	
	int choice = primeMenu(); 
	switch(choice){
		case 1 : 
			autoPrime(p,q);
			break;
		case 2 : 
			myselfPrime(p,q);
			break;
	}

	n = multiply(p,q);
	printf("n:%lld\n",n);

	phi_n = multiply(p-1,q-1);
	printf("phi_n:%lld\n",phi_n);

	e = findE(phi_n);
	printf("e:%lld\n",e);

	d = findD(phi_n,e);
	printf("d:%lld\n",d);
}

//ENCRYPT DECRYPT
LL encDec(LL m,LL ed,LL n){
	LL rem;
	LL x = 1;

	while(ed != 0){
		rem = ed % 2;
		ed = ed / 2;
		
		if(rem == 1) x = (x * m) % n;

		m = (m * m) % n;
	}

	return x;
}

void encDecNum(LL ed,LL n){
	 LL m;

	 printf("Enter a message number:\n");
	 scanf("%lld",&m);

	 LL c = encDec(m,ed,n);
	 printf("M/C:%lld C/M:%lld\n",m,c);
}





