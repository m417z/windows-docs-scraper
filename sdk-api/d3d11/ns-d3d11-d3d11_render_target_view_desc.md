# D3D11_RENDER_TARGET_VIEW_DESC structure

## Description

Specifies the subresources from a resource that are accessible using a render-target view.

## Members

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The data format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

### `ViewDimension`

Type: **[D3D11_RTV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_rtv_dimension)**

The resource type (see [D3D11_RTV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_rtv_dimension)), which specifies how the render-target resource will be accessed.

### `Buffer`

Type: **[D3D11_BUFFER_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_rtv)**

Specifies which buffer elements can be accessed (see [D3D11_BUFFER_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_rtv)).

### `Texture1D`

Type: **[D3D11_TEX1D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_rtv)**

Specifies the subresources in a 1D texture that can be accessed (see [D3D11_TEX1D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_rtv)).

### `Texture1DArray`

Type: **[D3D11_TEX1D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_rtv)**

Specifies the subresources in a 1D texture array that can be accessed (see [D3D11_TEX1D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_rtv)).

### `Texture2D`

Type: **[D3D11_TEX2D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_rtv)**

Specifies the subresources in a 2D texture that can be accessed (see [D3D11_TEX2D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_rtv)).

### `Texture2DArray`

Type: **[D3D11_TEX2D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_array_rtv)**

Specifies the subresources in a 2D texture array that can be accessed (see [D3D11_TEX2D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_array_rtv)).

### `Texture2DMS`

Type: **[D3D11_TEX2DMS_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_rtv)**

Specifies a single subresource because a multisampled 2D texture only contains one subresource (see [D3D11_TEX2DMS_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_rtv)).

### `Texture2DMSArray`

Type: **[D3D11_TEX2DMS_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_array_rtv)**

Specifies the subresources in a multisampled 2D texture array that can be accessed (see [D3D11_TEX2DMS_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_array_rtv)).

### `Texture3D`

Type: **[D3D11_TEX3D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_rtv)**

Specifies subresources in a 3D texture that can be accessed (see [D3D11_TEX3D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_rtv)).

## Remarks

A render-target-view description is passed into [ID3D11Device::CreateRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createrendertargetview) to create a render target.

A render-target-view cannot use the following formats:

* Any typeless format.
* DXGI_FORMAT_R32G32B32 if the view will be used to bind a buffer (vertex, index, constant, or stream-output).

If the format is set to DXGI_FORMAT_UNKNOWN, then the format of the resource that the view binds to the pipeline will be used.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)