# D3DXCreateRenderToSurface function

Creates a render surface.

## Parameters

*pDevice* \[in\]

Type: **[**LPDIRECT3DDEVICE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)**

Pointer to an [**IDirect3DDevice9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface, the device to be associated with the render surface.

*Width* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the render surface, in pixels.

*Height* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the render surface, in pixels.

*Format* \[in\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the pixel format of the render surface.

*DepthStencil* \[in\]

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If **TRUE**, the render surface supports a depth-stencil surface. Otherwise, this member is set to **FALSE**. This function will create a new depth buffer.

*DepthStencilFormat* \[in\]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

If *DepthStencil* is set to **TRUE**, this parameter is a member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the depth-stencil format of the render surface.

*ppRenderToSurface* \[out\]

Type: **[**LPD3DXRENDERTOSURFACE**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxrendertosurface)\***

Address of a pointer to an [**ID3DXRenderToSurface**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxrendertosurface) interface, representing the created render surface.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |
| Library<br> | D3dx9.lib |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-general-purpose)

