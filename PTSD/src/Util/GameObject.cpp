#include "Util/GameObject.hpp"

namespace Util {

void GameObject::Draw(const glm::vec2 &offset) {
    if (!m_Visible) {
        return;
    }

    Util::Transform transform = m_Transform;
    transform.translation += offset;
    m_Drawable->Draw(transform, m_ZIndex);
}

} // namespace Util
