# ID3D10Device::CreateRasterizerState

## Description

Create a rasterizer state object that tells the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage) how to behave.

## Parameters

### `pRasterizerDesc` [in]

Type: **const [D3D10_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_rasterizer_desc)***

Pointer to a rasterizer state description (see [D3D10_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_rasterizer_desc)).

### `ppRasterizerState` [out]

Type: **[ID3D10RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rasterizerstate)****

Address of a pointer to the rasterizer state object created (see [ID3D10RasterizerState Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rasterizerstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

4096 unique rasterizer state objects can be created on a device at a time.

If an application attempts to create a rasterizer state with the same description as an already existing rasterizer state, then the same interface with an incremented reference count will be returned and the total number of unique rasterizer state objects will stay the same.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)