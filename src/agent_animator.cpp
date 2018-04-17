// local
#include "agent_animator.h"
#include "agent.h"

// stdlib
#include <cassert>

AgentAnimator::AgentAnimator(Agent &parent)
{
  parent.ready.connect([&] { sprite = reinterpret_cast<godot::AnimatedSprite *>(parent.owner->get_node("AnimatedSprite")); });
  parent.movement_changed.connect([this](auto m) { update_animation(m); });
}

void AgentAnimator::update_animation(Movement m)
{
  assert(sprite);
  switch(m)
  {
  case Movement::up:
    sprite->play("up");
    break;

  case Movement::down:
    sprite->play("down");
    break;

  case Movement::left:
    sprite->play("left");
    break;

  case Movement::right:
    sprite->play("right");
    break;

  case Movement::none:
    sprite->stop();
    sprite->set_frame(0);
    break;
  }
}
