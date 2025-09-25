# D3D11_RESOURCE_DIMENSION enumeration

## Description

Identifies the type of resource being used.

## Constants

### `D3D11_RESOURCE_DIMENSION_UNKNOWN:0`

Resource is of unknown type.

### `D3D11_RESOURCE_DIMENSION_BUFFER:1`

Resource is a buffer.

### `D3D11_RESOURCE_DIMENSION_TEXTURE1D:2`

Resource is a 1D texture.

### `D3D11_RESOURCE_DIMENSION_TEXTURE2D:3`

Resource is a 2D texture.

### `D3D11_RESOURCE_DIMENSION_TEXTURE3D:4`

Resource is a 3D texture.

## Remarks

This enumeration is used in [ID3D11Resource::GetType](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11resource-gettype).

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)