# D3DXEFFECT\_DESC structure

Describes an effect object.

## Members

**Creator**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

String that contains the name of the effect creator.

**Parameters**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of parameters used for effect.

**Techniques**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of techniques that can render the effect.

**Functions**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of functions that can render the effect.

## Remarks

An effect object can contain multiple rendering techniques and parameters for the same effect.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9effect.h |

## See also

[Effect Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-structures)

