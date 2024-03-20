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
    TileMap::Map m_Map = {};
};

#endif // PHASE_STAGE_HPP
