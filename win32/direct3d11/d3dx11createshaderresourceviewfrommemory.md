# D3DX11CreateShaderResourceViewFromMemory function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use these:
>
> - [DirectXTK](https://github.com/Microsoft/DirectXTK) library (runtime), **CreateXXXTextureFromMemory** (where XXX is DDS or WIC)
> - [DirectXTex](https://github.com/Microsoft/DirectXTex) library (tools), **LoadFromXXXMemory** (where XXX is WIC, DDS, or TGA; WIC doesn't support DDS and TGA; D3DX 9 supported TGA as a common art source format for games) then **CreateShaderResourceView**

Create a shader-resource view from a file in memory.

## Parameters

*pDevice* \[in\]

Type: **[**ID3D11Device**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11device)\***

A pointer to the device (see [**ID3D11Device**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11device)) that will use the resource.

*pSrcData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the file in memory that contains the shader-resource view.

*SrcDataSize* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the file in memory.

*pLoadInfo* \[in\]

Type: **[**D3DX11\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-load-info)\***

Optional. Identifies the characteristics of a texture (see [**D3DX11\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-load-info)) when the data processor is created; set this to **NULL** to read the characteristics of a texture when the texture is loaded.

*pPump* \[in\]

Type: **[**ID3DX11ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump)\***

A pointer to a thread pump interface (see [**ID3DX11ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump)). If **NULL** is specified, this function will behave synchronously and will not return until it is finished.

*ppShaderResourceView* \[out\]

Type: **[**ID3D11ShaderResourceView**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11shaderresourceview)\*\***

Address of a pointer to the newly created shader resource view. See [**ID3D11ShaderResourceView**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11shaderresourceview).

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

