# D3DX11ComputeNormalMap function

> [!Note]
> The D3DX (D3DX 9, D3DX 10, and D3DX 11) utility library is deprecated for Windows 8 and is not supported for Windows Store apps.

> [!Note]
> Instead of using this function, we recommend that you use the [DirectXTex](https://github.com/Microsoft/DirectXTex) library, **ComputeNormalMap**.

Converts a height map into a normal map. The (x,y,z) components of each normal are mapped to the (r,g,b) channels of the output texture.

## Parameters

*pContext* \[in\]

Type: **[**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext)\***

Pointer to an [**ID3D11DeviceContext**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11devicecontext) interface, representing the source height-map texture.

*pSrcTexture* \[in\]

Type: **[**ID3D11Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11texture2d)\***

Pointer to an [**ID3D11Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11texture2d) interface, representing the source height-map texture.

*Flags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more D3DX\_NORMALMAP flags that control generation of normal maps.

*Channel* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One D3DX\_CHANNEL flag specifying the source of height information.

*Amplitude* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Constant value multiplier that increases (or decreases) the values in the normal map. Higher values usually make bumps more visible, lower values usually make bumps less visible.

*pDestTexture* \[in\]

Type: **[**ID3D11Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11texture2d)\***

Pointer to an [**ID3D11Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D11/nn-d3d11-id3d11texture2d) interface, representing the destination texture.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following value: D3DERR\_INVALIDCALL.

## Remarks

This method computes the normal by using the central difference with a kernel size of 3x3. RGB channels in the destination contain biased (x,y,z) components of the normal. The central differencing denominator is hardcoded to 2.0.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX11tex.h |
| Library<br> | D3DX11.lib |

## See also

[D3DX Functions](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3dx11-functions)

