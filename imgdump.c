#include <stdio.h>
#include <assert.h>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb/stb_image.h"

int main(int argc, char **argv)
{
	if (argc <= 1) {
		fprintf(stderr, "usage: %s [FILE]...\n", argv[0]);
		return 1;
	}

	for (int argi = 1; argi < argc; ++argi) {
		if (argc > 2) {
			printf("%s\n", argv[argi]);
		}

		int x, y, n;
		unsigned char *data = stbi_load(
			argv[argi],
			&x,
			&y,
			&n,
			0);

		if (!data) {
			fprintf(
				stderr,
				"error loading '%s': %s\n",
				argv[argi],
				stbi_failure_reason());
			return 1;
		}

		assert(n > 0);
		assert(n < 5);

		for (int j = 0; j < y; ++j) {
			const int z = j * x * n;

			for (int i = 0; i < x; ++i) {
				const int k = z + i * n;

				switch (n) {
				case 1:
					printf(
						"%3d",
						data[k + 0]);
					break;
				case 2:
					printf(
						"%3d/%3d",
						data[k + 0],
						data[k + 1]);
					break;
				case 3:
					printf(
						"%3d/%3d/%3d",
						data[k + 0],
						data[k + 1],
						data[k + 2]);
					break;
				case 4:
					printf(
						"%3d/%3d/%3d/%3d",
						data[k + 0],
						data[k + 1],
						data[k + 2],
						data[k + 3]);
					break;
				}

				if (i < x - 1) {
					printf(", ");
				}
			}

			printf("\n");
		}
	}
}
