#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    unsigned char rgb[3];
    int i, j, frame = 0;

    while (1) {
        for (i = 0; i < 480; i++) {
            for (j = 0; j < 640; j++) {
                rgb[0] = (j + frame) % 256;
                rgb[1] = (i + frame) % 256;
                rgb[2] = (i + j + frame) % 256;
                fwrite(rgb, sizeof(rgb), 1, stdout);
            }
        }
        frame++;
    }

    return 0;
}
