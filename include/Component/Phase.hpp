#ifndef PHASE_HPP
#define PHASE_HPP

#include "App.hpp"

class Phase {
public:
    virtual void Init(App *app) = 0;

    virtual void Update(App *app) = 0;

    virtual void Leave(App *app) = 0;

    ~Phase() = default;

    Phase() = default;
private:
    App::State m_LastState;
};

#endif // PHASE_HPP
