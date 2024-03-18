#include "App.hpp"
#include "Phase.hpp"

void App::ChangeState(State state) {
    // leave the old state
    if (m_CurrentPhase)
        m_CurrentPhase->leave(this);

    // create the new state
    m_CurrentState = state;
    switch (state) {
        case State::TITLE:
            // m_CurrentPhase = std::make_unique<Phase>();
            break;

        case State::MENU:
            //m_CurrentPhase = std::make_unique<Phase>();
            break;

        case State::STAGE:
            // m_CurrentPhase = std::make_unique<Phase>();
            break;

        case State::LOSE:
            // m_CurrentPhase = std::make_unique<Phase>();
            break;

        case State::ENDING_ANIMATION:
            //m_CurrentPhase = std::make_unique<Phase>();
            break;

        case State::END:
            //m_CurrentPhase = std::make_unique<Phase>();
            break;
    }

    // initialize the new state
    if (m_CurrentPhase)
        m_CurrentPhase->init(this);
}

void App::Update() {
    // update the current state
    if (m_CurrentPhase)
        m_CurrentPhase->update(this);
}

App::State App::GetState() const {
    // get the current state
    return m_CurrentState;
}

Util::Root App::GetRoot() const {
    return m_Root;
}

App::App(State state) : m_CurrentPhase(nullptr), m_CurrentState(state), m_Root(Util::Root()),
                        m_Context(Core::Context::GetInstance()) {}

App::~App() {
    // leave the current state
    if (m_CurrentPhase)
        m_CurrentPhase->leave(this);
}

std::shared_ptr<Core::Context> App::GetContext() const {
    return m_Context;
}


