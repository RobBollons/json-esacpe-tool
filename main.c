#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int c;
    int o;
    int uflag = 0;

    while ((c = getopt (argc, argv, "u")) != -1) {
        switch (c)
        {
            case 'u':
                uflag = 1;
                break;
        }
    }

    while ((c = fgetc(stdin)) != EOF) {
        if (uflag == 1) {
            if (c == 92) {
                if ((c = fgetc(stdin)) != EOF && c == 34) {
                    printf("\"");
                } else {
                    printf("\\");
                    printf("%c", (char)c);
                }
                continue;
            }
        } else {
            if (c == 34) {
                printf("\\");
            }
        }
        printf("%c", (char)c);
    }

    return 0;
}
