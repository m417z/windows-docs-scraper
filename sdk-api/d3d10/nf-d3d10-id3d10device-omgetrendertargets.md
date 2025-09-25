# ID3D10Device::OMGetRenderTargets

## Description

Get pointers to the render targets and the depth-stencil buffer that are available to the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

## Parameters

### `NumViews` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of render targets to retrieve.

### `ppRenderTargetViews` [out]

Type: **[ID3D10RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rendertargetview)****

Pointer to an array of render targets views (see [ID3D10RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rendertargetview)) to be filled with the render targets from the device. Specify **NULL** for this parameter when retrieval of a render target is not needed.

### `ppDepthStencilView` [out]

Type: **[ID3D10DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilview)****

Pointer to a depth-stencil view (see [ID3D10DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilview)) to be filled with the depth-stencil information from the device. Specify **NULL** for this parameter when retrieval of the depth-stencil view is not needed.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)