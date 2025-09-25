# D3D_SHADER_INPUT_FLAGS enumeration

## Description

Values that identify shader-input options.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_SIF_USERPACKED:0x1`

Assign a shader input to a register based on the register assignment in the HLSL code (instead of letting the compiler choose the register).

### `D3D_SIF_COMPARISON_SAMPLER:0x2`

Use a comparison sampler, which uses the [SampleCmp (DirectX HLSL Texture Object)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmp) and [SampleCmpLevelZero (DirectX HLSL Texture Object)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmplevelzero) sampling functions.

### `D3D_SIF_TEXTURE_COMPONENT_0:0x4`

A 2-bit value for encoding texture components.

### `D3D_SIF_TEXTURE_COMPONENT_1:0x8`

A 2-bit value for encoding texture components.

### `D3D_SIF_TEXTURE_COMPONENTS:0xc`

A 2-bit value for encoding texture components.

### `D3D_SIF_UNUSED:0x10`

This value is reserved.

### `D3D10_SIF_USERPACKED`

Assign a shader input to a register based on the register assignment in the HLSL code (instead of letting the compiler choose the register).

### `D3D10_SIF_COMPARISON_SAMPLER`

Use a comparison sampler, which uses the [SampleCmp (DirectX HLSL Texture Object)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmp) and [SampleCmpLevelZero (DirectX HLSL Texture Object)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmplevelzero) sampling functions.

### `D3D10_SIF_TEXTURE_COMPONENT_0`

A 2-bit value for encoding texture components.

### `D3D10_SIF_TEXTURE_COMPONENT_1`

A 2-bit value for encoding texture components.

### `D3D10_SIF_TEXTURE_COMPONENTS`

A 2-bit value for encoding texture components.

### `D3D_SIF_FORCE_DWORD:0x7fffffff`

Forces the enumeration to compile to 32 bits.
This value is not used directly by titles.

## Remarks

**D3D_SHADER_INPUT_FLAGS**-typed values are specified in
the **uFlags** member of the [D3D11_SHADER_INPUT_BIND_DESC](https://learn.microsoft.com/windows/win32/api/d3d11shader/ns-d3d11shader-d3d11_shader_input_bind_desc) structure.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)