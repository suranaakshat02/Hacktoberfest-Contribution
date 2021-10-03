#include <bits/stdc++.h>
using namespace std;

int main (){
	for(int i=1; i<4036; i++)
		if(__gcd(i,2008)==251)
			cout << i << endl;
	return 0;
}
