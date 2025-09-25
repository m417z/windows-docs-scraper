# ID3D11DeviceContext::OMGetRenderTargets

## Description

Get pointers to the resources bound to the output-merger stage.

## Parameters

### `NumViews` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of render targets to retrieve.

### `ppRenderTargetViews` [out, optional]

Type: **[ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview)****

Pointer to an array of [ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview)s which represent render target views. Specify **NULL** for this parameter when retrieval of a render target is not needed.

### `ppDepthStencilView` [out, optional]

Type: **[ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview)****

Pointer to a [ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview), which represents a depth-stencil view. Specify **NULL** for this parameter when retrieval of the depth-stencil view is not needed.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)