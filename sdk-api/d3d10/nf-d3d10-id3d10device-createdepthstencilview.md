# ID3D10Device::CreateDepthStencilView

## Description

Create a depth-stencil [view](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-access-views) for accessing resource data.

## Parameters

### `pResource` [in]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)***

Pointer to the [resource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) that will serve as the depth-stencil surface. This resource must have been created with the [D3D10_BIND_DEPTH_STENCIL](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag) flag.

### `pDesc` [in]

Type: **const [D3D10_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_view_desc)***

Pointer to a depth-stencil-view description (see [D3D10_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_view_desc)). Set this parameter to **NULL** to create a view that accesses mipmap level 0 of the entire resource (using the format the resource was created with).

### `ppDepthStencilView` [out]

Type: **[ID3D10DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilview)****

Address of a pointer to an [ID3D10DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilview). Set this parameter to **NULL** to validate the other input parameters (the method will return S_FALSE if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

A depth-stencil view can be bound to the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) by calling [ID3D10Device::OMSetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omsetrendertargets).

For more background information, see the [programming guide page](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-depth-stencil) about depth stencils.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)