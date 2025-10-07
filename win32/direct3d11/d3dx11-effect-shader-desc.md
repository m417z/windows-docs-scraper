# D3DX11\_EFFECT\_SHADER\_DESC structure

Describes an effect shader.

## Members

**pInputSignature**

Type: **const [**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

Passed into CreateInputLayout. Only valid on a vertex shader or geometry shader. See [**ID3D11Device::CreateInputLayout**](https://learn.microsoft.com/windows/desktop/api/D3D11/nf-d3d11-id3d11device-createinputlayout).

**IsInline**

Type: **[**BOOL**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** is the shader is defined inline; otherwise **FALSE**.

**pBytecode**

Type: **const [**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

Shader bytecode.

**BytecodeLength**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The length of pBytecode.

**SODecls**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Stream out declaration string (for geometry shader with SO).

**RasterizedStream**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates which stream is rasterized. D3D11 geometry shaders can output up to four streams of data, one of which can be rasterized.

**NumInputSignatureEntries**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of entries in the input signature.

**NumOutputSignatureEntries**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of entries in the output signature.

**NumPatchConstantSignatureEntries**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of entries in the patch constant signature.

## Remarks

D3DX11\_EFFECT\_SHADER\_DESC is used with [**ID3DX11EffectShaderVariable::GetShaderDesc**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effectshadervariable-getshaderdesc).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-structures)

