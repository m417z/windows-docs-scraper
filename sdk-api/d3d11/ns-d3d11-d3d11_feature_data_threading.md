# D3D11_FEATURE_DATA_THREADING structure

## Description

Describes the multi-threading features that are supported by the current graphics driver.

## Members

### `DriverConcurrentCreates`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** means resources can be created concurrently on multiple threads while drawing; **FALSE** means that the presence of coarse synchronization will prevent concurrency.

### `DriverCommandLists`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** means command lists are supported by the current driver; **FALSE** means that the API will emulate deferred contexts and command lists with software.

## Remarks

Use the D3D11_FEATURE_DATA_THREADING structure with the [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) method to determine multi-threading support.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)