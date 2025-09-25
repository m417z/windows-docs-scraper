## Description

Indicates the level of support that the adapter provides for variable-rate shading (VRS), and indicates whether or not background processing is supported. For more info, see [Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs), and the [Direct3D 12 background processing spec](https://microsoft.github.io/DirectX-Specs/d3d/BackgroundProcessing.html).

## Members

### `AdditionalShadingRatesSupported`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether 2x4, 4x2, and 4x4 coarse pixel sizes are supported for single-sampled rendering; and whether coarse pixel size 2x4 is supported for 2x MSAA. `true` if those sizes are supported, otherwise `false`.

### `PerPrimitiveShadingRateSupportedWithViewportIndexing`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether the per-provoking-vertex (also known as per-primitive) rate can be used with more than one viewport. If so, then, in that case, that rate can be used when `SV_ViewportIndex` is written to. `true` if that rate can be used with more than one viewport, otherwise `false`.

### `VariableShadingRateTier`

Type: **[D3D12_VARIABLE_SHADING_RATE_TIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_variable_shading_rate_tier)**

Indicates the shading rate tier.

### `ShadingRateImageTileSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates the tile size of the screen-space image as a **UINT**.

### `BackgroundProcessingSupported`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not background processing is supported. `true` if background processing is supported, otherwise `false`. For more info, see the [Direct3D 12 background processing spec](https://microsoft.github.io/DirectX-Specs/d3d/BackgroundProcessing.html).

## Remarks

## See also

* [Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs)
* [Direct3D 12 background processing spec](https://microsoft.github.io/DirectX-Specs/d3d/BackgroundProcessing.html)