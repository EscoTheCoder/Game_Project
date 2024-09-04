#include "GameObject.h"
#include "GameState.h"

GameObject::GameObject(const string& name) :
    m_name(name), m_state(GameState::getInstance()), m_id(m_next_id++) {
}

int GameObject::m_next_id = 1;
