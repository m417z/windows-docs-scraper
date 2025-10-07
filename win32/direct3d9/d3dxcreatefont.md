# D3DXCreateFont function

Creates a font object for a device and font.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, the device to be associated with the font object.

*Height* \[in\]

Type: **[**INT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The height of the characters in logical units.

*Width* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The width of the characters in logical units.

*Weight* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Typeface weight. One example is bold.

*MipLevels* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of mipmap levels.

*Italic* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

True for italic font, false otherwise.

*CharSet* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The character set of the font.

*OutputPrecision* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies how Windows should attempt to match the desired font sizes and characteristics with actual fonts. Use OUT\_TT\_ONLY\_PRECIS for instance, to ensure that you always get a TrueType font.

*Quality* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies how Windows should match the desired font with a real font. It applies to raster fonts only and should not affect TrueType fonts.

*PitchAndFamily* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pitch and family index.

*pFacename* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

String containing the typeface name. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*ppFont* \[out\]

Type: **[**LPD3DXFONT**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfont)\***

Returns a pointer to an [**ID3DXFont**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfont) interface, representing the created font object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

The creation of an ID3DXFont object requires that the device supports 32-bit color.

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateFontW. Otherwise, the function call resolves to D3DXCreateFontA because ANSI strings are being used.

If you want more information about font parameters, see [The Logical Font](https://learn.microsoft.com/windows/win32/gdi/creating-a-logical-font).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |
| Library<br> | D3dx9.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-general-purpose)

