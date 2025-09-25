# D3D10_STENCIL_OP enumeration

## Description

The stencil operations that can be performed during [depth-stencil](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) testing.

## Constants

### `D3D10_STENCIL_OP_KEEP:1`

Keep the existing stencil data.

### `D3D10_STENCIL_OP_ZERO:2`

Set the stencil data to 0.

### `D3D10_STENCIL_OP_REPLACE:3`

Set the stencil data to the reference value set by calling [ID3D10Device::OMSetDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omsetdepthstencilstate).

### `D3D10_STENCIL_OP_INCR_SAT:4`

Increment the stencil value by 1, and clamp the result.

### `D3D10_STENCIL_OP_DECR_SAT:5`

Decrement the stencil value by 1, and clamp the result.

### `D3D10_STENCIL_OP_INVERT:6`

Invert the stencil data.

### `D3D10_STENCIL_OP_INCR:7`

Increment the stencil value by 1, and wrap the result if necessary.

### `D3D10_STENCIL_OP_DECR:8`

Increment the stencil value by 1, and wrap the result if necessary.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)