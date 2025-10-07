# D3DX10CreateFont function

Creates a font object for a device and font.

> [!Note]
> Instead of using this function, we recommend that you use [DirectWrite](https://learn.microsoft.com/windows/win32/directwrite/direct-write-portal) and the [DirectXTK](https://github.com/Microsoft/DirectXTK) library, **SpriteFont** class.

## Parameters

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\***

Pointer to an ID3D10Device interface, the device to be associated with the font object.

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

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The character set of the font.

*OutputPrecision* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies how Windows should attempt to match the desired font sizes and characteristics with actual fonts. Use OUT\_TT\_ONLY\_PRECIS for instance, to ensure that you always get a TrueType font.

*Quality* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies how Windows should match the desired font with a real font. It applies to raster fonts only and should not affect TrueType fonts.

*PitchAndFamily* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pitch and family index.

*pFaceName* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

String containing the typeface name. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the data type resolves to LPCSTR. See Remarks.

*ppFont* \[out\]

Type: **[**LPD3DX10FONT**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10font)\***

Returns a pointer to an ID3DX10Font interface, representing the created font object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is S\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateFontW. Otherwise, the function call resolves to D3DXCreateFontA because ANSI strings are being used.

If you want more information about font parameters, see [The Logical Font](https://learn.microsoft.com/previous-versions//ms533985(v=vs.85)).

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |
| Library<br> | D3DX10.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

