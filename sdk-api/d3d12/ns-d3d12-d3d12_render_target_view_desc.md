# D3D12_RENDER_TARGET_VIEW_DESC structure

## Description

Describes the subresources from a resource that are accessible by using a render-target view.

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format.

### `ViewDimension`

A [D3D12_RTV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_rtv_dimension)-typed value that specifies how the render-target resource will be accessed. This type specifies how the resource will be accessed. This member also determines which _RTV to use in the following union.

### `Buffer`

A [D3D12_BUFFER_RTV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_buffer_rtv) structure that specifies which buffer elements can be accessed.

### `Texture1D`

A [D3D12_TEX1D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_rtv) structure that specifies the subresources in a 1D texture that can be accessed.

### `Texture1DArray`

A [D3D12_TEX1D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_array_rtv) structure that specifies the subresources in a 1D texture array that can be accessed.

### `Texture2D`

A [D3D12_TEX2D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2d_rtv) structure that specifies the subresources in a 2D texture that can be accessed.

### `Texture2DArray`

A [D3D12_TEX2D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2d_array_rtv) structure that specifies the subresources in a 2D texture array that can be accessed.

### `Texture2DMS`

A [D3D12_TEX2DMS_RTV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2dms_rtv) structure that specifies a single subresource because a multisampled 2D texture only contains one subresource.

### `Texture2DMSArray`

A [D3D12_TEX2DMS_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2dms_array_rtv) structure that specifies the subresources in a multisampled 2D texture array that can be accessed.

### `Texture3D`

A [D3D12_TEX3D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex3d_rtv) structure that specifies subresources in a 3D texture that can be accessed.

## Remarks

Pass a render-target-view description into [ID3D12Device::CreateRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createrendertargetview) to create a render-target view.

A render-target view can't use the following formats:

* Any typeless format.
* DXGI_FORMAT_R32G32B32 if the view will be used to bind a buffer (vertex, index, constant, or stream-output).

If the format is set to DXGI_FORMAT_UNKNOWN, then the format of the resource that the view binds to the pipeline will be used.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)