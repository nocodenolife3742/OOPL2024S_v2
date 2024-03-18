set(SRC_FILES
        App.cpp

        # Phases
        PhaseTitle.cpp
        PhaseMenu.cpp
        PhaseStage.cpp
        PhaseLose.cpp
        PhaseEndingAnimation.cpp

        # Components
        Component/AnimatedObject.cpp
        Component/ImageObject.cpp
)

set(INCLUDE_FILES
        App.hpp
        Phase.hpp

        # Phases
        PhaseTitle.hpp
        PhaseMenu.hpp
        PhaseStage.hpp
        PhaseLose.hpp
        PhaseEndingAnimation.hpp

        # Components
        Component/AnimatedObject.hpp
        Component/ImageObject.hpp
)

set(TEST_FILES
)
