# D3DX10ComputeNormalMap function

Converts a height map into a normal map. The (x,y,z) components of each normal are mapped to the (r,g,b) channels of the output texture.

## Parameters

*pSrcTexture* \[in\]

Type: **[**ID3D10Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10texture2d)\***

Pointer to an ID3D10Texture2D interface, representing the source height-map texture.

*Flags* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

One or more D3DX\_NORMALMAP flags that control generation of normal maps.

*Channel* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

One D3DX\_CHANNEL flag specifying the source of height information.

*Amplitude* \[in\]

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Constant value multiplier that increases (or decreases) the values in the normal map. Higher values usually make bumps more visible, lower values usually make bumps less visible.

*pDestTexture* \[in\]

Type: **[**ID3D10Texture2D**](https://learn.microsoft.com/windows/desktop/api/D3D10/nn-d3d10-id3d10texture2d)\***

Pointer to an ID3D10Texture2D interface, representing the destination texture.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be the following value: D3DERR\_INVALIDCALL.

## Remarks

This method computes the normal by using the central difference with a kernel size of 3x3. RGB channels in the destination contain biased (x,y,z) components of the normal. The central differencing denominator is hardcoded to 2.0.

## Requirements

| Requirement | Value |
|--------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3DX10Tex.h |
| Library<br> | D3DX10.lib |

## See also

[Texture Functions in D3DX 10](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-functions-texturing)

