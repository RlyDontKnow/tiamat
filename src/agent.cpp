// local
#include "agent.h"

// stdlib
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>

// godot
#include "Input.hpp"

namespace
{
  const real_t movement_delta = 16; // [pixel / second]
}

Agent::Agent()
  : animator(*this)
{
}

void Agent::_register_methods()
{
  godot::register_method("_ready", &Agent::_ready);
  godot::register_method("_process", &Agent::_process);
}

// called when entering scene
void Agent::_ready()
{
  viewport = owner->get_viewport_rect().size;
  ready();
}

// called once per frame
void Agent::_process(float delta)
{
  handle_user_input();
  integrate_movement(delta);
}

void Agent::handle_user_input()
{
  using godot::Input;

  Movement newmovement = Movement::none;
  if(Input::is_action_pressed("ui_up"))
  {
    newmovement = Movement::up;
  }
  else if(Input::is_action_pressed("ui_down"))
  {
    newmovement = Movement::down;
  }
  else if(Input::is_action_pressed("ui_left"))
  {
    newmovement = Movement::left;
  }
  else if(Input::is_action_pressed("ui_right"))
  {
    newmovement = Movement::right;
  }
  
  if(newmovement != movement)
  {
    movement = newmovement;
    movement_changed(movement);
  }
}

void Agent::integrate_movement(float delta)
{
  godot::Vector2 update{};
  switch(movement)
  {
  case Movement::up:
    update.y -= movement_delta;
    break;

  case Movement::down:
    update.y += movement_delta;
    break;

  case Movement::left:
    update.x -= movement_delta;
    break;

  case Movement::right:
    update.x += movement_delta;
    break;

  case Movement::none:
    // nothing to be done
    break;
  }
  update *= delta;
  auto pos = owner->get_position() + update;
  pos.x = std::clamp(pos.x, 0.0f, viewport.width);
  pos.y = std::clamp(pos.y, 0.0f, viewport.height);
  owner->set_position(pos);
}
