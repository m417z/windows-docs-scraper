# D3D12DDI_SHADING_RATE_0062 enumeration

## Description

The shading rate at which the variable rate shading occurs.

## Constants

### `D3D12DDI_SHADING_RATE_0062_1X1`

No change to the shading rate.

### `D3D12DDI_SHADING_RATE_0062_1X2`

Reduces vertical resolution 2x.

### `D3D12DDI_SHADING_RATE_0062_2X1`

Reduces horizontal resolution 2x.

### `D3D12DDI_SHADING_RATE_0062_2X2`

Reduces both axes by 2x.

### `D3D12DDI_SHADING_RATE_0062_2X4`

Reduce horizontal res 2x, vertical by 4x.

### `D3D12DDI_SHADING_RATE_0062_4X2`

Reduce horizontal res 4x, vertical by 2x.

### `D3D12DDI_SHADING_RATE_0062_4X4`

Reduces both axes by 4x.

## Remarks

The values are organized so that shading rates are easily decomposable into two axes, where each axis’s values are compactly represented in logarithmic space.

## See also