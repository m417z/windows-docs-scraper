# D3DX11CreateAsyncTextureProcessor function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps. See Remarks.

Create a data processor to be used with a [**thread pump**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11threadpump).

## Parameters

*pDevice* \[in\]

Type: **[**ID3D11Device**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11device)\***

A pointer to the devive (see [**ID3D11Device**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11device)).

*pLoadInfo* \[in\]

Type: **[**D3DX11\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-load-info)\***

Optional. Identifies the characteristics of a texture (see [**D3DX11\_IMAGE\_LOAD\_INFO**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11-image-load-info)) when the data processor is created; set this to **NULL** to read the characteristics of a texture when the texture is loaded.

*ppDataProcessor* \[out\]

Type: **[**ID3DX11DataProcessor**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11dataprocessor)\*\***

Address of a pointer to a buffer that contains the data processor created (see [**ID3DX11DataProcessor Interface**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11dataprocessor)).

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

The return value is one of the values listed in [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This API does creates a data-processor interface and loads the texture; [**D3DX11CreateAsyncTextureInfoProcessor**](https://learn.microsoft.com/windows/win32/direct3d11/d3dx11createasynctextureinfoprocessor) creates the data-processor interface.

There s no implementation of the async loader outside of D3DX 10, and D3DX 11.

For Windows Store apps, the DirectX samples (for example, the [Direct3D tutorial sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/Direct3D%20tutorial%20sample)) include the **BasicLoader** module that uses the Windows Runtime asynchronous programming model ([**AsyncBase**](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2012/br244878(v=vs.110))).

For Win32 desktop apps, you can use the [Concurrency Runtime](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/ee207192(v=vs.100)) to implement something similar to the Windows Runtime asynchronous programming model.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

