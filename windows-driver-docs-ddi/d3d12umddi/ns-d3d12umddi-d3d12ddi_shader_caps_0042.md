# D3D12DDI_SHADER_CAPS_0042 structure

## Description

The **D3D12DDI_SHADER_CAPS_0042** structure contains display device shader capabilities that the driver supports.

## Members

### `MinPrecision`

A bitwise OR of [**D3D12DDI_SHADER_MIN_PRECISION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_shader_min_precision) values that describe the driver's minimum precision support options for shaders.

### `DoubleOps`

A Boolean value that specifies whether the driver allows **double** types for shader operations (TRUE indicates driver support).

### `ShaderSpecifiedStencilRef`

A Boolean value that specifies whether the driver supports pixel shader stencil ref (TRUE indicates driver support).

### `TypedUAVLoadAdditionalFormats`

A Boolean value that specifies whether the driver supports the loading of additional formats for typed unordered-access views (UAVs) (TRUE indicates driver support).

### `ROVs`

A Boolean value that specifies whether the driver supports [rasterizer ordered views](https://learn.microsoft.com/windows/win32/direct3d12/directx-12-glossary) (TRUE indicates driver support).

### `WaveOps`

A Boolean value that specifies whether the driver supports wave operations.

### `WaveLaneCountMin`

Specifies the minimum number of lanes in the SIMD (single instruction, multiple data) wave that the driver supports.

### `WaveLaneCountMax`

Specifies the maximum number of lanes in the SIMD wave that the driver supports.

### `TotalLaneCount`

Specifies the total number of SIMD lanes on the hardware.

### `Int64Ops`

A Boolean value that indicates whether the driver supports 64-bit operations (TRUE indicates driver support).

### `Native16BitOps`

A Boolean value that indicates whether the driver supports native 64-bit operations (TRUE indicates driver support).

## Remarks

The user-mode display driver returns these caps when the D3D runtime calls UMD's [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function with the **Type** member of the [**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure set to **D3D12DDICAPS_TYPE_SHADER**.
## See also

[**D3D12DDI_SHADER_CAPS_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shader_caps_0084)

[**D3D12DDICAPS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type)

[**D3DDDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)