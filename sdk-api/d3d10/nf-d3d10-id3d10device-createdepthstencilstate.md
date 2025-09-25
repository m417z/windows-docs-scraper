# ID3D10Device::CreateDepthStencilState

## Description

Create a depth-stencil state object that encapsulates [depth-stencil test](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) information for the output-merger stage.

## Parameters

### `pDepthStencilDesc` [in]

Type: **const [D3D10_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_desc)***

Pointer to a depth-stencil state description (see [D3D10_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_desc)).

### `ppDepthStencilState` [out]

Type: **[ID3D10DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilstate)****

Address of a pointer to the depth-stencil state object created (see [ID3D10DepthStencilState Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

4096 unique depth-stencil state objects can be created on a device at a time.

If an application attempts to create a depth-stencil state with the same description as an already existing depth-stencil state, then the same interface with an incremented reference count will be returned and the total number of unique depth-stencil state objects will stay the same.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)