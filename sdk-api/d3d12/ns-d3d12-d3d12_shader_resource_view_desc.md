## Description

Describes a shader-resource view (SRV).

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format. See remarks.

### `ViewDimension`

A [D3D12_SRV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_srv_dimension)-typed value that specifies the resource type of the view. This type is the same as the resource type of the underlying resource. This member also determines which _SRV to use in the union below.

### `Shader4ComponentMapping`

A value, constructed using the [D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_component_mapping) macro. The **D3D12_SHADER_COMPONENT_MAPPING** enumeration specifies what values from memory should be returned when the texture is accessed in a shader via this shader resource view (SRV). For example, it can route component 1 (green) from memory, or the constant `0`, into component 2 (`.b`) of the value given to the shader.

### `Buffer`

A [D3D12_BUFFER_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_buffer_srv) structure that views the resource as a buffer.

### `Texture1D`

A [D3D12_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_srv) structure that views the resource as a 1D texture.

### `Texture1DArray`

A [D3D12_TEX1D_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex1d_array_srv) structure that views the resource as a 1D-texture array.

### `Texture2D`

A [D3D12_TEX2D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2d_srv) structure that views the resource as a 2D-texture.

### `Texture2DArray`

A [D3D12_TEX2D_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2d_array_srv) structure that views the resource as a 2D-texture array.

### `Texture2DMS`

A [D3D12_TEX2DMS_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2dms_srv) structure that views the resource as a 2D-multisampled texture.

### `Texture2DMSArray`

A [D3D12_TEX2DMS_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex2dms_array_srv) structure that views the resource as a 2D-multisampled-texture array.

### `Texture3D`

A [D3D12_TEX3D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tex3d_srv) structure that views the resource as a 3D texture.

### `TextureCube`

A [D3D12_TEXCUBE_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texcube_srv) structure that views the resource as a 3D-cube texture.

### `TextureCubeArray`

A [D3D12_TEXCUBE_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texcube_array_srv) structure that views the resource as a 3D-cube-texture array.

### `RaytracingAccelerationStructure`

A [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_srv) structure that views the resource as a raytracing acceleration structure.

## Remarks

A view is a format-specific way to look at the data in a resource. The view determines what data to look at, and how it is cast when read.

When viewing a resource, the resource-view description must specify a typed format, that is compatible with the resource format. So that means that you can't create a resource-view description using any format with _TYPELESS in the name. You can however view a typeless resource by specifying a typed format for the view. For example, a DXGI_FORMAT_R32G32B32_TYPELESS resource can be viewed with one of these typed formats: DXGI_FORMAT_R32G32B32_FLOAT, DXGI_FORMAT_R32G32B32_UINT, and DXGI_FORMAT_R32G32B32_SINT, since these typed formats are compatible with the typeless resource.

Create a shader-resource-view description by calling [ID3D12Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createshaderresourceview).

## See also

[Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)