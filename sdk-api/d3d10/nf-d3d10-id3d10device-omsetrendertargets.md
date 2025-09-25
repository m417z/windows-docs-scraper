# ID3D10Device::OMSetRenderTargets

## Description

Bind one or more render targets and the depth-stencil buffer to the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

## Parameters

### `NumViews` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of render targets to bind.

### `ppRenderTargetViews` [in]

Type: **[ID3D10RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rendertargetview)***

Pointer to an array of render targets (see [ID3D10RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rendertargetview)) to bind to the device. If this parameter is **NULL**, no render targets are bound. See Remarks.

### `pDepthStencilView` [in]

Type: **[ID3D10DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilview)***

Pointer to a depth-stencil view (see [ID3D10DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilview)) to bind to the device. If this parameter is **NULL**, the depth-stencil state is not bound.

## Remarks

A call to **OMSetRenderTargets** overrides all bounded render targets and the depth stencil target regardless of the number of render targets in *ppRenderTargetViews*.

The maximum number of render targets a device can have active at any given time is set by a #define in D3D10.h called D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT. It is invalid to try to set the same [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to multiple render target slots.

If any subresources are also currently bound for reading or writing (perhaps in a different part of the [pipeline](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-pipeline-stages)), those bind points will be **NULL**'ed out to prevent the same subresource from being read and written simultaneously in a single rendering operation.

The method will not hold references to the interfaces passed in. For that reason, applications should be careful not to release interfaces currently in use by the device.

See [Binding Resources and Pipeline stages](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) for more information on binding resources.

The pixel shader must be able to simultaneously render to at least eight separate render targets. All of these render targets must access the same type of resource: [Buffer](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-buffer), [Texture1D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture1d), [Texture1DArray](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture1darray), [Texture2D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2d), [Texture2DArray](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2darray), [Texture3D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture3d), or [TextureCube](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-type). All render targets must have the same size in all dimensions (width and height, and depth for 3D or array size for *Array types). If render targets use multisample anti-aliasing, all bound render targets and depth buffer must be the same form of multisample resource (that is, the sample counts must be the same). Each render target can have a different data format. These render target formats are not required to have identical bit-per-element counts.

Any combination of the eight slots for render targets can have a render target set or not set.

The same resource view cannot be bound to multiple render target slots simultaneously. However, you can set multiple non-overlapping resource views of a single resource as simultaneous multiple render targets.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)