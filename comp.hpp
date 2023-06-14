#ifndef COMP_HPP
#define COMP_HPP
#include "game.hpp"

class CompPlayer : public Player
{
   private:
      float x, y;
      float dx, dy;
      int onBlock;
      int animFrame;
      bool slowingDOwn, facingLeft;
      // Images
      std::vector<SDL_Texture*> plyFrames = std::vector<SDL_Texture*>(2);
   public:
      CompPlayer();
};

CompPlayer::CompPlayer()
{
   this->set_x(200-PLAYER_WIDTH);
   this->set_y(0-PLAYER_HEIGHT);
   this->set_dx(0);
   this->set_dy(0);

   this->reset_onBlock();
   this->set_animFrame(0);
   this->set_facingLeft(true);
   this->set_slowingDown(false);
}



#endif