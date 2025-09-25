# D3D12_CONSERVATIVE_RASTERIZATION_TIER enumeration

## Description

Identifies the tier level of conservative rasterization.

## Constants

### `D3D12_CONSERVATIVE_RASTERIZATION_TIER_NOT_SUPPORTED:0`

Conservative rasterization is not supported.

### `D3D12_CONSERVATIVE_RASTERIZATION_TIER_1:1`

Tier 1 enforces a maximum 1/2 pixel uncertainty region and does not support post-snap degenerates. This is good for tiled rendering, a texture atlas, light map generation and sub-pixel shadow maps.

### `D3D12_CONSERVATIVE_RASTERIZATION_TIER_2:2`

 Tier 2 reduces the maximum uncertainty region to 1/256 and requires post-snap degenerates not be culled. This tier is helpful for CPU-based algorithm acceleration (such as voxelization).

### `D3D12_CONSERVATIVE_RASTERIZATION_TIER_3:3`

 Tier 3 maintains a maximum 1/256 uncertainty region and adds support for inner input coverage. Inner input coverage adds the new value `SV_InnerCoverage` to High Level Shading Language (HLSL). This is a 32-bit scalar integer that can be specified on input to a pixel shader, and represents the underestimated conservative rasterization information (that is, whether a pixel is guaranteed-to-be-fully covered). This tier is helpful for occlusion culling.

## Remarks

This enum is used by the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure.

## See also

[Conservative Rasterization](https://learn.microsoft.com/windows/desktop/direct3d12/conservative-rasterization)

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[D3D12_CONSERVATIVE_RASTERIZATION_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_conservative_rasterization_mode)