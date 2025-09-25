# D3D12_CULL_MODE enumeration

## Description

Specifies triangles facing a particular direction are not drawn.

## Constants

### `D3D12_CULL_MODE_NONE:1`

Always draw all triangles.

### `D3D12_CULL_MODE_FRONT:2`

Do not draw triangles that are front-facing.

### `D3D12_CULL_MODE_BACK:3`

Do not draw triangles that are back-facing.

## Remarks

Cull mode is specified in a [D3D12_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rasterizer_desc) structure.

## See also

[CD3DX12_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-rasterizer-desc)

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)