#ifndef PHASE_TITLE_HPP
#define PHASE_TITLE_HPP

#include "Phase.hpp"

class PhaseTitle : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;
};

#endif // PHASE_TITLE_HPP