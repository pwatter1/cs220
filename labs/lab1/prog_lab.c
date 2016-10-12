/* Implementation of the factorial function goes here. */

int fact(int n){
	int result;
	result = 1;

	if(n<=1) return result;
	
	while(n  > 1){
		result = n * result;
		n -= 1;
	}
	return result;
}
