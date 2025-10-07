# D3DXGetImageInfoFromFileInMemory function

Retrieves information about a given image file in memory.

## Parameters

*pSrcData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

VOID pointer to the source file in memory.

*SrcDataSize* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of file in memory, in bytes. .

*pSrcInfo* \[in\]

Type: **[**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info)\***

Pointer to a [**D3DXIMAGE\_INFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dximage-info) structure to be filled with the description of the data in the source file.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following: D3DERR\_INVALIDCALL

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

[**D3DXGetImageInfoFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxgetimageinfofromfile)

[**D3DXGetImageInfoFromResource**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxgetimageinfofromresource)

