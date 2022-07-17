#include "MapCreator.h"

MapCreator::MapCreator(int height, int width, int res) : _m_height(height), _m_width(width), _m_res(res) {
    std::cout << "Map Initiliazed!" << std::endl;
    _circle_list = new std::queue<Circle>;
    _m_data_ptr = new char;
    createEmptyMap();
}

MapCreator::~MapCreator() {
    delete _circle_list;
    delete _m_data_ptr;
    _m_data_ptr = NULL;
    _circle_list = NULL;
}

void MapCreator::createEmptyMap() {
    int image_size = _m_height * _m_width;
    for (int i = 0; i < _m_height; i++) {
        for (int j = 0; j < _m_width; j++) {
            sprintf(_m_data_ptr+(j*3),"%X ", 255);
        }
    }
    printf("_m_data_ptr.len = %s\n", _m_data_ptr);
}

Circle MapCreator::createRandomCircle(bool c_insec) {
    Circle circle_data;
    std::random_device rand_engine;
    std::mt19937 rng(rand_engine());
    std::uniform_int_distribution<std::mt19937::result_type> radius_dist(_min_radius, _max_radius);
    std::uniform_int_distribution<std::mt19937::result_type> c_point_dist(_min_c_point, _max_c_point);

    if (!c_insec) {
        /* code */
        circle_data.radius = radius_dist(rng);
        circle_data.x = c_point_dist(rng);
        circle_data.y = c_point_dist(rng);
    } else {
        // check intersection code will be write
    }
    
    return circle_data;
}

void MapCreator::createObstacles(int n_circle) {
    float c_root = sqrt(n_circle);
    int root = ceil(c_root);
    _max_radius = _m_width / (root * 2);
    _min_c_point = _max_radius / 2; 
    _max_c_point = 1000 - (_max_radius / 2);
    // std::cout << "Number of circle: " << n_circle << std::endl << "Root of circle number: " << c_root << " -> " << root << std::endl;
    // std::cout << "Max radius of circles is " << _max_radius << " px" << std::endl;

    Circle d_circle;

    for (int i = 0; i < n_circle; i++) {
        d_circle = createRandomCircle(false);
        printf("Dummy Circle Created -> Center: (%d, %d) - Radius: %d\n", d_circle.x, d_circle.y, d_circle.radius);
        _circle_list->push(d_circle);
    }

    int l_size = _circle_list->size();
    std::cout << "Circle List Size: " << l_size << std::endl;
}

void MapCreator::drawCircle2Map(Circle obj) {
    int d_size = _m_height * _m_width;
    for (int i = 0; i < obj.radius; i++) {
        for (int j = 0; j < obj.radius; j++) {
            sprintf(_m_data_ptr, "%d ", 255);
            printf("Data: %s\n", _m_data_ptr);
        }
    }
}
