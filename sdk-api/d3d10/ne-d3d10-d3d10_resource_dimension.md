# D3D10_RESOURCE_DIMENSION enumeration

## Description

Identifies the type of [resource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) being used.

## Constants

### `D3D10_RESOURCE_DIMENSION_UNKNOWN:0`

Resource is of unknown type.

### `D3D10_RESOURCE_DIMENSION_BUFFER:1`

Resource is a [buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

### `D3D10_RESOURCE_DIMENSION_TEXTURE1D:2`

Resource is a [1D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

### `D3D10_RESOURCE_DIMENSION_TEXTURE2D:3`

Resource is a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

### `D3D10_RESOURCE_DIMENSION_TEXTURE3D:4`

Resource is a [3D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

## Remarks

This enumeration is used in [ID3D10Resource::GetType](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10resource-gettype), and [D3DX10_IMAGE_INFO](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10-image-info).

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-enums)