#include <iostream>
#include <fstream>

#include "ros/ros.h"

#include "MapCreator.h"

int main(int argc, char **argv) {
    FILE* outimage = fopen("src/rrt_star/maps/map5.pgm", "wb");

    // P2 for text, P5 for bit
    fprintf(outimage, "P2\n");
    // width and height + image bit scale
    fprintf(outimage, "%d %d \n255\n", 1000,1000);

    /*for (int j = 0; j < 1000; j++) {
        for (int i = 0; i < 1000; i++) {
            fprintf(outimage, "%d ", i%64 + j%64);
        }
        fprintf(outimage, "\n");
    }*/
    int obs = 10; // default value = 10
    if (argc == 2) {obs = atoi(argv[1]);} 

    MapCreator Map1(1000, 1000);
    Map1.createObstacles(obs);
    
    int image_size = 1000 * 1000;
    char *x = Map1.getData();

    for (int i = 0; i < image_size; i++) {
        if (x[i] == '0') {
            fprintf(outimage, "%d ", 255);
        } else {
            fprintf(outimage, "%d ", 0);
        }
    }
    
    fclose(outimage);
    return 0;
}
