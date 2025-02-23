#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int i, j;
    unsigned char rgb[3];
    int urand = open("/dev/urandom", O_RDONLY);

    if (urand < 0) {
        perror("Failed to open /dev/urandom");
        return 1;
    }

    while (1) {
        for (i = 0; i < 480; i++) {
            for (j = 0; j < 640; j++) {
                read(urand, rgb, sizeof(rgb));
                fwrite(rgb, sizeof(rgb), 1, stdout);
            }
        }
    }

    close(urand);
    return 0;
}
