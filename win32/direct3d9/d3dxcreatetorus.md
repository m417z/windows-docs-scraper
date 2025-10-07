# D3DXCreateTorus function

Uses a left-handed coordinate system to create a mesh containing a torus.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, representing the device associated with the created torus mesh.

*InnerRadius* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Inner-radius of the torus. Value should be greater than or equal to 0.0f.

*OuterRadius* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Outer-radius of the torus. Value should be greater than or equal to 0.0f.

*Sides* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of sides in a cross-section. Value must be greater than or equal to 3.

*Rings* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of rings making up the torus. Value must be greater than or equal to 3.

*ppMesh* \[out\]

Type: **[**LPD3DXMESH**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh)\***

Address of a pointer to the output shape, an [**ID3DXMesh**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxmesh) interface.

*ppAdjacency* \[out\]

Type: **[**LPD3DXBUFFER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer)\***

Address of a pointer to an [**ID3DXBuffer**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxbuffer) interface. When the method returns, this parameter is filled with an array of three DWORDs per face that specify the three neighbors for each face in the mesh. **NULL** can be specified.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Remarks

The created torus is centered at the origin, and its axis is aligned with the z-axis. The inner radius of the torus is the radius of the cross-section (the minor radius), and the outer radius of the torus is the radius of the central hole.

This function returns a mesh that can be used later for drawing or manipulation by the application.

This function creates a mesh with the D3DXMESH\_MANAGED creation option and [D3DFVF\_XYZ \| D3DFVF\_NORMAL](https://learn.microsoft.com/windows/win32/direct3d9/d3dfvf) flexible vertex format (FVF).

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Header<br> | D3dx9shape.h |
| Library<br> | D3dx9.lib |

## See also

[Shape Drawing Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-shape)

