#ifndef PHASE_MENU_HPP
#define PHASE_MENU_HPP

#include "Phase.hpp"

class PhaseMenu : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;
};

#endif // PHASE_MENU_HPP