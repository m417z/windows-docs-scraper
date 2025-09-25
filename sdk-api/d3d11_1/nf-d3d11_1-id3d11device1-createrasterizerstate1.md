# ID3D11Device1::CreateRasterizerState1

## Description

Creates a rasterizer state object that informs the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage) how to behave and forces the sample count while UAV rendering or rasterizing.

## Parameters

### `pRasterizerDesc` [in]

A pointer to a [D3D11_RASTERIZER_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-cd3d11_rasterizer_desc1) structure that describes the rasterizer state.

### `ppRasterizerState` [out, optional]

Address of a pointer to the [ID3D11RasterizerState1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11rasterizerstate1) interface for the rasterizer state object created.

## Return value

This method returns E_OUTOFMEMORY if there is insufficient memory to create the rasterizer state object. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## Remarks

An app can create up to 4096 unique rasterizer state objects. For each object created, the runtime checks to see if a previous object
has the same state. If such a previous object exists, the runtime will return a pointer to previous instance instead of creating a duplicate object.

## See also

[ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1)