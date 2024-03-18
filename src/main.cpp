#include "App.hpp"
#include "Core/Context.hpp"

int main(int, char **) {
    App app(App::State::ENDING_ANIMATION);

    while (!app.GetContext()->GetExit()) {
        app.Update();
    }
    return 0;
}
