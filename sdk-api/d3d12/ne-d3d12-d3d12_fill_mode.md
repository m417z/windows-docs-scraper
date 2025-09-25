# D3D12_FILL_MODE enumeration

## Description

Specifies the fill mode to use when rendering triangles.

## Constants

### `D3D12_FILL_MODE_WIREFRAME:2`

Draw lines connecting the vertices. Adjacent vertices are not drawn.

### `D3D12_FILL_MODE_SOLID:3`

Fill the triangles formed by the vertices. Adjacent vertices are not drawn.

## Remarks

Fill mode is specified in a [D3D12_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_rasterizer_desc) structure.

## See also

[CD3DX12_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-rasterizer-desc)

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)