# ID3D11Device::CreateRasterizerState

## Description

Create a rasterizer state object that tells the rasterizer stage how to behave.

## Parameters

### `pRasterizerDesc` [in]

Type: **const [D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc)***

Pointer to a rasterizer state description (see [D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc)).

### `ppRasterizerState` [out, optional]

Type: **[ID3D11RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rasterizerstate)****

Address of a pointer to the rasterizer state object created (see [ID3D11RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rasterizerstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns E_OUTOFMEMORY if there is insufficient memory to create the compute shader. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## Remarks

4096 unique rasterizer state objects can be created on a device at a time.

If an application attempts to create a rasterizer-state interface with the same state as an existing interface, the same interface will be returned and the total number of unique rasterizer state objects will stay the same.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)