## Description

Indicates whether or not the SUM combiner can be used, and whether or not *SV_ShadingRate* can be set from a mesh shader.

## Members

### `VariableRateShadingSumCombinerSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not the SUM combiner can be used (this relates to [variable-rate shading](https://learn.microsoft.com/windows/desktop/direct3d12/vrs) Tier 2). `true` if it can, otherwise `false`.

### `MeshShaderPerPrimitiveShadingRateSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not *SV_ShadingRate* can be set from a mesh shader (this relates to [variable-rate shading](https://learn.microsoft.com/windows/desktop/direct3d12/vrs) Tier 2). `true` if it can, otherwise `false`.

## Remarks

## See also

* [Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs)