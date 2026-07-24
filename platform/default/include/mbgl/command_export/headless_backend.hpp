#pragma once

#include <mbgl/gfx/headless_backend.hpp>
#include <mbgl/command_export/renderer_backend.hpp>
#include <memory>

namespace mbgl {
namespace command_export {

class HeadlessBackend final : public command_export::RendererBackend, public gfx::HeadlessBackend {
public:
    HeadlessBackend(Size = {256, 256},
                    SwapBehaviour = SwapBehaviour::NoFlush,
                    gfx::ContextMode = gfx::ContextMode::Unique);
    ~HeadlessBackend() override;

    void updateAssumedState() override;
    gfx::Renderable& getDefaultRenderable() override;
    PremultipliedImage readStillImage() override;
    RendererBackend* getRendererBackend() override;

private:
    void activate() override;
    void deactivate() override;

    bool active = false;
};

} // namespace command_export
} // namespace mbgl
