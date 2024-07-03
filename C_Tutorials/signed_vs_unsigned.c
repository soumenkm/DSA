#include<stdio.h>

int power(int a, int b) {
	if (b == 0) {
		return 1;
	} else {
		return a * power(a, b-1);
	}
}

int findNumDigits(int number) {
	int count = 0;
	if (number == 0) {
		count = 1;
	} else {
		while (number) {
			number = number / 10;
			count += 1;
		}
	}
	return count;
}

int bin2dec(int binary) {
    // binary needs to be in 2s complement format, number can't start with 0
    int number = binary;
    int length = findNumDigits(number);
	int sum = 0;
	for (int i = 0; i < length; i++) {
		if (i == length-1) {
			sum += -1 * power(2, i) * (number % 10);
		} else {
			sum += 1 * power(2, i) * (number % 10);
		}
		number = number / 10;
	}
	return sum;
}

int dec2bin(int decimal) {
	// decimal needs to be positive number
	int number = decimal;
	int sum = 0;
	int rem = 0;
	int count = 0;
	while (number) {
		rem = number % 2;
		sum += rem * power(10, count);
		number = number / 2;
		count++;
	}
	return sum;
}

int main() {
    
    /* Two's Complement: Representation to store signed integers in computer
    1. If the number is +Ve then represent it as usual way with MSB as 0
    2. If the number is -Ve then represent it in negative -1 weight at MSB position
    so that the MSB is always 1
    3. If a bit pattern is given then transform this into usual way of multiplying the 
    weights of the bits with -1 as additional multiplier of MSB weight
	4. If a number is unsigned then copy as it is and fill by 0
	5. If a number is signed then copy as it is and fill by MSB
	6. Do not mix signed and unsigned in calculation
	7. printf just uses the bit pattern in memory and treats it acc. to its format specifier
	8. signed and unsigned are just for the range purpose, the integer literal is the main 
	thing which is stored in memory as per its sign.
	9. While copying, the unsigned or signed is seen, the MSB of the number in memory is
	not looked at for unsigned and complier extends the bit by unsigned (0) or signed (MSB)
	10. Do not ever use unsigned. This is a common source of bug.
    */
    
	char x = 10; // 00001010 (10 in 2s complement system)
	int y = x; // 00000000 000000000 000000000 00001010 (copied as it is and extended by MSB 0)
	printf("%d\n", y); // treats it as signed integer so result is 10

	unsigned char xx = -10; // 11110110 (-10 in 2s complement system)
	int yy = xx; // 000000000 00000000 00000000 11110110 (copied as it is and extended by MSB 0)
	printf("%d\n", yy); // treats it as signed integer so result is 128+64+32+16+4+2 = 246

    int a = -10; // 11111111 11111111 11111111 11110110 (-10 in binary 2's complement system)
    int b = a >> 3; // 11111111 11111111 11111111 11111110 (after shifting it becomes -2)
    printf("%d\n", b); // treat the bit pattern as signed int so result is -2

    unsigned int c = -10; // 11111111 11111111 11111111 11110110 (-10 in binary 2's complement system)
    int d = c >> 3; // 00011111 11111111 11111111 11111110 (filling using unsigned MSB extension)
    printf("%d\n", d); // treat the bit pattern as signed int so result is HUGE as MSB is 0 means it's a HUGE positive number
	
	printf("DONE\n");
}