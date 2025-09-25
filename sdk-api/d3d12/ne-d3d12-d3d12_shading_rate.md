## Description

Defines constants that specify the shading rate (for variable-rate shading, or VRS). For more info, see [Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs).

## Constants

### `D3D12_SHADING_RATE_1X1:0`

Specifies no change to the shading rate.

### `D3D12_SHADING_RATE_1X2:0x1`

Specifies that the shading rate should reduce vertical resolution 2x.

### `D3D12_SHADING_RATE_2X1:0x4`

Specifies that the shading rate should reduce horizontal resolution 2x.

### `D3D12_SHADING_RATE_2X2:0x5`

Specifies that the shading rate should reduce the resolution of both axes 2x.

### `D3D12_SHADING_RATE_2X4:0x6`

Specifies that the shading rate should reduce horizontal resolution 2x, and reduce vertical resolution 4x.

### `D3D12_SHADING_RATE_4X2:0x9`

Specifies that the shading rate should reduce horizontal resolution 4x, and reduce vertical resolution 2x.

### `D3D12_SHADING_RATE_4X4:0xa`

Specifies that the shading rate should reduce the resolution of both axes 4x.

## Remarks

## See also

[Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs)