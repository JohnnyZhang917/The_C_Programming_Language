
// Look at this example:
// Would it be strange that "-10 > 0" ?

#include <stdio.h>
#include <stdlib.h>
int main() {
	int i;
	unsigned int stop_val;

	stop_val = 0;
	i = -10;

	while (i - stop_val>0) {    // no warning, but using '>' may cause a warning
		printf("%d\n", i);
		i = i + 1;
	}
	exit(EXIT_SUCCESS);
}

// we get:
// -10 -9 ... -1

// Note:
// writting : while (i >= stop_val) may cause a warning on the unsigned and signed