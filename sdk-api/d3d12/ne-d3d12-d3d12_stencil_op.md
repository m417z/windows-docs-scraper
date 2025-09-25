# D3D12_STENCIL_OP enumeration

## Description

Identifies the stencil operations that can be performed during depth-stencil testing.

## Constants

### `D3D12_STENCIL_OP_KEEP:1`

Keep the existing stencil data.

### `D3D12_STENCIL_OP_ZERO:2`

Set the stencil data to 0.

### `D3D12_STENCIL_OP_REPLACE:3`

Set the stencil data to the reference value set by calling [ID3D12GraphicsCommandList::OMSetStencilRef](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-omsetstencilref).

### `D3D12_STENCIL_OP_INCR_SAT:4`

Increment the stencil value by 1, and clamp the result.

### `D3D12_STENCIL_OP_DECR_SAT:5`

Decrement the stencil value by 1, and clamp the result.

### `D3D12_STENCIL_OP_INVERT:6`

Invert the stencil data.

### `D3D12_STENCIL_OP_INCR:7`

Increment the stencil value by 1, and wrap the result if necessary.

### `D3D12_STENCIL_OP_DECR:8`

Decrement the stencil value by 1, and wrap the result if necessary.

## Remarks

This enum is used by the [D3D12_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencilop_desc) structure.

## See also

[CD3DX12_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-depth-stencil-desc)

[Core enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)