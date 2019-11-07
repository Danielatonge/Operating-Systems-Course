#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

static int append_mode = 0;

int parse_args(int argc, char *argv[])
{
	char c;
	while ((c = getopt(argc, argv, "a")) != -1) {
		switch (c) {
		case 'a':
			append_mode = 1;
			break;
		default:
      return 1;
			break;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char buffer[100];
	size_t len;
	char *file_mode;
  int i;
	FILE *files[10];
	int num_files;
  char input[100];
  printf("Enter file name(path) + extension you want to use as stdin(e.g app.txt): ");
  scanf("%s", input);
  FILE *not_stdin = fopen(input, "r");


	if (parse_args(argc, argv)) {
		return 1;
	}

	file_mode = (append_mode ? "a" : "w");

	num_files = argc - optind;
	if (num_files > 0) {
		/* go through file arguments and either open for writing
		   or append based on the -a flag */
		for (i = optind; i < argc; i++) {
			FILE *pFile = fopen(argv[i], file_mode);
			files[i - optind] = pFile;
		}
	}

	while ((len = fread(&buffer[0], 1, sizeof(buffer), not_stdin)) > 0) {
		fwrite(&buffer[0], 1, len, stdout);
		for (i = 0; i < num_files; i++) {
			fwrite(&buffer[0], 1, len, files[i]);
		}
	}

	if (num_files > 0) {
		for (i = 0; i < num_files; i++) {
			fclose(files[i]);
		}
	}

	return 0;
}
