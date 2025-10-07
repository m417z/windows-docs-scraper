# D3DX10CreateShaderResourceViewFromMemory function

Create a shader-resource view from a file in memory.

## Parameters

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\***

A pointer to the device (see [**ID3D10Device Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)) that will use the resource.

*pSrcData* \[in\]

Type: **[**LPCVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to the file in memory that contains the shader-resource view.

*SrcDataSize* \[in\]

Type: **[**SIZE\_T**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the file in memory.

*pLoadInfo* \[in\]

Type: **[**D3DX10\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-load-info)\***

Optional. Identifies the characteristics of a texture (see [**D3DX10\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-load-info)) when the data processor is created; set this to **NULL** to read the characteristics of a texture when the texture is loaded.

*pPump* \[in\]

Type: **[**ID3DX10ThreadPump**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)\***

A pointer to a thread pump interface (see [**ID3DX10ThreadPump Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump)). If **NULL** is specified, this function will behave synchronously and will not return until it is finished.

*ppShaderResourceView* \[out\]

Type: **[**ID3D10ShaderResourceView**](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview)\*\***

Address of a pointer to the newly created shader resource view. See [**ID3D10ShaderResourceView Interface**](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview).

*pHResult* \[out\]

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)\***

A pointer to the return value. May be **NULL**. If *pPump* is not **NULL**, then *pHResult* must be a valid memory location until the asynchronous execution completes.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |
| Library<br> | D3DX10.lib |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

