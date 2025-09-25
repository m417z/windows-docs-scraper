# D3D12_FEATURE_DATA_FEATURE_LEVELS structure

## Description

Describes info about the [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) supported by the current graphics driver.

## Members

### `NumFeatureLevels`

The number of [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) in the array at **pFeatureLevelsRequested**.

### `pFeatureLevelsRequested`

A pointer to an array of [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)s that the application is requesting for the driver and hardware to evaluate.

### `MaxSupportedFeatureLevel`

The maximum [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) that the driver and hardware support.

## Remarks

See [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)