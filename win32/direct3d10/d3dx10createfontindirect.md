# D3DX10CreateFontIndirect function

Creates a font object.

> [!Note]
> Instead of using this function, we recommend that you use [DirectWrite](https://learn.microsoft.com/windows/win32/directwrite/direct-write-portal) and the [DirectXTK](https://github.com/Microsoft/DirectXTK) library, **SpriteFont** class.

## Parameters

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\***

Pointer to an [**ID3D10Device Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device) interface.

*pDesc* \[in\]

Type: **const [**D3DX10\_FONT\_DESC**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-font-desc)\***

Pointer to a [**D3DX10\_FONT\_DESC**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-font-desc) structure, describing the attributes of the font object to create. If Unicode is defined, the function call resolves to D3DXCreateFontIndirectW. Otherwise, the function call resolves to D3DXCreateFontIndirectA because ANSI strings are being used.

*ppFont* \[out\]

Type: **[**LPD3DX10FONT**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10font)\***

Returns a pointer to an [**ID3DX10Font Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10font).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Core.h |
| Library<br> | D3DX10.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

