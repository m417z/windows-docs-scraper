# D3DXCreateTextureShader function

Creates a texture shader object from the compiled shader.

## Parameters

*pFunction* \[in\]

Type: **const [**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the function DWORD stream.

*ppTextureShader* \[out\]

Type: **[**LPD3DXTEXTURESHADER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtextureshader)\***

Returns an [**ID3DXTextureShader**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtextureshader) object which can be used to procedurally fill the contents of a texture using the [**D3DXFillTextureTX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfilltexturetx) functions.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_INVALIDCALL, D3DXERR\_INVALIDDATA, E\_OUTOFMEMORY.

## Requirements

| Requirement | Value |
|--------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX9Shader.h |
| Library<br> | D3dx9.lib |

## See also

[Shader Functions](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-shader)

