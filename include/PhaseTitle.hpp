#ifndef PHASE_TITLE_HPP
#define PHASE_TITLE_HPP

#include "Component/AnimatedObject.hpp"
#include "Phase.hpp"

class PhaseTitle : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;

private:
    std::shared_ptr<AnimatedObject> m_Background;
};

#endif // PHASE_TITLE_HPP
