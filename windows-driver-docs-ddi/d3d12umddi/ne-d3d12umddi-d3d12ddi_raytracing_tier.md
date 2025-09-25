# D3D12DDI_RAYTRACING_TIER enumeration

## Description

A **D3D12DDI_RAYTRACING_TIER** value specifies the level of raytracing support provided by the graphics hardware.

## Constants

### `D3D12DDI_RAYTRACING_TIER_NOT_SUPPORTED:0`

There is no support for raytracing on the device.

### `D3D12DDI_RAYTRACING_TIER_1_0:10`

The device supports tier 1 raytracing.

### `D3D12DDI_RAYTRACING_TIER_1_1:11`

The device supports tier 1.1 raytracing. Available starting with Windows 10, version 2004.

## Remarks

See [**D3D12_RAYTRACING_TIER**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_raytracing_tier) for a detailed description for each tier level.

See the [DirectX Raytracing (DXR) functional specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

## See also

[**D3D12DDI_D3D12_OPTIONS_DATA_0089**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_d3d12_options_data_0089)