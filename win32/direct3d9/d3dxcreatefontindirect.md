# D3DXCreateFontIndirect function

Creates a font object indirectly for both a device and a font.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, the device to be associated with the font object.

*pDesc* \[in\]

Type: **const [**D3DXFONT\_DESC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfont-desc)\***

Pointer to a [**D3DXFONT\_DESC**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfont-desc) structure, describing the attributes of the font object to create. If the compiler settings require Unicode, the data type D3DXFONT\_DESC resolves to D3DXFONT\_DESCW; otherwise, the data type resolves to D3DXFONT\_DESCA. See Remarks.

*ppFont* \[out\]

Type: **[**LPD3DXFONT**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfont)\***

Returns a pointer to an [**ID3DXFont**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxfont) interface, representing the created font object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateFontIndirectW. Otherwise, the function call resolves to D3DXCreateFontIndirectA because ANSI strings are being used.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |
| Library<br> | D3dx9.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-general-purpose)

