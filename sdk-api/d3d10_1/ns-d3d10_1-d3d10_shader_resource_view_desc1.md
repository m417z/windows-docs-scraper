# D3D10_SHADER_RESOURCE_VIEW_DESC1 structure

## Description

Describes a shader-resource view.

## Members

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The viewing [format](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format). See remarks.

### `ViewDimension`

Type: **[D3D10_SRV_DIMENSION1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb694535(v=vs.85))**

The resource type of the view. See [D3D10_SRV_DIMENSION1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb694535(v=vs.85)). This should be the same as the resource type of the underlying resource. This parameter also determines which _SRV to use in the union below.

### `Buffer`

Type: **[D3D10_BUFFER_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_buffer_srv)**

View the resource as a buffer using information from a shader-resource view (see [D3D10_BUFFER_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_buffer_srv)).

### `Texture1D`

Type: **[D3D10_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_srv)**

View the resource as a 1D texture using information from a shader-resource view (see [D3D10_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_srv)).

### `Texture1DArray`

Type: **[D3D10_TEX1D_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_array_srv)**

View the resource as a 1D-texture array using information from a shader-resource view (see [D3D10_TEX1D_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex1d_array_srv).

### `Texture2D`

Type: **[D3D10_TEX2D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_srv)**

View the resource as a 2D-texture using information from a shader-resource view (see [D3D10_TEX2D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_srv).

### `Texture2DArray`

Type: **[D3D10_TEX2D_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_array_srv)**

View the resource as a 2D-texture array using information from a shader-resource view (see [D3D10_TEX2D_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2d_array_srv).

### `Texture2DMS`

Type: **[D3D10_TEX2DMS_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_srv)**

View the resource as a 2D-multisampled texture using information from a shader-resource view (see [D3D10_TEX2DMS_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_srv).

### `Texture2DMSArray`

Type: **[D3D10_TEX2DMS_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_array_srv)**

View the resource as a 2D-multisampled-texture array using information from a shader-resource view (see [D3D10_TEX2DMS_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex2dms_array_srv).

### `Texture3D`

Type: **[D3D10_TEX3D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex3d_srv)**

View the resource as a 3D texture using information from a shader-resource view (see [D3D10_TEX3D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_tex3d_srv).

### `TextureCube`

Type: **[D3D10_TEXCUBE_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_texcube_srv)**

View the resource as a 3D-cube texture using information from a shader-resource view (see [D3D10_TEXCUBE_SRV](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_texcube_srv)).

Type: **[D3D10_TEXCUBE_ARRAY_SRV1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_texcube_array_srv1)**

View the resource as an array of cube textures using information from a shader-resource view (see [D3D10_TEXCUBE_ARRAY_SRV1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_texcube_array_srv1)).

### `TextureCubeArray`

## Remarks

A view is a format-specific way to look at the data in a resource. The view determines what data to look at, and how it is cast when read. For more information about how views work, see [Views](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-access-views)

When viewing a resource, the resource-view description must specify a typed format, that is compatible with the resource format. So that means that you cannot create a resource-view description using any format with _TYPELESS in the name. You can however view a typeless resource by specifying a typed format for the view. For example, a DXGI_FORMAT_R32G32B32_TYPELESS resource can be viewed with one of these typed formats: DXGI_FORMAT_R32G32B32_FLOAT, DXGI_FORMAT_R32G32B32_UINT, and DXGI_FORMAT_R32G32B32_SINT, since these typed formats are compatible with the typeless resource.

Create a shader-resource-view description by calling [ID3D10Device1::CreateShaderResourceView1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nf-d3d10_1-id3d10device1-createshaderresourceview1). To view a shader-resource-view description, call [ID3D10ShaderResourceView::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10shaderresourceview-getdesc).

This structure requires Windows Vista Service Pack 1.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)