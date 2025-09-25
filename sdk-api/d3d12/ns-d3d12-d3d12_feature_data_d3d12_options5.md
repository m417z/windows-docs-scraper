# D3D12_FEATURE_DATA_D3D12_OPTIONS5 structure

## Description

Indicates the level of support that the adapter provides for render passes, ray tracing, and shader-resource view tier 3 tiled resources.

## Members

### `SRVOnlyTiledResourceTier3`

A boolean value indicating whether the options require shader-resource view tier 3 tiled resource support. For more information, see [D3D12_TILED_RESOURCES_TIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_tiled_resources_tier).

### `RenderPassesTier`

The extent to which a device driver and/or the hardware efficiently supports render passes. See [D3D12_RENDERPASS_TIER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_render_pass_tier).

#### RaytracingTier

Specifies the level of ray tracing support on the graphics device. See [D3D12_RAYTRACING_TIER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_raytracing_tier).

### `RaytracingTier`

## Remarks

Pass [D3D12_FEATURE_D3D12_OPTIONS5](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature) to [ID3D12Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport) to retrieve a **D3D12_FEATURE_DATA_D3D12_OPTIONS5** structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)