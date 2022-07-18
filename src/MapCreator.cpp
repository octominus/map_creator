#include "MapCreator.h"

MapCreator::MapCreator(int height, int width) : _m_height(height), _m_width(width) {
    std::cout << "Map Initiliazed!" << std::endl;
    _circle_list = new std::vector<Circle>;
    int image_size = _m_height * _m_width;
    _m_data_ptr = new char[image_size];
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
    for (int i = 0; i < image_size; i++) {
        _m_data_ptr[i] = '0';
    }
}

Circle MapCreator::createRandomCircle() {
    Circle circle_data;
    std::random_device rand_engine;
    std::mt19937 rng(rand_engine());
    std::uniform_int_distribution<std::mt19937::result_type> radius_dist(_min_radius, _max_radius);
    std::uniform_int_distribution<std::mt19937::result_type> c_point_dist(_min_c_point, _max_c_point);

    circle_data.radius = radius_dist(rng);
    if (circle_data.radius%2 == 0) {circle_data.radius -= 1;}
    circle_data.x = c_point_dist(rng) - 1;
    circle_data.y = c_point_dist(rng) - 1;
    
    return circle_data;
}

void MapCreator::createObstacles(int n_circle) {
    float c_root = sqrt(n_circle);
    int root = ceil(c_root);
    _max_radius = _m_width / (root * 2);
    _min_c_point = _max_radius; 
    _max_c_point = 1000 - (_max_radius);
    // std::cout << "Number of circle: " << n_circle << std::endl << "Root of circle number: " << c_root << " -> " << root << std::endl;
    // std::cout << "Max radius of circles is " << _max_radius << " px" << std::endl;

    Circle d_circle;
    bool collision = 0;
    float pow_x, pow_y;
    float dist_rad, dist_circ;

    for (int i = 0; i < n_circle; i++) {
        d_circle = createRandomCircle();
        for (uint j = 0; j < _circle_list->size(); j++) {
            /* code */
            pow_x = pow((d_circle.x - _circle_list->at(j).x), 2);
            pow_y = pow((d_circle.y - _circle_list->at(j).y), 2);
            dist_rad = d_circle.radius + _circle_list->at(j).radius;
            dist_circ = sqrt(pow_x + pow_y);
            collision |= (dist_circ) < 1.5*(dist_rad);
        }
        if (collision) {
            /* code */
            i--;
            collision = 0;
        } else {
            printf("Circle Created -> Center: (%d, %d) - Radius: %d\n", d_circle.x, d_circle.y, d_circle.radius);
            drawCircle2Map(d_circle);
            _circle_list->push_back(d_circle);
        }
    }

    //printf("_m_data_ptr.len = %s\n", _m_data_ptr);
    int l_size = _circle_list->size();
    std::cout << "Circle List Size: " << l_size << std::endl;
}

void MapCreator::drawCircle2Map(Circle obj) {
    for (int i = -obj.radius; i < obj.radius; i++) {
        for (int j = -obj.radius; j < obj.radius; j++) {
            if (sqrt(pow(i, 2) + pow(j, 2)) <= (obj.radius)) {
                /* code */
                _m_data_ptr[(obj.x + j) + (_m_width * (obj.y+i))] = '1';
            }
        }
    }
}

char* MapCreator::getData() {
    return _m_data_ptr;
}

/*
void MapCreator::convertData2Image(FILE* image) {
    int image_size = _m_height * _m_width;
    for (int i = 0; i < image_size; i++) {
        if (_m_data_ptr[i] == '1') {
            fprintf(image, "%d ", 255);
        } else {
            fprintf(image, "%d ", 0);
        }
    }
}
*/