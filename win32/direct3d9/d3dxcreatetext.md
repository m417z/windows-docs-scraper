# D3DXCreateText function

Creates a mesh containing the specified text, using the font associated with the device context.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to the device that created the mesh.

*hDC* \[in\]

Type: **HDC**

Device context, containing the font for output. The font selected by the device context must be a TrueType font.

*pText* \[in\]

Type: **[**LPCTSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that specifies the text to generate. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks.

*Deviation* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum chordal deviation from TrueType font outlines.

*Extrusion* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Amount to extrude text in the negative z-direction.

*ppMesh* \[out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Pointer to the returned mesh.

*ppAdjacency* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Pointer to a buffer containing adjacency information. May be **NULL**.

*pGlyphMetrics* \[out\]

Type: **[**LPGLYPHMETRICSFLOAT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-glyphmetricsfloat)**

Pointer to an array of [**GLYPHMETRICSFLOAT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-glyphmetricsfloat) structures that contain the glyph metric data. Each element contains information about the position and orientation of the corresponding glyph in the string. The number of elements in the array should be equal to the number of characters in the string. Note that the origin in each structure is not relative to the entire string, but rather is relative to that character cell. To compute the entire bounding box, add the increment for each glyph while traversing the string. If you are not concerned with the glyph sizes, set this parameter to **NULL**.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

The compiler setting also determines the function version. If Unicode is defined, the function call resolves to D3DXCreateTextW. Otherwise, the function call resolves to D3DXCreateTextA because ANSI strings are being used.

This function creates a mesh with the D3DXMESH\_MANAGED creation option and [D3DFVF\_XYZ \| D3DFVF\_NORMAL](https://learn.microsoft.com/windows/win32/direct3d9/d3dfvf) flexible vertex format (FVF).

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3dx9shape.h |
| Library<br> | D3dx9.lib |

## See also

[Shape Drawing Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-shape)

