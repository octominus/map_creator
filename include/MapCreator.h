#if !defined(MAPCREATOR_H)
#define MAPCREATOR_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#define MAX_HEIGHT 10000
#define MAX_WIDTH 10000
#define MAX_RESOLATION 1.0

#define DEFAULT_HEIGHT 1000
#define DEFAULT_WIDTH 1000
#define DEFAULT_RESOLATION 0.1

struct Circle
{
    int radius;
    int x;
    int y;
};

class MapCreator {
private:
    int _m_height = DEFAULT_HEIGHT; // default 1000 px
    int _m_width = DEFAULT_WIDTH; // default 1000 px
    float _m_res = DEFAULT_RESOLATION; // default 0.1 m/px

    char *_m_data_ptr;

    int _max_radius = DEFAULT_HEIGHT / 2; // default for 1 circle
    int _min_radius = 25;  // default 25 px

    int _max_c_point = 1000;
    int _min_c_point = 0;

    std::vector<Circle> *_circle_list;

    void createEmptyMap();
public:
    MapCreator(int height, int width);
    Circle createRandomCircle();
    void createObstacles(int n_circle);
    void drawCircle2Map(Circle obj);
    char* getData();
    ~MapCreator();
};

#endif // MAPCREATOR_H
