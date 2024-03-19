#include "PhaseTitle.hpp"
#include "Util/Input.hpp"

void PhaseTitle::Init(App *app) {
    LOG_DEBUG("PhaseTitle::Init()");

    // init background
    m_Background = std::make_shared<AnimatedObject>(
        std::vector<std::string>{RESOURCE_DIR "/Picture/UI/Title1.png",
                                 RESOURCE_DIR "/Picture/UI/Title2.png"},
        true, 500);
    m_Background->SetScale({3, 3});
    app->GetRoot()->AddChild(m_Background);
}

void PhaseTitle::Update(App *app) {
    LOG_DEBUG("PhaseTitle::Update()");

    // if enter is pressed
    if (Util::Input::IsKeyUp(Util::Keycode::RETURN)) {
        app->ChangeState(App::State::MENU);
        return;
    }

    // if escape is pressed
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE)) {
        app->GetContext()->SetExit(true);
        return;
    }
}

void PhaseTitle::Leave(App *app) {
    LOG_DEBUG("PhaseTitle::Leave()");

    // free background resources
    app->GetRoot()->RemoveAllChildren();
    m_Background = nullptr;
}
