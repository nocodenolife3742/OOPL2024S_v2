#ifndef APP_HPP
#define APP_HPP

#include "Core/Context.hpp"
#include "Util/Root.hpp"
#include "pch.hpp"

class Phase;

class App {
public:
    enum class State {
        TITLE,
        MENU,
        STAGE,
        LOSE,
        ENDING_ANIMATION,
    };

    void ChangeState(State state);

    void Update();

    [[nodiscard]] State GetState() const;

    [[nodiscard]] std::shared_ptr<Util::Root> GetRoot() const;

    [[nodiscard]] std::shared_ptr<Core::Context> GetContext() const;

    explicit App(State state);

    ~App();

private:
    std::unique_ptr<Phase> m_CurrentPhase;
    State m_CurrentState;
    std::shared_ptr<Util::Root> m_Root;
    std::shared_ptr<Core::Context> m_Context;
};

#endif // APP_HPP
