#ifndef PHASE_LOSE_HPP
#define PHASE_LOSE_HPP

#include "Component/Phase.hpp"

class PhaseLose : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;

    explicit PhaseLose(App::State lastState)
        : Phase(lastState){};
};

#endif // PHASE_LOSE_HPP
