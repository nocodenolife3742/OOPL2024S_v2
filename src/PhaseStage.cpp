#include "PhaseStage.hpp"
#include "Util/Input.hpp"
#include "Util/Time.hpp"

void PhaseStage::Init(App *app) {
    // Load the map
    m_Map = TileMap::Map("Bomb Man Stage");
    app->GetRoot()->AddChildren(m_Map.GetObjects());
}

void PhaseStage::Update(App *app) {
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
}

void PhaseStage::Leave(App *app) {
    // clean up root
    app->GetRoot()->RemoveAllChildren();
}
