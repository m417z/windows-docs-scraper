# D3D12_SRV_DIMENSION enumeration

## Description

Identifies the type of resource that will be viewed as a shader resource.

## Constants

### `D3D12_SRV_DIMENSION_UNKNOWN:0`

The type is unknown.

### `D3D12_SRV_DIMENSION_BUFFER:1`

The resource is a buffer.

### `D3D12_SRV_DIMENSION_TEXTURE1D:2`

The resource is a 1D texture.

### `D3D12_SRV_DIMENSION_TEXTURE1DARRAY:3`

The resource is an array of 1D textures.

### `D3D12_SRV_DIMENSION_TEXTURE2D:4`

The resource is a 2D texture.

### `D3D12_SRV_DIMENSION_TEXTURE2DARRAY:5`

The resource is an array of 2D textures.

### `D3D12_SRV_DIMENSION_TEXTURE2DMS:6`

The resource is a multisampling 2D texture.

### `D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:7`

The resource is an array of multisampling 2D textures.

### `D3D12_SRV_DIMENSION_TEXTURE3D:8`

The resource is a 3D texture.

### `D3D12_SRV_DIMENSION_TEXTURECUBE:9`

The resource is a cube texture.

### `D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:10`

The resource is an array of cube textures.

### `D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:11`

The resource is a raytracing acceleration structure.

## Remarks

These values are used by a shader-resource-view description, [D3D12_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_resource_view_desc).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)