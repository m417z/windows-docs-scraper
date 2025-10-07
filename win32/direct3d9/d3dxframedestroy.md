# D3DXFrameDestroy function

Destroys the subtree of frames under the root, including the root.

## Parameters

*pFrameRoot* \[in\]

Type: **[**LPD3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe)**

Pointer to the root node.

*pAlloc* \[in\]

Type: **[**LPD3DXALLOCATEHIERARCHY**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxallocatehierarchy)**

Allocation interface used to deallocate nodes of the frame hierarchy.

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

