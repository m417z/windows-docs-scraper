# D3DX11\_GROUP\_DESC structure

Describes an effect group.

## Members

**Name**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of this group (only **NULL** if global).

**Techniques**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of techniques contained in group.

**Annotations**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of annotations on this group.

## Remarks

D3DX11\_GROUP\_DESC is used with [**ID3DX11EffectTechnique::GetDesc**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effecttechnique-getdesc).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-structures)

