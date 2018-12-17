/*
2018 David DiPaola
licensed under CC0 (public domain, see https://creativecommons.org/publicdomain/zero/1.0/)
*/

#include <unistd.h>

int
main() {
	char ch;
	while (read(STDIN_FILENO, &ch, sizeof(ch)) == sizeof(ch)) {
		if (ch == 0x20) {
			/* write codepoint 0x3000 */
			char utf8[] = {
				0b11100000 |   0b0011,
				0b10000000 | 0b000000,
				0b10000000 | 0b000000,
			};
			write(STDOUT_FILENO, utf8, sizeof(utf8));
		}
		else if ((ch >= 0x21) && (ch <= 0x7E)) {
			/* write codepoints 0xFF01-0xFF5E */
			char offset = ch - 0x20;
			char utf8[] = {
				0b11100000 |                        0b1111,
				0b10000000 | (0b1111 << 2) | (offset >> 6),
				0b10000000 |           (offset & 0b111111),
			};
			write(STDOUT_FILENO, utf8, sizeof(utf8));
		}
		else {
			write(STDOUT_FILENO, &ch, sizeof(ch));
		}
	}

	return 0;
}

