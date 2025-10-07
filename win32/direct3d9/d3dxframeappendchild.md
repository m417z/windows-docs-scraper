# D3DXFrameAppendChild function

Adds a child frame to a frame.

## Parameters

*pFrameParent* \[in\]

Type: **[**LPD3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe)**

Pointer to the parent node.

*pFrameChild* \[in\]

Type: **const [**D3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe)\***

Pointer to the child node.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |
| Library<br> | D3dx9.lib |

## See also

[Animation Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-animation)

