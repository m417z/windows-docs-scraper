# D3DXTECHNIQUE\_DESC structure

Describes a technique used by an effect.

## Members

**Name**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

String that contains the technique name.

**Passes**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of rendering passes the technique requires. See Remarks.

**Annotations**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of annotations. See [Add Information to Effect Parameters with\_Annotations](https://learn.microsoft.com/windows/win32/direct3d9/using-an-effect).

## Remarks

Some video cards can render two textures in a single pass. However, if a card does not have this capability, it is often possible to render the same effect in two passes, using one texture for each pass.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9effect.h |

## See also

[Effect Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-structures)

