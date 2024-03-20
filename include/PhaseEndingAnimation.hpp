#ifndef PHASE_ENDING_ANIMATION_HPP
#define PHASE_ENDING_ANIMATION_HPP

#include "Component/AnimatedObject.hpp"
#include "Component/ImageObject.hpp"
#include "Component/Phase.hpp"
#include "Util/GameObject.hpp"

class PhaseEndingAnimation : public Phase {
    using Phase::Phase;

public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;

private:
    bool m_IsScrolling;
    std::shared_ptr<ImageObject> m_Background;
    std::shared_ptr<Util::GameObject> m_Character;
};

#endif // PHASE_ENDING_ANIMATION_HPP
