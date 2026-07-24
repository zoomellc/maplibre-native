#pragma once

#include <mbgl/gfx/renderer_backend.hpp>
#include <mbgl/util/image.hpp>
#include <mbgl/util/size.hpp>

namespace mbgl {

class ProgramParameters;

namespace command_export {

class RendererBackend : public gfx::RendererBackend {
public:
    RendererBackend(gfx::ContextMode);
    ~RendererBackend() override;

    /// Called prior to rendering to update assumed state (no-op for CPU backend)
    virtual void updateAssumedState() = 0;

    /// One-time shader initialization
    void initShaders(gfx::ShaderRegistry&, const ProgramParameters&) override;

protected:
    std::unique_ptr<gfx::Context> createContext() override;

    /// Read pixel data from render target
    PremultipliedImage readFramebuffer(const Size&);
};

} // namespace command_export
} // namespace mbgl
