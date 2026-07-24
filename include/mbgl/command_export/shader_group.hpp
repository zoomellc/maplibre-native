#pragma once

#include <mbgl/gfx/shader_group.hpp>
#include <mbgl/command_export/shader_program.hpp>

#include <memory>
#include <string>

namespace mbgl {
namespace command_export {

/// Stub shader group for the Command Export backend.
/// Returns a simple ShaderProgram stub — no GPU compilation needed.
class StubShaderGroup final : public gfx::ShaderGroup {
public:
    StubShaderGroup(std::string name)
        : shaderName(std::move(name)) {}

    gfx::ShaderPtr getOrCreateShader(gfx::Context&, const StringIDSetsPair&, std::string_view) override {
        if (!cachedShader) {
            cachedShader = std::make_shared<ShaderProgram>(shaderName);
        }
        return cachedShader;
    }

private:
    std::string shaderName;
    gfx::ShaderPtr cachedShader;
};

} // namespace command_export
} // namespace mbgl
