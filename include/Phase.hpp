#ifndef PHASE_HPP
#define PHASE_HPP

#include "App.hpp"

class Phase {
public:
    virtual void init(App *app) = 0;

    virtual void update(App *app) = 0;

    virtual void leave(App *app) = 0;

    virtual ~Phase() = default;

    Phase() = default;
};

#endif // PHASE_HPP
