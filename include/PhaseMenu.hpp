#ifndef PHASE_MENU_HPP
#define PHASE_MENU_HPP

#include "Component/Phase.hpp"

class PhaseMenu : public Phase {
    using Phase::Phase;

public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;
};

#endif // PHASE_MENU_HPP
