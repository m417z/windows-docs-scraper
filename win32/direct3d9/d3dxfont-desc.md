# D3DXFONT\_DESC structure

Defines the attributes of a font.

## Members

**Height**

Type: **[**INT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height, in logical units, of the font's character cell or character.

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width, in logical units, of characters in the font.

**Weight**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Weight of the font in the range from 0 through 1000.

**MipLevels**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of mip levels requested. If this value is zero or D3DX\_DEFAULT, a complete mipmap chain is created. If the value is 1, the texture space is mapped identically to the screen space.

**Italic**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Set to **TRUE** for an Italic font.

**CharSet**

Type: **[**BYTE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Character set.

**OutputPrecision**

Type: **[**BYTE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Output precision. The output precision defines how closely the output must match the requested font height, width, character orientation, escapement, pitch, and font type.

**Quality**

Type: **[**BYTE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Output quality.

**PitchAndFamily**

Type: **[**BYTE**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pitch and family of the font.

**FaceName**

Type: **TCHAR**

A null-terminated string or characters that specifies the typeface name of the font. The length of the string must not exceed 32 characters, including the terminating null character. If FaceName is an empty string, the first font that matches the other specified attributes will be used. If the compiler settings require Unicode, the data type TCHAR resolves to WCHAR; otherwise, the data type resolves to CHAR. See Remarks.

## Remarks

The compiler setting also determines the structure type. If Unicode is defined, the D3DXFONT\_DESC structure type resolves to a D3DXFONT\_DESCW; otherwise the structure type resolves to a D3DXFONT\_DESCA.

Possible values of the above members are given in the GDI [**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta) structure.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

[**GetDesc**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfont--getdesc)

