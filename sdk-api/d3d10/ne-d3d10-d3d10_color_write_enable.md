# D3D10_COLOR_WRITE_ENABLE enumeration

## Description

Identify which components of each pixel of a render target are writable during [blending](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

## Constants

### `D3D10_COLOR_WRITE_ENABLE_RED:1`

Allow data to be stored in the red component.

### `D3D10_COLOR_WRITE_ENABLE_GREEN:2`

Allow data to be stored in the green component.

### `D3D10_COLOR_WRITE_ENABLE_BLUE:4`

Allow data to be stored in the blue component.

### `D3D10_COLOR_WRITE_ENABLE_ALPHA:8`

Allow data to be stored in the alpha component.

### `D3D10_COLOR_WRITE_ENABLE_ALL`

Allow data to be stored in all components.

## Remarks

These flags can be combined with a bitwise OR.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)