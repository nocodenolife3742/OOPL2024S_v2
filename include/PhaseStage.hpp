#ifndef PHASE_STAGE_HPP
#define PHASE_STAGE_HPP

#include "Component/Phase.hpp"

class PhaseStage : public Phase {
    using Phase::Phase;

public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;
};

#endif // PHASE_STAGE_HPP
