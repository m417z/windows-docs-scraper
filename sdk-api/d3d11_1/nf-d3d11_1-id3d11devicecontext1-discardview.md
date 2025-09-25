# ID3D11DeviceContext1::DiscardView

## Description

Discards a resource view from the device context.

## Parameters

### `pResourceView` [in]

Type: **[ID3D11View](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11view)***

A pointer to the [ID3D11View](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11view) interface for the resource view to discard. The resource that underlies the view must have been created with usage [D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) or [D3D11_USAGE_DYNAMIC](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage), otherwise the runtime drops the call to **DiscardView**; if the debug layer is enabled, the runtime returns an error message.

## Remarks

**DiscardView** informs the graphics processing unit (GPU) that the existing content in the resource view that *pResourceView* points to is no longer needed. The view can be an SRV, RTV, UAV, or DSV. **DiscardView** is a variation on the [DiscardResource](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-discardresource) method. **DiscardView** allows you to discard a subset of a resource that is in a view (such as a single miplevel). More importantly, **DiscardView** provides a convenience because often views are what are being bound and unbound at the pipeline. Some pipeline bindings do not have views, such as stream output. In that situation, **DiscardResource** can do the job for any resource.

## See also

[ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1)