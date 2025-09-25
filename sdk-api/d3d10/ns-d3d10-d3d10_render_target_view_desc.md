# D3D10_RENDER_TARGET_VIEW_DESC structure

## Description

Specifies the [subresource(s)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) from a resource that are accessible using a render-target view.

## Members

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The data format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

### `ViewDimension`

Type: **[D3D10_RTV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_rtv_dimension)**

The resource type (see [D3D10_RTV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_rtv_dimension)), which specifies how the render-target resource will be accessed.

### `Buffer`

Type: **[D3D10_BUFFER_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_buffer_rtv)**

Specifies which buffer elements can be accessed (see [D3D10_BUFFER_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_buffer_rtv)).

### `Texture1D`

Type: **[D3D10_TEX1D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_rtv)**

Specifies the subresources in a 1D texture that can be accessed (see [D3D10_TEX1D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_rtv)).

### `Texture1DArray`

Type: **[D3D10_TEX1D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_array_rtv)**

Specifies the subresources in a 1D texture array that can be accessed (see [D3D10_TEX1D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_array_rtv)).

### `Texture2D`

Type: **[D3D10_TEX2D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_rtv)**

Specifies the subresources in a 2D texture that can be accessed (see [D3D10_TEX2D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_rtv)).

### `Texture2DArray`

Type: **[D3D10_TEX2D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_array_rtv)**

Specifies the subresources in a 2D texture array that can be accessed (see [D3D10_TEX2D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_array_rtv)).

### `Texture2DMS`

Type: **[D3D10_TEX2DMS_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_rtv)**

Specifies a single subresource because a multisampled 2D texture only contains one subresource (see [D3D10_TEX2DMS_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_rtv)).

### `Texture2DMSArray`

Type: **[D3D10_TEX2DMS_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_array_rtv)**

Specifies the subresources in a multisampled 2D texture array that can be accessed (see [D3D10_TEX2DMS_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_array_rtv)).

### `Texture3D`

Type: **[D3D10_TEX3D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex3d_rtv)**

Specifies subresources in a 3D texture that can be accessed (see [D3D10_TEX3D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex3d_rtv)).

## Remarks

A render-target-view description is passed into [ID3D10Device::CreateRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createrendertargetview) to create a render target.

A render-target-view cannot use the following formats:

* Any [typeless format](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-access-views).
* [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) if the view will be used to bind a buffer (vertex, index, constant, or stream-output).

If the format is set to [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), then the format of the resource that the view binds to the pipeline will be used.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)