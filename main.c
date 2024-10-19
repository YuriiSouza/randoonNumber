#include <stdio.h>
#include <windows.h>

unsigned long getMilliseconds() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    return st.wMilliseconds;
}

unsigned long linearCongruentialGenerator(unsigned long prev, unsigned long b, unsigned long c, unsigned long m) {
    return (b * prev + c) % m;
}

unsigned long* randoom_congruential(int size) { //good to generate sequencies
		unsigned long seed = getMilliseconds();

    unsigned long b = 1664525UL;
    unsigned long c = 101390422;
    unsigned long m = 429496729;

		unsigned long* randoons = (unsigned long*)malloc(size * sizeof(unsigned long));

		if (randoons == NULL) {
			fprintf(stderr, "Error in memory allocation\n");
			exit(1);
		};

		for(int i = 0; i < size;i++){
			randoons[i] = linearCongruentialGenerator(seed, b, c, m);
			seed = randoons[i];
		};

    return randoons;
}

int main() {
		int size = 900;

    unsigned long* randomSequence = randoom_congruential(size);

    for(int i = 0; i < size; i++) {
			printf("Valor %d: %lu\n", i + 1, randomSequence[i]);
		};

		free(randomSequence);
    return 0;
}
