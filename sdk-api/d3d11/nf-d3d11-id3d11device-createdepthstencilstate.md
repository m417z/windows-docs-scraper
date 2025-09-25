# ID3D11Device::CreateDepthStencilState

## Description

Create a depth-stencil state object that encapsulates depth-stencil test information for the output-merger stage.

## Parameters

### `pDepthStencilDesc` [in]

Type: **const [D3D11_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_desc)***

Pointer to a depth-stencil state description (see [D3D11_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_desc)).

### `ppDepthStencilState` [out, optional]

Type: **[ID3D11DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilstate)****

Address of a pointer to the depth-stencil state object created (see [ID3D11DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

4096 unique depth-stencil state objects can be created on a device at a time.

If an application attempts to create a depth-stencil-state interface with the same state as an existing interface, the same interface will be returned and the total number of unique depth-stencil state objects will stay the same.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)