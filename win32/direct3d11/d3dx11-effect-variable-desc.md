# D3DX11\_EFFECT\_VARIABLE\_DESC structure

Describes an effect variable.

## Members

**Name**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of this variable, annotation, or structure member.

**Semantic**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Semantic string of this variable or structure member (NULL for annotations or if not present).

**Flags**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional flags for effect variables.

**Annotations**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of annotations on this variable (always 0 for annotations).

**BufferOffset**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset into containing cbuffer or tbuffer (always 0 for annotations or variables not in constant buffers).

**ExplicitBindPoint**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Used if the variable has been explicitly bound using the register keyword. Check Flags for D3DX11\_EFFECT\_VARIABLE\_EXPLICIT\_BIND\_POINT.

## Remarks

D3DX11\_EFFECT\_VARIABLE\_DESC is used with [**ID3DX11EffectVariable::GetDesc**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effectvariable-getdesc).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-structures)

