#pragma once

#include <mbgl/gfx/drawable_builder.hpp>

namespace mbgl {
namespace command_export {

class DrawableBuilder final : public gfx::DrawableBuilder {
public:
    explicit DrawableBuilder(std::string name);
    ~DrawableBuilder() override = default;

    std::unique_ptr<gfx::Drawable::DrawSegment> createSegment(gfx::DrawMode, SegmentBase&&) override;

protected:
    gfx::UniqueDrawable createDrawable() const override;
    void init() override;
};

} // namespace command_export
} // namespace mbgl
