#ifndef PLAYER_H
#define PLAYER_H
#include "main.hpp"

class Player
{
   private:
      /* data */
      float x, y;
      float dx, dy;
      int onBlock;
      short life;
      char *name;
      int animFrame;
      bool slowingDown, facingLeft;
   public:
      
      inline int get_x() { return x; } const
      inline void set_x(int val) { x = val; }
      inline int get_y() { return y; } const
      inline void set_y(int val) { y = val; }

      inline int get_dx() { return dx; } const
      inline void set_dx(int val) { dx = val; }
      inline int get_dy() { return dy; } const
      inline void set_dy(int val) { dy = val; }


      // Player Physics 

      inline void apply_gravity() { dy += GRAVITY; } // Accumulates the gravity constant to the player.

      inline void apply_jump() { dy -= 0.3f; }
      
      inline void move_left_x() { dx += -PLAYER_SPEED; }
      inline void move_right_x() { dx += PLAYER_SPEED; }

      inline void move_left_dx() { dx = -6; }
      inline void move_right_dx() { dx = 6; }
      inline void slow_movement() { dx *= 0.8; };
      inline void apply_static_movement() { dx = 0; }
      inline void set_onBlock() { onBlock = 1; }
      inline void reset_onBlock() { onBlock = 0; }
      inline int get_onBlock() { return onBlock; }



      inline int get_animFrame() { return animFrame; } const
      inline void set_animFrame(int af) { animFrame = af; }
      inline int get_facingLeft() { return facingLeft; } const
      inline void set_facingLeft(int v) { facingLeft = v; }
      inline bool get_slowingDown() { return slowingDown; } const
      inline void set_slowingDown(bool s) { slowingDown = s; }
      
};

#endif