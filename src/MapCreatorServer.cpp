#include <iostream>
#include <fstream>

#include "MapCreator.h"

int main(int argc, char const *argv[]) {
    /*
    FILE* outimage = fopen("../maps/map1.pgm", "wb");

    // P2 for text, P5 for bit
    fprintf(outimage, "P2\n");
    // width and height + image bit scale
    fprintf(outimage, "%d %d \n255\n", 1000,1000);

    int size=1000*1000;
    char* imagedata;

    for (int j = 0; j < 1000; j++) {
        for (int i = 0; i < 1000; i++) {
            fprintf(outimage, "%d ", i%128 + j%128);
        }
        fprintf(outimage, "\n");
    }
    
    fclose(outimage);
    */
    MapCreator Map1(1000, 1000, 0.1);
    Map1.createObstacles(10);

    return 0;
}
