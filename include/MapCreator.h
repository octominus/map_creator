#if !defined(MAPCREATOR_H)
#define MAPCREATOR_H

#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <chrono>

struct Circle
{
    int radius;
    int x;
    int y;
};

class MapCreator {
private:
    int _m_height = 1000; // default 1000 px
    int _m_width = 1000; // default 1000 px
    float _m_res = 0.1; // default 0.1 m/px

    char *_m_data_ptr;

    int _max_radius = 500; // default for 1 circle
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
