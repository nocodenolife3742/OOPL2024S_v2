#ifndef PHASE_HPP
#define PHASE_HPP

#include "App.hpp"

class Phase {
public:
    virtual void Init(App *app) = 0;

    virtual void Update(App *app) = 0;

    virtual void Leave(App *app) = 0;

    virtual ~Phase() = default;

    Phase() = default;
};

#endif // PHASE_HPP
