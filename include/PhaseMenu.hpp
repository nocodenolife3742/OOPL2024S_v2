#ifndef PHASE_MENU_HPP
#define PHASE_MENU_HPP

#include "Component/Phase.hpp"
#include "Component/ImageObject.hpp"

class PhaseMenu : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;

    explicit PhaseMenu(App::State lastState)
        : Phase(lastState){};

private:
    std::shared_ptr<ImageObject> m_Screen;
};

#endif // PHASE_MENU_HPP
