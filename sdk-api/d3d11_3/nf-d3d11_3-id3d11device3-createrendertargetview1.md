# ID3D11Device3::CreateRenderTargetView1

## Description

Creates a render-target view for accessing resource data.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Pointer to a [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) that represents a render target. This resource must have been created with the [D3D11_BIND_RENDER_TARGET](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) flag.

### `pDesc1` [in, optional]

Type: **const [D3D11_RENDER_TARGET_VIEW_DESC1](https://learn.microsoft.com/windows/win32/api/d3d11_3/ns-d3d11_3-d3d11_render_target_view_desc1)***

Pointer to a [D3D11_RENDER_TARGET_VIEW_DESC1](https://learn.microsoft.com/windows/win32/api/d3d11_3/ns-d3d11_3-d3d11_render_target_view_desc1) that represents a render-target view description. Set this parameter to **NULL** to create a view that accesses all of the subresources in mipmap level 0.

### `ppRTView1` [out, optional]

Type: **[ID3D11RenderTargetView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11rendertargetview1)****

A pointer to a memory block that receives a pointer to a [ID3D11RenderTargetView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11rendertargetview1) interface for the created render-target view. Set this parameter to **NULL** to validate the other input parameters (the method will return **S_FALSE** if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

A render-target view can be bound to the output-merger stage by calling [ID3D11DeviceContext::OMSetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetrendertargets).

## See also

[ID3D11Device3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11device3)