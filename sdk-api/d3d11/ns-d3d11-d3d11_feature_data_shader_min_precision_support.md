# D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT structure

## Description

**Note** This structure is supported by the Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems.

Describes precision support options for shaders in the current graphics driver.

## Members

### `PixelShaderMinPrecision`

A combination of [D3D11_SHADER_MIN_PRECISION_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_shader_min_precision_support)-typed values that are combined by using a bitwise OR operation. The resulting value specifies minimum precision levels that the driver supports for the pixel shader. A value of zero indicates that the driver supports only full 32-bit precision for the pixel shader.

### `AllOtherShaderStagesMinPrecision`

A combination of [D3D11_SHADER_MIN_PRECISION_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_shader_min_precision_support)-typed values that are combined by using a bitwise OR operation. The resulting value specifies minimum precision levels that the driver supports for all other shader stages. A value of zero indicates that the driver supports only full 32-bit precision for all other shader stages.

## Remarks

For hardware at Direct3D 10 and higher [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro), the runtime sets both members identically. For hardware at Direct3D 9.3 and lower feature levels, the runtime can set a lower precision support in the **PixelShaderMinPrecision** member than the **AllOtherShaderStagesMinPrecision** member; for 9.3 and lower, all other shader stages represent only the vertex shader.

For more info about HLSL minimum precision, see [using HLSL minimum precision](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-1-features).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)