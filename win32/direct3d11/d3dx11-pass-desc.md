# D3DX11\_PASS\_DESC structure

Describes an effect pass, which contains pipeline state.

## Members

**Name**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of this pass (**NULL** if not anonymous).

**Annotations**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of annotations on this pass.

**pIAInputSignature**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

Signature from the vertex shader or geometry shader (if there is no vertex shader) or **NULL** if neither exists.

**IAInputSignatureSize**

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Singature size in bytes.

**StencilRef**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The stencil-reference value used in the depth-stencil state.

**SampleMask**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The sample mask for the blend state.

**BlendFactor**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The per-component blend factors (RGBA) for the blend state.

## Remarks

D3DX11\_PASS\_DESC is used with [**ID3DX11EffectPass::GetDesc**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effectpass-getdesc).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-structures)

