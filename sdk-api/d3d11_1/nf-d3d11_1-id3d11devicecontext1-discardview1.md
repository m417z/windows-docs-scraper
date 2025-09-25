# ID3D11DeviceContext1::DiscardView1

## Description

Discards the specified elements in a resource view from the device context.

## Parameters

### `pResourceView` [in]

Type: **[ID3D11View](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11view)***

A pointer to the [ID3D11View](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11view) interface for the resource view to discard. The resource that underlies the view must have been created with usage [D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) or [D3D11_USAGE_DYNAMIC](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage), otherwise the runtime drops the call to **DiscardView1**; if the debug layer is enabled, the runtime returns an error message.

### `pRects` [in, optional]

Type: **const [D3D11_RECT](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-rect)***

An array of [D3D11_RECT](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-rect) structures for the rectangles in the resource view to discard. If **NULL**, **DiscardView1** discards the entire view and behaves the same as [DiscardView](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-discardview).

### `NumRects`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of rectangles in the array that the *pRects* parameter specifies.

## Remarks

**DiscardView1** informs the graphics processing unit (GPU) that the existing content in the specified elements in the resource view that *pResourceView* points to is no longer needed. The view can be an SRV, RTV, UAV, or DSV. **DiscardView1** is a variation on the [DiscardResource](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-discardresource) method. **DiscardView1** allows you to discard elements of a subset of a resource that is in a view (such as elements of a single miplevel). More importantly, **DiscardView1** provides a convenience because often views are what are being bound and unbound at the pipeline. Some pipeline bindings do not have views, such as stream output. In that situation, **DiscardResource** can do the job for any resource.

## See also

[ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1)