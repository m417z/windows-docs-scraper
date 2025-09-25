# D3D10_CULL_MODE enumeration

## Description

Indicates triangles facing a particular direction are not drawn.

## Constants

### `D3D10_CULL_NONE:1`

Always draw all triangles.

### `D3D10_CULL_FRONT:2`

Do not draw triangles that are front-facing.

### `D3D10_CULL_BACK:3`

Do not draw triangles that are back-facing.

## Remarks

This enumeration is part of a rasterizer-state object description (see [D3D10_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_rasterizer_desc)).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)