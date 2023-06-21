#include "utilities.hpp"


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

int collide2d(float x1, float y1, float x2, float y2, float ht1, float wt1, float wt2, float ht2)
{
    return (!((x1 > (x2+wt2)) || (x2 > (x1+wt1)) || (y1 > (y2+ht2)) || (y2 > (y1+ht1))));
}


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

double get_distances(double x_1, double x_2, double y_1, double y_2)
{
    double val = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));
    return val;
}

void modify_block_textures(vector<pair<string,string> > &surface_args, string idx)
{
  for (int i = 0; i < surface_args.size(); ++i)
  {
      string request = surface_args.at(i).first;
      string period = {"."};
      std::size_t index = request.find(period);
      request.insert(index, idx);
      surface_args.at(i).first = request;

      request = surface_args.at(i).second;
      index = request.find(period);
      request.insert(index, idx);
      surface_args.at(i).second = request;
  }   
}