#include "PhaseEndingAnimation.hpp"
#include "Util/Input.hpp"
#include "Util/Time.hpp"

void PhaseEndingAnimation::Init(App *app) {
    // init scrolling
    m_IsScrolling = true;

    // init background
    m_Background = std::make_shared<ImageObject>(
        RESOURCE_DIR "/Picture/UI/Credits/background.png");
    m_Background->SetScale({3, 3});
    m_Background->SetPosition({-3840, 0});
    m_Background->SetZIndex(0);
    app->GetRoot()->AddChild(m_Background);

    // init character
    m_Character = std::make_shared<AnimatedObject>(
        std::vector<std::string>{
            RESOURCE_DIR "/Picture/Character/Normal/Walk2.png",
            RESOURCE_DIR "/Picture/Character/Normal/Walk1.png",
            RESOURCE_DIR "/Picture/Character/Normal/Walk2.png",
            RESOURCE_DIR "/Picture/Character/Normal/Walk3.png",
        },
        true, 120);
    std::dynamic_pointer_cast<AnimatedObject>(m_Character)->SetScale({3, 3});
    std::dynamic_pointer_cast<AnimatedObject>(m_Character)
        ->SetPosition({0, 30});
    m_Character->SetZIndex(10);
    app->GetRoot()->AddChild(m_Character);
}

void PhaseEndingAnimation::Update(App *app) {
    // calculate delta x for scrolling
    double delta_x = Util::Time::GetDeltaTime() * 600;

    // if background is out of screen and not scrolling
    if (m_Background->GetPosition().x + delta_x >= 3840 && m_IsScrolling) {

        // set background to border of screen
        m_Background->SetPosition({3840, 0});

        // set character to idle
        app->GetRoot()->RemoveChild(m_Character);
        m_Character = std::make_shared<ImageObject>(
            RESOURCE_DIR "/Picture/Character/Normal/Idle1.png");
        std::dynamic_pointer_cast<ImageObject>(m_Character)->SetScale({3, 3});
        std::dynamic_pointer_cast<ImageObject>(m_Character)
            ->SetPosition({0, 30});
        m_Character->SetZIndex(10);
        app->GetRoot()->AddChild(m_Character);

        // stop scrolling
        m_IsScrolling = false;
    }

    // if scrolling
    if (m_IsScrolling) {
        // scroll background
        m_Background->SetPosition({m_Background->GetPosition().x + delta_x, 0});
    }

    // if escape key is pressed or enter key is pressed and not scrolling
    if ((Util::Input::IsKeyUp(Util::Keycode::RETURN) && !m_IsScrolling) ||
        Util::Input::IsKeyUp(Util::Keycode::ESCAPE)) {

        // exit app
        app->GetContext()->SetExit(true);
        return;
    }
}

void PhaseEndingAnimation::Leave(App *app) {
    // free background resources
    app->GetRoot()->RemoveChild(m_Background);
    m_Background = nullptr;

    // free character resources
    app->GetRoot()->RemoveChild(m_Character);
    m_Character = nullptr;
}
