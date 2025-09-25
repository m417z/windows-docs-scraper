# D3D11_SHADER_CACHE_SUPPORT_FLAGS enumeration

## Description

Describes the level of support for shader caching in the current graphics driver.

## Constants

### `D3D11_SHADER_CACHE_SUPPORT_NONE:0`

Indicates that the driver does not support shader caching.

### `D3D11_SHADER_CACHE_SUPPORT_AUTOMATIC_INPROC_CACHE:0x1`

Indicates that the driver supports an OS-managed shader cache that stores compiled shaders in memory during the current run of the application.

### `D3D11_SHADER_CACHE_SUPPORT_AUTOMATIC_DISK_CACHE:0x2`

Indicates that the driver supports an OS-managed shader cache that stores compiled shaders on disk to accelerate future runs of the application.

## Remarks

This enum is used by the [D3D11_FEATURE_DATA_SHADER_CACHE](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_shader_cache) structure.

## See also

[Core structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3d11-core-structures)