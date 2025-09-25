# ID3D11DeviceContext::OMSetRenderTargetsAndUnorderedAccessViews

## Description

Binds resources to the output-merger stage.

## Parameters

### `NumRTVs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of render targets to bind (ranges between 0 and **D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT**). If this parameter is nonzero, the number of entries in the array to which *ppRenderTargetViews* points must equal the number in this parameter. If you set *NumRTVs* to D3D11_KEEP_RENDER_TARGETS_AND_DEPTH_STENCIL (0xffffffff), this method does not modify the currently bound render-target views (RTVs) and also does not modify depth-stencil view (DSV).

### `ppRenderTargetViews` [in, optional]

Type: **[ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview)***

Pointer to an array of [ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview)s that represent the render targets to bind to the device.
If this parameter is **NULL** and *NumRTVs* is 0, no render targets are bound.

### `pDepthStencilView` [in, optional]

Type: **[ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview)***

Pointer to a [ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview) that represents the depth-stencil view to bind to the device.
If this parameter is **NULL**, the depth-stencil view is not bound.

### `UAVStartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into a zero-based array to begin setting unordered-access views (ranges from 0 to D3D11_PS_CS_UAV_REGISTER_COUNT - 1).

For the Direct3D 11.1 runtime, which is available starting with Windows 8, this value can range from 0 to D3D11_1_UAV_SLOT_COUNT - 1. D3D11_1_UAV_SLOT_COUNT is defined as 64.

For pixel shaders, *UAVStartSlot* should be equal to the number of render-target views being bound.

### `NumUAVs` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of unordered-access views (UAVs) in *ppUnorderedAccessViews*. If you set *NumUAVs* to D3D11_KEEP_UNORDERED_ACCESS_VIEWS (0xffffffff), this method does not modify the currently bound unordered-access views.

For the Direct3D 11.1 runtime, which is available starting with Windows 8, this value can range from 0 to D3D11_1_UAV_SLOT_COUNT - *UAVStartSlot*.

### `ppUnorderedAccessViews` [in, optional]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

Pointer to an array of [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)s that represent the unordered-access views to bind to the device.
If this parameter is **NULL** and *NumUAVs* is 0, no unordered-access views are bound.

### `pUAVInitialCounts` [in, optional]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

An array of append and consume buffer offsets. A value of -1 indicates to keep the current offset. Any other values set the hidden counter
for that appendable and consumable UAV. *pUAVInitialCounts* is relevant only for UAVs that were created with either
[D3D11_BUFFER_UAV_FLAG_APPEND](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_buffer_uav_flag) or **D3D11_BUFFER_UAV_FLAG_COUNTER** specified
when the UAV was created; otherwise, the argument is ignored.

## Remarks

For pixel shaders, the render targets and unordered-access views share the same resource slots when being written out. This means that UAVs must be
given an offset so that they are placed in the slots after the render target views that are being bound.

**Note** RTVs, DSV, and UAVs cannot be set independently; they all need to be set at the same time.

Two RTVs conflict if they share a subresource (and therefore share the same resource).

Two UAVs conflict if they share a subresource (and therefore share the same resource).

An RTV conflicts with a UAV if they share a subresource or share a bind point.

**OMSetRenderTargetsAndUnorderedAccessViews** operates properly in the following situations:

1. *NumRTVs* != D3D11_KEEP_RENDER_TARGETS_AND_DEPTH_STENCIL and *NumUAVs* != D3D11_KEEP_UNORDERED_ACCESS_VIEWS

   The following conditions must be true for **OMSetRenderTargetsAndUnorderedAccessViews** to succeed and for the runtime to pass the bind information to the driver:

   * *NumRTVs* <= 8
   * *UAVStartSlot* >= *NumRTVs*
   * *UAVStartSlot* + *NumUAVs* <= 8
   * There must be no conflicts in the set of all *ppRenderTargetViews* and *ppUnorderedAccessViews*.
   * *ppDepthStencilView* must match the render-target views. For more information about resource views, see [Introduction to a Resource in Direct3D 11](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).**OMSetRenderTargetsAndUnorderedAccessViews** performs the following tasks:

   * Unbinds all currently bound conflicting resources (stream-output target resources (SOTargets), compute shader (CS) UAVs, shader-resource views (SRVs)).
   * Binds *ppRenderTargetViews*, *ppDepthStencilView*, and *ppUnorderedAccessViews*.
2. *NumRTVs* == D3D11_KEEP_RENDER_TARGETS_AND_DEPTH_STENCIL

   In this situation, **OMSetRenderTargetsAndUnorderedAccessViews** binds only UAVs.

   The following conditions must be true for **OMSetRenderTargetsAndUnorderedAccessViews** to succeed and for the runtime to pass the bind information to the driver:

   * *UAVStartSlot* + *NumUAVs* <= 8
   * There must be no conflicts in *ppUnorderedAccessViews*.**OMSetRenderTargetsAndUnorderedAccessViews** unbinds the following items:

   * All RTVs in slots >= *UAVStartSlot*
   * All RTVs that conflict with any UAVs in *ppUnorderedAccessViews*
   * All currently bound resources (SOTargets, CS UAVs, SRVs) that conflict with *ppUnorderedAccessViews***OMSetRenderTargetsAndUnorderedAccessViews** binds *ppUnorderedAccessViews*.

   **OMSetRenderTargetsAndUnorderedAccessViews** ignores *ppDepthStencilView*, and the current depth-stencil view remains bound.
3. *NumUAVs* == D3D11_KEEP_UNORDERED_ACCESS_VIEWS

   In this situation, **OMSetRenderTargetsAndUnorderedAccessViews** binds only RTVs and DSV.

   The following conditions must be true for **OMSetRenderTargetsAndUnorderedAccessViews** to succeed and for the runtime to pass the bind information to the driver:

   * *NumRTVs* <= 8
   * There must be no conflicts in *ppRenderTargetViews*.
   * *ppDepthStencilView* must match the render-target views. For more information about resource views, see [Introduction to a Resource in Direct3D 11](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).**OMSetRenderTargetsAndUnorderedAccessViews** unbinds the following items:

   * All UAVs in slots < *NumRTVs*
   * All UAVs that conflict with any RTVs in *ppRenderTargetViews*
   * All currently bound resources (SOTargets, CS UAVs, SRVs) that conflict with *ppRenderTargetViews***OMSetRenderTargetsAndUnorderedAccessViews** binds *ppRenderTargetViews* and *ppDepthStencilView*.

   **OMSetRenderTargetsAndUnorderedAccessViews** ignores *UAVStartSlot*.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)