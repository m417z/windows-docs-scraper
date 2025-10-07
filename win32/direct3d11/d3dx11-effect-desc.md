# D3DX11\_EFFECT\_DESC structure

Describes an effect.

## Members

**ConstantBuffers**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of constant buffers in this effect.

**GlobalVariables**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of global variables in this effect.

**InterfaceVariables**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of global interfaces in this effect.

**Techniques**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of techniques in this effect.

**Groups**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of groups in this effect.

## Remarks

D3DX11\_EFFECT\_DESC is used with [**ID3DX11Effect::GetDesc**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effect-getdesc).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-structures)

