# D3D11_FEATURE_DATA_D3D11_OPTIONS2 structure

## Description

Describes Direct3D 11.3 feature options in the current graphics driver.

## Members

### `PSSpecifiedStencilRefSupported`

Specifies whether the hardware and driver support **PSSpecifiedStencilRef**.
The runtime sets this member to **TRUE** if the hardware and driver support this option.

### `TypedUAVLoadAdditionalFormats`

Specifies whether the hardware and driver support **TypedUAVLoadAdditionalFormats**.
The runtime sets this member to **TRUE** if the hardware and driver support this option.

### `ROVsSupported`

Specifies whether the hardware and driver support ROVs.
The runtime sets this member to **TRUE** if the hardware and driver support this option.

### `ConservativeRasterizationTier`

Specifies whether the hardware and driver support conservative rasterization.
The runtime sets this member to a [D3D11_CONSERVATIVE_RASTERIZATION_TIER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_conservative_rasterization_tier)-typed value that indicates if the hardware and driver support conservative rasterization and at what tier level.

### `TiledResourcesTier`

Specifies whether the hardware and driver support tiled resources.
The runtime sets this member to a [D3D11_TILED_RESOURCES_TIER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_tiled_resources_tier)-typed value that indicates if the hardware and driver support tiled resources and at what tier level.

### `MapOnDefaultTextures`

Specifies whether the hardware and driver support mapping on default textures.
The runtime sets this member to **TRUE** if the hardware and driver support this option.

### `StandardSwizzle`

Specifies whether the hardware and driver support standard swizzle.
The runtime sets this member to **TRUE** if the hardware and driver support this option.

### `UnifiedMemoryArchitecture`

Specifies whether the hardware and driver support Unified Memory Architecture.
The runtime sets this member to **TRUE** if the hardware and driver support this option.

## Remarks

If **MapOnDefaultTextures** is TRUE, applications may create textures using D3D11_USAGE_DEFAULT in combination with non-zero a D3D11_CPU_ACCESS_FLAG value.
For performance reasons it is typically undesirable to create a default texture with CPU access flags unless the **UnifiedMemoryArchitecture** option is TRUE, or CPU / GPU usage of the texture is tightly interleaved.

Default textures may not be in a mapped state while either bound to the pipeline to referenced by an operation issued to a context.
Default textures may not be mapped by a deferred context.
Default textures may not be created shareable.

See [D3D11_TEXTURE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ne-d3d11_3-d3d11_texture_layout) for texture swizzle options and restrictions.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)