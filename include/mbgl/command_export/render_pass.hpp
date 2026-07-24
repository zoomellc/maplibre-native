#pragma once

#include <mbgl/gfx/render_pass.hpp>

namespace mbgl {
namespace command_export {

/// No-op render pass. An external consumer performs the actual rendering.
class RenderPass final : public gfx::RenderPass {
public:
    RenderPass() = default;
    ~RenderPass() override = default;

protected:
    void pushDebugGroup(const char*) override {}
    void popDebugGroup() override {}
    void addDebugSignpost(const char*) override {}
};

} // namespace command_export
} // namespace mbgl
