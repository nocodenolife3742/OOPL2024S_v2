#ifndef PHASE_STAGE_HPP
#define PHASE_STAGE_HPP

#include "Component/Phase.hpp"
#include "Component/TileMap.hpp"

class PhaseStage : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;

    explicit PhaseStage(App::State lastState)
        : Phase(lastState){};

private:
    std::vector<std::shared_ptr<Util::GameObject>> m_BackgroundObjects;
    std::vector<std::shared_ptr<Util::GameObject>> m_ForegroundObjects;
};

#endif // PHASE_STAGE_HPP
