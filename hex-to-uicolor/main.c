//
//  main.c
//  Color
//
//  Created by Neo Mode on 16.02.2022.
//

#include <stdio.h>

char hex2dec(char);

int main(int argc, const char **argv) {

	if (argc != 2) {
		fprintf(stderr, "Examples of Usage:\n  %s ffffff\n  %s ff45ca\n  %s fff\n", *argv, *argv, *argv);
		return 1;
	}

	const char *text = argv[1];

	float color[3];
	short sum = 0, unchanged = 1;
	const char first = *text;

	for (short i = 0, j = 0; *text && i < 6; i++, text++) {

		if (i && first != *text) unchanged = 0;

		sum += hex2dec(*text);
		if (i % 2 == 0) { sum <<= 4; continue; }

		color[j++] = (float)sum / 255;
		sum = 0;
	}

	if (unchanged) {
		printf("\n\n\tUIColor(white: %g, alpha: 1)\n\n\n", color[0]);
		return 0;
	}

	printf("\n\n\tUIColor(red: %g, green: %g, blue: %g, alpha: 1)\n\n\n", color[0], color[1], color[2]);
	return 0;
}

char hex2dec(char chr) {
	chr |= 32;
	if (chr >= '1' && chr <= '9') return chr - 48;
	if (chr >= 'a' && chr <= 'f') return chr - 87;
	return 0;
}
