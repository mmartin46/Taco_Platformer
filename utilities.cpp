#include <utility>
#include <ctime>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <memory>
#include "constants.hpp"
#include "player.hpp"
#include "comp.hpp"
#include "enemy.hpp"
#include "entity.hpp"

using std::vector;
using std::pair;
using std::shared_ptr;
using std::vector;

// Returns the minimum in a vector.
double minimum(const vector<double> &v)
{
    double min = v.at(0);
    typename vector<double>::const_pointer p, end = v.data() + v.size();
    for (p = v.data(); p < end; ++p)
    {
        if (min > *p)
        {
            min = *p;
        }
    }
    return min;
}

// Are two rectangles colliding.
int collide2d(float x1, float y1, float x2, float y2, float ht1, float wt1, float wt2, float ht2)
{
    return (!((x1 > (x2+wt2)) || (x2 > (x1+wt1)) || (y1 > (y2+ht2)) || (y2 > (y1+ht1))));
}

// Allows the user to load a texture and returns a surface.
//
// Parameters:
// \param file includes the file path
// \param error_msg includes an error message if the file isn't found.
SDL_Surface* get_surface(const char *file, const char *error_msg)
{
    SDL_Surface *surface = NULL;
    
    surface = IMG_Load(file);
    if (surface == NULL)
    {
        printf(error_msg);
        SDL_Quit();
        exit(1);
    } 
    return surface;   
}

// Uses the manhattan distance formula
double get_distances(double x_1, double x_2, double y_1, double y_2)
{
    double val = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));
    return val;
}