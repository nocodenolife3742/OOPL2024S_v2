#ifndef PHASE_LOSE_HPP
#define PHASE_LOSE_HPP

#include "Component/Phase.hpp"

class PhaseLose : public Phase {
    using Phase::Phase;

public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;
};

#endif // PHASE_LOSE_HPP
