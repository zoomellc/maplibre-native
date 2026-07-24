#include <mbgl/command_export/tile_layer_group.hpp>
#include <mbgl/command_export/drawable.hpp>
#include <mbgl/command_export/upload_pass.hpp>
#include <mbgl/renderer/paint_parameters.hpp>
#include <mbgl/command_export/draw_command.hpp>
#include <mbgl/renderer/render_orchestrator.hpp>

namespace mbgl {
namespace command_export {

TileLayerGroup::TileLayerGroup(int32_t layerIndex, std::size_t initialCapacity, std::string name)
    : mbgl::TileLayerGroup(layerIndex, initialCapacity, std::move(name)) {}

void TileLayerGroup::upload(gfx::UploadPass&) {
    // CPU-only backend: vertex/index data already in memory
}

void TileLayerGroup::render(RenderOrchestrator&, PaintParameters& parameters) {
    setCurrentLayerIndex(static_cast<uint32_t>(getLayerIndex()));
    const auto& layerUBOs = uniformBuffers;
    visitDrawables([&](gfx::Drawable& drawable) {
        if (!drawable.getEnabled()) return;
        // Copy layer UBOs (e.g. EvaluatedPropsUBO) to drawable
        drawable.mutableUniformBuffers().copyCpuDataFrom(layerUBOs);
        drawable.draw(parameters);
    });
}

} // namespace command_export
} // namespace mbgl
