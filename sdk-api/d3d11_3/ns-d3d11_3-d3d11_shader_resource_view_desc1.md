## Description

Describes a shader-resource view.

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format. See remarks.

### `ViewDimension`

A [D3D11_SRV_DIMENSION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff476217(v=vs.85))-typed value that specifies the resource type of the view. This type is the same as the resource type of the underlying resource. This member also determines which _SRV to use in the union below.

### `Buffer`

A [D3D11_BUFFER_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_srv) structure that views the resource as a buffer.

### `Texture1D`

A [D3D11_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_srv) structure that views the resource as a 1D texture.

### `Texture1DArray`

A [D3D11_TEX1D_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_array_srv) structure that views the resource as a 1D-texture array.

### `Texture2D`

A [D3D11_TEX2D_SRV1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-d3d11_tex2d_srv1) structure that views the resource as a 2D-texture.

### `Texture2DArray`

A [D3D11_TEX2D_ARRAY_SRV1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-d3d11_tex2d_array_srv1) structure that views the resource as a 2D-texture array.

### `Texture2DMS`

A [D3D11_TEX2DMS_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_srv) structure that views the resource as a 2D-multisampled texture.

### `Texture2DMSArray`

A [D3D11_TEX2DMS_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2dms_array_srv) structure that views the resource as a 2D-multisampled-texture array.

### `Texture3D`

A [D3D11_TEX3D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_srv) structure that views the resource as a 3D texture.

### `TextureCube`

A [D3D11_TEXCUBE_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texcube_srv) structure that views the resource as a 3D-cube texture.

### `TextureCubeArray`

A [D3D11_TEXCUBE_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texcube_array_srv) structure that views the resource as a 3D-cube-texture array.

### `BufferEx`

A [D3D11_BUFFEREX_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_bufferex_srv) structure that views the resource as a raw buffer. For more info about raw viewing of buffers, see [Raw Views of Buffers](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

## Remarks

A view is a format-specific way to look at the data in a resource. The view determines what data to look at, and how it is cast when read.

When viewing a resource, the resource-view description must specify a typed format, that is compatible with the resource format. So that means that you cannot create a resource-view description using any format with _TYPELESS in the name. You can however view a typeless resource by specifying a typed format for the view. For example, a DXGI_FORMAT_R32G32B32_TYPELESS resource can be viewed with one of these typed formats: DXGI_FORMAT_R32G32B32_FLOAT, DXGI_FORMAT_R32G32B32_UINT, and DXGI_FORMAT_R32G32B32_SINT, since these typed formats are compatible with the typeless resource.

Create a shader-resource-view description by calling [ID3D11Device3::CreateShaderResourceView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-createshaderresourceview1). To view a shader-resource-view description, call [ID3D11ShaderResourceView1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11shaderresourceview1-getdesc1).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)