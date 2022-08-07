#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <getopt.h>

#include "MapCreator.h"

/*
    -h                  ==> --help                      ==> Display usage summary and exit
    -p                  ==> --publish                   ==> Publish map data as a ROS node
    -s filename         ==> --save filename             ==> Save created map
    -l filename         ==> --load filename             ==> Load a map from selected file
    -W sizeofwidth      ==> --width sizeofwidth         ==> Define width size
    -H sizeofheight     ==> --height sizeofheight       ==> Define height size
    -O numberofobstacle ==> --obstacle numberofobstacle ==> Define obstacle number
    -T typeofobstacle   ==> --type typeofobstacle       ==> Define obstacle type
    -v                  ==> --verbose                   ==> Print verbose messages
*/

void createImageFile(FILE* file, int height, int width) {
    // P2 for text, P5 for bit
    fprintf(file, "P2\n");
    // width and height + image bit scale
    fprintf(file, "%d %d \n255\n", height, width);
}

void printUsage(int exit_code) {
    std::cout << "HELP!" << std::endl;
    exit(exit_code);
}

int main(int argc, char *argv[]) {
    FILE* outimage = fopen("src/map_creator/maps/map3.pgm", "wb");

    int next_option, verbose = 0;
    const char *const short_options = "hpslWHOT:v";
    const struct option long_options[] = {
        {"help"     , 0, NULL, 'h'},
        {"publish"  , 0, NULL, 'p'},
        {"save"     , 1, NULL, 's'},
        {"load"     , 1, NULL, 'l'},
        {"width"    , 1, NULL, 'W'},
        {"height"   , 1, NULL, 'H'},
        {"obstacle" , 1, NULL, 'O'},
        {"type"     , 1, NULL, 'T'}
    };

    const char* program_name = argv[0];

    do {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);

        switch (next_option) {
        case 'h':
            printUsage(0);
            break;

        case 'p':
            break;

        case 's':
            break;

        case 'l':
            break;

        case 'W':
            break;

        case 'H':
            break;

        case 'O':
            break;

        case 'T':
            break;
        
        case '?':   // INVALID OPTION
            printUsage(1);
            break;

        case 'v':
            verbose = 1;
            break;

        default:
            abort();
        }
    } while (next_option != -1);
    
    if(verbose) {
        int i;
        for (i = optind; i < argc; ++i) {
            std::cout << "Argument: " << argv[i] << std::endl;
        }
    }

    int height = 1000;
    int width = 1000;
    int obs = 10; // default value = 10

    createImageFile(outimage, height, width);

    // if (argc == 2) {obs = atoi(argv[1]);}

    MapCreator Map1(height, width);
    Map1.createObstacles(obs);
    
    int image_size = height * width;
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
