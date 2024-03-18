#ifndef PHASE_ENDING_ANIMATION_HPP
#define PHASE_ENDING_ANIMATION_HPP

#include "Phase.hpp"

class PhaseEndingAnimation : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;
};

#endif // PHASE_ENDING_ANIMATION_HPP