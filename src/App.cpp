#include "App.hpp"
#include "PhaseEndingAnimation.hpp"
#include "PhaseLose.hpp"
#include "PhaseMenu.hpp"
#include "PhaseStage.hpp"
#include "PhaseTitle.hpp"
#include "Util/Input.hpp"

void App::ChangeState(State state) {
    // leave the old state
    if (m_CurrentPhase)
        m_CurrentPhase->Leave(this);

    // create the new state
    m_CurrentState = state;
    switch (state) {
    case State::TITLE:
        m_CurrentPhase = std::make_unique<PhaseTitle>();
        break;

    case State::MENU:
        m_CurrentPhase = std::make_unique<PhaseMenu>();
        break;

    case State::STAGE:
        m_CurrentPhase = std::make_unique<PhaseStage>();
        break;

    case State::LOSE:
        m_CurrentPhase = std::make_unique<PhaseLose>();
        break;

    case State::ENDING_ANIMATION:
        m_CurrentPhase = std::make_unique<PhaseEndingAnimation>();
        break;
    }

    // initialize the new state
    if (m_CurrentPhase)
        m_CurrentPhase->Init(this);
}

void App::Update() {
    // update the current state
    if (m_CurrentPhase)
        m_CurrentPhase->Update(this);

    // render the root at the camera position
    m_Root->Update(-m_CameraPosition);

    // update the context
    m_Context->Update();

    // if pressed ESC, exit the app
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE)) {
        m_Context->SetExit(true);
    }
}

App::State App::GetState() const {
    // get the current state
    return m_CurrentState;
}

std::shared_ptr<Util::Renderer> App::GetRoot() const {
    return m_Root;
}

glm::vec2 App::GetCameraPosition() const {
    return m_CameraPosition;
}

App::App(State state)
    : m_CurrentPhase(nullptr),
      m_CurrentState(state),
      m_Root(std::make_shared<Util::Renderer>()),
      m_Context(Core::Context::GetInstance()),
      m_CameraPosition({0, 0}) {
    ChangeState(state);
}

App::~App() {
    // leave the current state
    if (m_CurrentPhase)
        m_CurrentPhase->Leave(this);
}

std::shared_ptr<Core::Context> App::GetContext() const {
    return m_Context;
}
