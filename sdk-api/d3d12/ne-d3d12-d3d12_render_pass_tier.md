# D3D12_RENDER_PASS_TIER enumeration

## Description

Specifies the level of support for render passes on a graphics device.

## Constants

### `D3D12_RENDER_PASS_TIER_0:0`

The user-mode display driver hasn't implemented render passes, and so the feature is provided only via software emulation. Render passes might not provide a performance advantage at this level of support.

### `D3D12_RENDER_PASS_TIER_1:1`

The render passes feature is implemented by the user-mode display driver, and render target/depth buffer writes may be accelerated. Unordered access view (UAV) writes are not efficiently supported within the render pass.

### `D3D12_RENDER_PASS_TIER_2:2`

The render passes feature is implemented by the user-mode display driver, render target/depth buffer writes may be accelerated, and unordered access view (UAV) writes (provided that writes in a render pass are not read until a subsequent render pass) are likely to be more efficient than issuing the same work without using a render pass.

## Remarks

To determine the level of support for render passes for a graphics device, pass [D3D12_FEATURE_DATA_D3D12_OPTIONS5](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options5) struct.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)