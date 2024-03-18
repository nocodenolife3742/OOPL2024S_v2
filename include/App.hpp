#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp"
#include "Util/Root.hpp"
#include "Core/Context.hpp"

class Phase;


class App {
public:
    enum class State {
        TITLE,
        MENU,
        STAGE,
        LOSE,
        ENDING_ANIMATION,
        END,
    };

    void ChangeState(State state);

    void Update();

    [[nodiscard]] State GetState() const;

    [[nodiscard]] Util::Root GetRoot() const;

    [[nodiscard]] std::shared_ptr<Core::Context> GetContext() const;

    explicit App(State state);

    ~App();

private:
    std::unique_ptr<Phase> m_CurrentPhase;
    State m_CurrentState;
    Util::Root m_Root;
    std::shared_ptr<Core::Context> m_Context;
};

#endif // APP_HPP
