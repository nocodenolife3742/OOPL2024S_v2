#include "PhaseLose.hpp"
#include "Util/Input.hpp"

void PhaseLose::Init(App *app) {
    // init phase
    m_State = State::CONTINUE;
    m_Screen =
        std::make_shared<ImageObject>(RESOURCE_DIR "/Picture/UI/GameOver1.png");
    m_Screen->SetScale({3, 3});
    app->GetRoot()->AddChild(m_Screen);
}

void PhaseLose::Update(App *app) {

    // update state
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN) && m_State == State::CONTINUE) {
        m_State = State::STAGE_SELECT;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::UP) && m_State == State::STAGE_SELECT) {
        m_State = State::CONTINUE;
    }

    // draw screen
    switch (m_State) {
    case State::CONTINUE:
        m_Screen->SetImage(RESOURCE_DIR "/Picture/UI/GameOver1.png");
        break;
    case State::STAGE_SELECT:
        m_Screen->SetImage(RESOURCE_DIR "/Picture/UI/GameOver2.png");
        break;
    }

    // change phase
    if (Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
        switch (m_State) {
        case State::CONTINUE:
            app->ChangeState(GetLastState());
            break;
        case State::STAGE_SELECT:
            app->ChangeState(App::State::MENU);
            break;
        }
        return;
    }
}

void PhaseLose::Leave(App *app) {
    app->GetRoot()->RemoveChild(m_Screen);
    m_Screen = nullptr;
}
