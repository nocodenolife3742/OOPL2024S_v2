#ifndef PHASE_MENU_HPP
#define PHASE_MENU_HPP

#include "Component/Phase.hpp"

class PhaseMenu : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;

    explicit PhaseMenu(App::State lastState)
        : Phase(lastState){};
};

#endif // PHASE_MENU_HPP
