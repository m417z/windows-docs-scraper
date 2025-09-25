# ID3D11Device::CreateRenderTargetView

## Description

Creates a render-target view for accessing resource data.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Pointer to a [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) that represents a render target. This resource must have been created with the [D3D11_BIND_RENDER_TARGET](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) flag.

### `pDesc` [in, optional]

Type: **const [D3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_view_desc)***

Pointer to a [D3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_view_desc) that represents a render-target view description. Set this parameter to **NULL** to create a view that accesses all of the subresources in mipmap level 0.

### `ppRTView` [out, optional]

Type: **[ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview)****

Address of a pointer to an [ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview). Set this parameter to **NULL** to validate the other input parameters (the method will return S_FALSE if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

A render-target view can be bound to the output-merger stage by calling [ID3D11DeviceContext::OMSetRenderTargets](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetrendertargets).

The Direct3D 11.1 runtime, which is available starting with Windows 8, allows you to use **CreateRenderTargetView** for the following new purpose.

You can create render-target views of video resources so that Direct3D shaders can process those render-target views. These video resources are either [Texture2D](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2d) or [Texture2DArray](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sm5-object-texture2darray). The value in the **ViewDimension** member of the [D3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_view_desc) structure for a created render-target view must match the type of video resource, D3D11_RTV_DIMENSION_TEXTURE2D for Texture2D and D3D11_RTV_DIMENSION_TEXTURE2DARRAY for Texture2DArray. Additionally, the format of the underlying video resource restricts the formats that the view can use. The video resource format values on the [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) reference page specify the format values that views are restricted to.

The runtime read+write conflict prevention logic (which stops a resource from being bound as an SRV and RTV or UAV at the same time) treats views of different parts of the same video surface as conflicting for simplicity. Therefore, the runtime does not allow an application to read from luma while the application simultaneously renders to chroma in the same surface even though the hardware might allow these simultaneous operations.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)