# D3DXGetVertexShaderProfile function

Returns the name of the highest high-level shader language (HLSL) profile supported by a given device.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to the device. See [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9).

## Return value

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The HLSL profile name.

If the device does not support vertex shaders then the function returns **NULL**.

## Remarks

A shader profile specifies the assembly shader version to use and the capabilities available to the HLSL compiler when compiling a shader. The following table lists the vertex shader profiles that are supported.

| Shader Profile | Description |
|----------------|-------------|
| vs_1_1 | Compile to vs_1_1 version. |
| vs_2_0 | Compile to vs_2_0 version. |
| vs_2_a | Same as the vs_2_0 profile, with the following additional capabilities available for the compiler to target:

* Number of Temporary Registers (r#) is greater than or equal to 13.
* Dynamic flow control instruction.
* Predication.

|
| vs_3_0 | Compile to vs_3_0 version. |

For more information about the differences between shader versions, see [Vertex Shader Differences](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx9-graphics-reference-asm-vs-differences).

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Shader.h |
| Library<br> | D3dx9.lib |

## See also

[Shader Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-shader)

