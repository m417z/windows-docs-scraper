# ID3D11Device3::CreateRasterizerState2

## Description

Creates a rasterizer state object that informs the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage) how to behave and forces the sample count while UAV rendering or rasterizing.

## Parameters

### `pRasterizerDesc` [in]

Type: **const [D3D11_RASTERIZER_DESC2](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_rasterizer_desc2)***

A pointer to a [D3D11_RASTERIZER_DESC2](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_rasterizer_desc2) structure that describes the rasterizer state.

### `ppRasterizerState` [out, optional]

Type: **[ID3D11RasterizerState2](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11rasterizerstate2)****

A pointer to a memory block that receives a pointer to a [ID3D11RasterizerState2](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11rasterizerstate2) interface for the created rasterizer state object. Set this parameter to **NULL** to validate the other input parameters (the method will return **S_FALSE** if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns E_OUTOFMEMORY if there is insufficient memory to create the rasterizer state object. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## See also

[ID3D11Device3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11device3)