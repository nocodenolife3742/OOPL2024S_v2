#include "Component/App.hpp"
#include "Core/Context.hpp"

int main(int, char **) {
    App app(App::State::TITLE);

    while (!app.GetContext()->GetExit()) {
        app.Update();
    }
    return 0;
}
