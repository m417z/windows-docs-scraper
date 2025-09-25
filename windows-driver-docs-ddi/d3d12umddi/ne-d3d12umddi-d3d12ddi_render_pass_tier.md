# D3D12DDI_RENDER_PASS_TIER enumeration

## Description

A **D3D12DDI_RENDER_PASS_TIER** value indicates the level of support that a user-mode driver (UMD) provides for render passes.

## Constants

### `D3D12DDI_RENDER_PASS_TIER_NOT_SUPPORTED:0`

The UMD has not implemented a DDI Table, which is supported via software emulation.

### `D3D12DDI_RENDER_PASS_TIER_1:1`

The driver provides tier 1 support.

### `D3D12DDI_RENDER_PASS_TIER_2:2`

The driver provides tier 2 support.

## Remarks

See [**D3D12_VIEW_INSTANCING_TIER**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_tiled_resources_tier) for a detailed description for each tier level.

The UMD will report back these tiers to the runtime. The runtime will validate that UMDs that fill out the DDI table report back at least TIER_1 support. At the same time, the runtime will validate that UMDs that do not fill out the DDI table do not claim anything other than TIER_0 support (the runtime will fail device creation in this case).

> [!NOTE]
> This requirement will only be present for UMDs that support the DDI build version in which this change is made.

## See also

[**D3D12DDI_D3D12_OPTIONS_DATA_0089**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_d3d12_options_data_0089)