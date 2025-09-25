# D3D10_RTV_DIMENSION enumeration

## Description

Specifies how to access a resource used in a render-target [view](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-access-views).

## Constants

### `D3D10_RTV_DIMENSION_UNKNOWN:0`

The resource will be accessed according to its type as determined from the actual instance this enumeration is paired with when the render-target view is created.

### `D3D10_RTV_DIMENSION_BUFFER:1`

The resource will be accessed as a [buffer](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

### `D3D10_RTV_DIMENSION_TEXTURE1D:2`

The resource will be accessed as a [1D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

### `D3D10_RTV_DIMENSION_TEXTURE1DARRAY:3`

The resource will be accessed as an array of 1D textures.

### `D3D10_RTV_DIMENSION_TEXTURE2D:4`

The resource will be accessed as a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

### `D3D10_RTV_DIMENSION_TEXTURE2DARRAY:5`

The resource will be accessed as an array of 2D textures.

### `D3D10_RTV_DIMENSION_TEXTURE2DMS:6`

The resource will be accessed as a 2D texture with multisampling.

### `D3D10_RTV_DIMENSION_TEXTURE2DMSARRAY:7`

The resource will be accessed as an array of 2D textures with multisampling.

### `D3D10_RTV_DIMENSION_TEXTURE3D:8`

The resource will be accessed as a [3D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

## Remarks

This enumeration is used in [D3D10_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_render_target_view_desc) to create a render-target view.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-enums)