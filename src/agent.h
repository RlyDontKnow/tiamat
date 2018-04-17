#pragma once

// local
#include "agent_animator.h"
#include "movement.h"

// boost
#include "boost/signals2.hpp"

// godot
#include "Godot.hpp"
#include "Area2D.hpp"

class Agent : public godot::GodotScript<godot::Area2D>
{
  GODOT_CLASS(Agent)
public:
  Agent();

  // godot interface
  static void _register_methods();

  // signals
  boost::signals2::signal<void()> ready;
  boost::signals2::signal<void(Movement)> movement_changed;

private:
  void _ready();
  void _process(float delta);
  void handle_user_input();
  void integrate_movement(float delta);

  Movement movement = Movement::none;
  godot::Vector2 viewport;
  AgentAnimator animator;
};
