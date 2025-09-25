# D3D10_DSV_DIMENSION enumeration

## Description

Specifies how to access a resource used in a depth-stencil [view](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-access-views).

## Constants

### `D3D10_DSV_DIMENSION_UNKNOWN:0`

The resource will be accessed according to its type as determined from the actual instance this enumeration is paired with when the depth-stencil view is created.

### `D3D10_DSV_DIMENSION_TEXTURE1D:1`

The resource will be accessed as a [1D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

### `D3D10_DSV_DIMENSION_TEXTURE1DARRAY:2`

The resource will be accessed as an array of 1D textures.

### `D3D10_DSV_DIMENSION_TEXTURE2D:3`

The resource will be accessed as a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

### `D3D10_DSV_DIMENSION_TEXTURE2DARRAY:4`

The resource will be accessed as an array of 2D texture.

### `D3D10_DSV_DIMENSION_TEXTURE2DMS:5`

The resource will be accessed as a 2D texture with multisampling.

### `D3D10_DSV_DIMENSION_TEXTURE2DMSARRAY:6`

The resource will be accessed as an array of 2D textures with multisampling.

## Remarks

This enumeration is used in [D3D10_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencil_view_desc) to create a depth-stencil view.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-enums)