#pragma once

#include <mbgl/gfx/render_pass.hpp>

namespace mbgl {
namespace command_export {

/// No-op render pass; exported commands are rendered by an external consumer.
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
