# ID3D11Device::CreateDepthStencilView

## Description

Create a depth-stencil view for accessing resource data.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Pointer to the resource that will serve as the depth-stencil surface. This resource must have been created with the [D3D11_BIND_DEPTH_STENCIL](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) flag.

### `pDesc` [in, optional]

Type: **const [D3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_view_desc)***

Pointer to a depth-stencil-view description (see [D3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_view_desc)). Set this parameter to **NULL** to create a view that accesses mipmap level 0 of the entire resource (using the format the resource was created with).

### `ppDepthStencilView` [out, optional]

Type: **[ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview)****

Address of a pointer to an [ID3D11DepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilview). Set this parameter to **NULL** to validate the other input parameters (the method will return S_FALSE if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

A depth-stencil view can be bound to the output-merger stage by calling [ID3D11DeviceContext::OMSetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetrendertargets).

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)