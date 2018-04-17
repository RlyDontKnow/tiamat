#pragma once

// local
#include "movement.h"

// godot
#include "AnimatedSprite.hpp"

class Agent;

class AgentAnimator
{
public:
  AgentAnimator(Agent &);

private:
  void update_animation(Movement);

  godot::AnimatedSprite *sprite = nullptr;
};
