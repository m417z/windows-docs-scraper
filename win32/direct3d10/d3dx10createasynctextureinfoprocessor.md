# D3DX10CreateAsyncTextureInfoProcessor function

Create a data processor to be used with a [**thread pump**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10threadpump).

## Parameters

*pLoadInfo* \[in\]

Type: **[**D3DX10\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-load-info)\***

Optional. Identifies the characteristics of a texture (see [**D3DX10\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10-image-load-info)) when the data processor is created; set this to **NULL** to read the characteristics of a texture when the texture is loaded.

*ppDataProcessor* \[out\]

Type: **[**ID3DX10DataProcessor**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)\*\***

Address of a pointer to a buffer that contains the data processor created (see [**ID3DX10DataProcessor Interface**](https://learn.microsoft.com/windows/win32/direct3d10/id3dx10dataprocessor)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This API does creates a data-processor interface; [**D3DX10CreateAsyncTextureProcessor**](https://learn.microsoft.com/windows/win32/direct3d10/d3dx10createasynctextureprocessor) creates the data-processor interface and loads the texture.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |
| Library<br> | D3DX10.lib |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

