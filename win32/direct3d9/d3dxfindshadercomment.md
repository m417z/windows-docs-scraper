# D3DXFindShaderComment function

Searches through a shader for a particular comment. The comment is identified by a four-character code (FOURCC) in the first DWORD of the comment.

## Parameters

*pFunction* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the shader function DWORD stream.

*FourCC* \[in\]

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

FOURCC code that identifies the comment block. See [FourCC Formats](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat).

*ppData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Returns a pointer to the comment data (not including the comment token and FOURCC code). This value can be **NULL**.

*pSizeInBytes* \[out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Returns the size of the comment data in bytes. This value can be **NULL**.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the comment is not found, and no other error has occurred, S\_FALSE is returned.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Shader.h |
| Library<br> | D3dx9.lib |

## See also

[Shader Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-shader)

