# D3D11_CULL_MODE enumeration

## Description

Indicates triangles facing a particular direction are not drawn.

## Constants

### `D3D11_CULL_NONE:1`

Always draw all triangles.

### `D3D11_CULL_FRONT:2`

Do not draw triangles that are front-facing.

### `D3D11_CULL_BACK:3`

Do not draw triangles that are back-facing.

## Remarks

This enumeration is part of a rasterizer-state object description (see [D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc)).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)