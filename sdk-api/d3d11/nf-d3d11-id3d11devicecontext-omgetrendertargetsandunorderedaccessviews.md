# ID3D11DeviceContext::OMGetRenderTargetsAndUnorderedAccessViews

## Description

Get pointers to the resources bound to the output-merger stage.

## Parameters

### `NumRTVs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of render-target views to retrieve.

### `ppRenderTargetViews` [out, optional]

Type: **[ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview)****

Pointer to an array of [ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview)s, which represent render-target views. Specify **NULL** for this parameter when retrieval of render-target views is not required.

### `ppDepthStencilView` [out, optional]

Type: **[ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview)****

Pointer to a [ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview), which represents a depth-stencil view. Specify **NULL** for this parameter when retrieval of the depth-stencil view is not required.

### `UAVStartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into a zero-based array to begin retrieving unordered-access views (ranges from 0 to D3D11_PS_CS_UAV_REGISTER_COUNT - 1).
For pixel shaders *UAVStartSlot* should be equal to the number of render-target views that are bound.

### `NumUAVs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of unordered-access views to return in *ppUnorderedAccessViews*. This number ranges from 0 to D3D11_PS_CS_UAV_REGISTER_COUNT - *UAVStartSlot*.

### `ppUnorderedAccessViews` [out, optional]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)****

Pointer to an array of [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)s, which represent unordered-access views that are retrieved. Specify **NULL** for this parameter when retrieval of unordered-access views is not required.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)