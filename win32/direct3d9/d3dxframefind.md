# D3DXFrameFind function

Finds the child frame of a root frame.

## Parameters

*pFrameRoot* \[in\]

Type: **const [**D3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe)\***

Pointer to the root frame. See [**D3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe).

*Name* \[in\]

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Name of the child frame to find.

## Return value

Type: **[**LPD3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe)**

Returns the child frame if it is found, or **NULL** otherwise. See [**D3DXFRAME**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxframe).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |
| Library<br> | D3dx9.lib |

## See also

[Animation Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-animation)

