# D3D12_COLOR_WRITE_ENABLE enumeration

## Description

Identifies which components of each pixel of a render target are writable during blending.

## Constants

### `D3D12_COLOR_WRITE_ENABLE_RED:1`

Allow data to be stored in the red component.

### `D3D12_COLOR_WRITE_ENABLE_GREEN:2`

Allow data to be stored in the green component.

### `D3D12_COLOR_WRITE_ENABLE_BLUE:4`

Allow data to be stored in the blue component.

### `D3D12_COLOR_WRITE_ENABLE_ALPHA:8`

Allow data to be stored in the alpha component.

### `D3D12_COLOR_WRITE_ENABLE_ALL`

Allow data to be stored in all components.

## Remarks

This enum is used by the [D3D12_RENDER_TARGET_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_blend_desc) structure.

## See also

[CD3DX12_BLEND_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-blend-desc)

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)