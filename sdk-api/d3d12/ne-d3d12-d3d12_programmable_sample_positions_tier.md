# D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER enumeration

## Description

Specifies the level of support for programmable sample positions that's offered by the adapter.

## Constants

### `D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_NOT_SUPPORTED:0`

Indicates that there's no support for programmable sample positions.

### `D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_1:1`

Indicates that there's tier 1 support for programmable sample positions. In tier 1, a single sample pattern can be specified to repeat for every pixel ([SetSamplePosition](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist1-setsamplepositions) parameter *NumPixels* = 1) and ResolveSubResource is supported.

### `D3D12_PROGRAMMABLE_SAMPLE_POSITIONS_TIER_2:2`

Indicates that there's tier 2 support for programmable sample positions. In tier 2, four separate sample patterns can be specified for each pixel in a 2x2 grid ([SetSamplePosition](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist1-setsamplepositions) parameter *NumPixels* = 4) that repeats over the render-target or viewport, aligned on even coordinates .

## Remarks

This enum is used by the [D3D12_FEATURE_D3D12_DATA_OPTIONS2](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options2) structure to indicate the level of support offered for programmable sample positions.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)