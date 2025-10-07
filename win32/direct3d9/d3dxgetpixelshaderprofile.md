# D3DXGetPixelShaderProfile function

Returns the name of the highest high-level shader language (HLSL) profile supported by a given device.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to the device. See [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9).

## Return value

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The HLSL profile name.

If the device does not support pixel shaders then the function returns **NULL**.

## Remarks

A shader profile specifies the assembly shader version to use and the capabilities available to the HLSL compiler when compiling a shader. The following table lists the pixel shader profiles that are supported.

| Shader Profile | Description |
|----------------|-------------|
| ps_1_1 | Compile to ps_1_1 version. |
| ps_1_2 | Compile to ps_1_2 version. |
| ps_1_3 | Compile to ps_1_3 version. |
| ps_1_4 | Compile to ps_1_4 version. |
| ps_2_0 | Compile to ps_2_0 version. |
| ps_2_a | Same as the ps_2_0 profile, with the following additional capabilities available for the compiler to target:

* Number of Temporary Registers (r#) is greater than or equal to 22.
* Arbitrary source swizzle.
* Gradient instructions: dsx, dsy.
* Predication.
* No dependent texture read limit.
* No limit for the number of texture instructions.

|
| ps_2_b | Same as the ps_2_0 profile, with the following additional capabilities available for the compiler to target:

* Number of Temporary Registers (r#) is greater than or equal to 32.
* No limit for the number of texture instructions.

|
| ps_3_0 | Compile to ps_3_0 version. |

For more information about the differences between shader versions, see [Pixel Shader Differences](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx9-graphics-reference-asm-ps-differences).

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Shader.h |
| Library<br> | D3dx9.lib |

## See also

[Shader Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-shader)

