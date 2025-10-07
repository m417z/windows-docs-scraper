# D3DX10CreateAsyncShaderResourceViewProcessor function

Create a data processor that will load a resource and then create a shader-resource view for it. Data processors are a component of the asynchronous data loading feature in D3DX10 that uses [**thread pumps**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump).

## Parameters

*pDevice* \[in\]

Type: **[**ID3D10Device**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)\***

Pointer to the Direct3D device (see [**ID3D10Device Interface**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10device)) that will be used to create a resource and a shader-resource view for that resource.

*pLoadInfo* \[in\]

Type: **[**D3DX10\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-load-info)\***

Optional. Identifies the characteristics of a texture (see [**D3DX10\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-load-info)) when the data processor is created; set this to **NULL** to read the characteristics of a texture when the texture is loaded.

*ppDataProcessor* \[out\]

Type: **[**ID3DX10DataProcessor**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)\*\***

Address of a pointer to a buffer that contains the data processor created (see [**ID3DX10DataProcessor Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3DX10Async.h |

## See also

[General Purpose Functions](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-general-purpose)

