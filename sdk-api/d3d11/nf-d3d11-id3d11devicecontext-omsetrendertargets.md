## Description

Bind one or more render targets atomically and the depth-stencil buffer to the [output-merger stage](https://learn.microsoft.com/windows/win32/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

## Parameters

### `NumViews` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

Number of render targets to bind (ranges between 0 and **D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT**). If this parameter is nonzero, the number of entries in the array to which *ppRenderTargetViews* points must equal the number in this parameter.

### `ppRenderTargetViews` [in, optional]

Type: **[ID3D11RenderTargetView](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11rendertargetview)***

Pointer to an array of [ID3D11RenderTargetView](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11rendertargetview) that represent the render targets to bind to the device.
If this parameter is **NULL** and *NumViews* is 0, no render targets are bound.

### `pDepthStencilView` [in, optional]

Type: **[ID3D11DepthStencilView](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11depthstencilview)***

Pointer to a [ID3D11DepthStencilView](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11depthstencilview) that represents the depth-stencil view to bind to the device.
If this parameter is **NULL**, the depth-stencil view is not bound.

## Remarks

The maximum number of active render targets a device can have active at any given time is set by a #define in D3D11.h called
**D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT**. It is invalid to try to set the same subresource to multiple render target slots.
Any render targets not defined by this call are set to **NULL**.

If any subresources are also currently bound for reading in a different stage or writing (perhaps in a different part of the pipeline),
those bind points will be set to **NULL**, in order to prevent the same subresource from being read and written simultaneously in a single rendering operation.

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

If the render-target views were created from an array resource type, all of the render-target views must have the same array size.
This restriction also applies to the depth-stencil view, its array size must match that of the render-target views being bound.

The pixel shader must be able to simultaneously render to at least eight separate render targets. All of these render targets must access the same type of resource: [Buffer](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-buffer), [Texture1D](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-texture1d), [Texture1DArray](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-texture1darray), [Texture2D](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-texture2d), [Texture2DArray](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-texture2darray), [Texture3D](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-texture3d), or [TextureCube](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-to-type). All render targets must have the same size in all dimensions (width and height, and depth for 3D or array size for *Array types). If render targets use multisample anti-aliasing, all bound render targets and depth buffer must be the same form of multisample resource (that is, the sample counts must be the same). Each render target can have a different data format. These render target formats are not required to have identical bit-per-element counts.

Any combination of the eight slots for render targets can have a render target set or not set.

The same resource view cannot be bound to multiple render target slots simultaneously. However, you can set multiple non-overlapping resource views of a single resource as simultaneous multiple render targets.

Note that unlike some other resource methods in Direct3D, all currently bound render targets will be unbound by calling `OMSetRenderTargets(0, nullptr, nullptr);`.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11devicecontext)