# D3D_INTERPOLATION_MODE enumeration

## Description

Specifies interpolation mode, which affects how values are calculated during rasterization.

## Constants

### `D3D_INTERPOLATION_UNDEFINED:0`

The interpolation mode is undefined.

### `D3D_INTERPOLATION_CONSTANT:1`

Don't interpolate between register values.

### `D3D_INTERPOLATION_LINEAR:2`

Interpolate linearly between register values.

### `D3D_INTERPOLATION_LINEAR_CENTROID:3`

Interpolate linearly between register values but centroid clamped when multisampling.

### `D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE:4`

Interpolate linearly between register values but with no perspective correction.

### `D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE_CENTROID:5`

Interpolate linearly between register values but with no perspective correction and centroid clamped when multisampling.

### `D3D_INTERPOLATION_LINEAR_SAMPLE:6`

Interpolate linearly between register values but sample clamped when multisampling.

### `D3D_INTERPOLATION_LINEAR_NOPERSPECTIVE_SAMPLE:7`

Interpolate linearly between register values but with no perspective correction and sample clamped when multisampling.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)

[D3D11_PARAMETER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_parameter_desc)