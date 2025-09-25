# CD3D11_RENDER_TARGET_VIEW_DESC1 structure

## Description

Describes the subresources from a resource that are accessible using a render-target view.

## Members

### `CD3D11_RENDER_TARGET_VIEW_DESC1`

TBD

### `~CD3D11_RENDER_TARGET_VIEW_DESC1`

TBD

### `operator` const D3D11_RENDER_TARGET_VIEW_DESC1&

TBD

### `D3D11_RENDER_TARGET_VIEW_DESC1`

#### - Buffer

A [D3D11_BUFFER_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_rtv) structure that specifies which buffer elements can be accessed.

#### - Format

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the data format.

#### - Texture1D

A [D3D11_TEX1D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_rtv) structure that specifies the subresources in a 1D texture that can be accessed.

#### - Texture1DArray

A [D3D11_TEX1D_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_rtv) structure that specifies the subresources in a 1D texture array that can be accessed.

#### - Texture2D

A [D3D11_TEX2D_RTV1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-d3d11_tex2d_rtv1) structure that specifies the subresources in a 2D texture that can be accessed.

#### - Texture2DArray

A [D3D11_TEX2D_ARRAY_RTV1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-d3d11_tex2d_array_rtv1) structure that specifies the subresources in a 2D texture array that can be accessed.

#### - Texture2DMS

A [D3D11_TEX2DMS_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_rtv) structure that specifies a single subresource because a multisampled 2D texture only contains one subresource.

#### - Texture2DMSArray

A [D3D11_TEX2DMS_ARRAY_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_array_rtv) structure that specifies the subresources in a multisampled 2D texture array that can be accessed.

#### - Texture3D

A [D3D11_TEX3D_RTV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_rtv) structure that specifies subresources in a 3D texture that can be accessed.

#### - ViewDimension

A [D3D11_RTV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_rtv_dimension)-typed value that specifies the resource type and how the render-target resource will be accessed.

## Remarks

A render-target-view description is passed into [ID3D11Device3::CreateRenderTargetView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-createrendertargetview1) to create a render target.

A render-target-view can't use the following formats:

* Any typeless format.
* DXGI_FORMAT_R32G32B32 if the view will be used to bind a buffer (vertex, index, constant, or stream-output).

If the format is set to DXGI_FORMAT_UNKNOWN, then the format of the resource that the view binds to the pipeline will be used.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)