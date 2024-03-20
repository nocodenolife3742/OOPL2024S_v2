#include "PhaseStage.hpp"
#include "Util/Input.hpp"
#include "Util/Time.hpp"

void PhaseStage::Init(App *app) {
    // Load the map
    m_BackgroundObjects = TileMap::GetBackgroundObjects("Bomb Man Stage");
    m_ForegroundObjects = TileMap::GetForegroundObjects("Bomb Man Stage");

    // Add the root
    app->GetRoot()->AddChildren(m_BackgroundObjects);
    app->GetRoot()->AddChildren(m_ForegroundObjects);

    // TODO: remove camera movement in the futures
    app->SetCameraPosition({366, -3460});
}

void PhaseStage::Update(App *app) {

    // TODO: remove camera movement in the future
    if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
        auto pos = app->GetCameraPosition();
        pos.y += Util::Time::GetDeltaTime() * 240;
        app->SetCameraPosition(pos);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        auto pos = app->GetCameraPosition();
        pos.y -= Util::Time::GetDeltaTime() * 240;
        app->SetCameraPosition(pos);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        auto pos = app->GetCameraPosition();
        pos.x -= Util::Time::GetDeltaTime() * 240;
        app->SetCameraPosition(pos);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        auto pos = app->GetCameraPosition();
        pos.x += Util::Time::GetDeltaTime() * 240;
        app->SetCameraPosition(pos);
    }
    LOG_DEBUG("Camera Position: ({}, {})", app->GetCameraPosition().x,
              app->GetCameraPosition().y);
}

void PhaseStage::Leave(App *app) {
    // clean up root
    app->GetRoot()->RemoveAllChildren();
}
