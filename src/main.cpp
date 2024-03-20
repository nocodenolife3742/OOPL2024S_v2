#include "Component/App.hpp"
#include "Core/Context.hpp"

int main(int, char **) {
    App app(App::State::STAGE);

    while (!app.GetContext()->GetExit()) {
        app.Update();
    }
    return 0;
}
