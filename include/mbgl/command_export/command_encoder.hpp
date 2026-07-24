#pragma once

#include <mbgl/gfx/command_encoder.hpp>

namespace mbgl {
namespace command_export {

class Context;

class CommandEncoder final : public gfx::CommandEncoder {
public:
    explicit CommandEncoder(Context& context);
    ~CommandEncoder() override;

    std::unique_ptr<gfx::UploadPass> createUploadPass(const char* name, gfx::Renderable&) override;
    std::unique_ptr<gfx::RenderPass> createRenderPass(const char* name, const gfx::RenderPassDescriptor&) override;
    void present(gfx::Renderable&) override;
    void pushDebugGroup(const char* name) override;
    void popDebugGroup() override;

private:
    Context& context;
};

} // namespace command_export
} // namespace mbgl
