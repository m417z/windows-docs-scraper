# D3D11_STENCIL_OP enumeration

## Description

The stencil operations that can be performed during depth-stencil testing.

## Constants

### `D3D11_STENCIL_OP_KEEP:1`

Keep the existing stencil data.

### `D3D11_STENCIL_OP_ZERO:2`

Set the stencil data to 0.

### `D3D11_STENCIL_OP_REPLACE:3`

Set the stencil data to the reference value set by calling [ID3D11DeviceContext::OMSetDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetdepthstencilstate).

### `D3D11_STENCIL_OP_INCR_SAT:4`

Increment the stencil value by 1, and clamp the result.

### `D3D11_STENCIL_OP_DECR_SAT:5`

Decrement the stencil value by 1, and clamp the result.

### `D3D11_STENCIL_OP_INVERT:6`

Invert the stencil data.

### `D3D11_STENCIL_OP_INCR:7`

Increment the stencil value by 1, and wrap the result if necessary.

### `D3D11_STENCIL_OP_DECR:8`

Decrement the stencil value by 1, and wrap the result if necessary.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)