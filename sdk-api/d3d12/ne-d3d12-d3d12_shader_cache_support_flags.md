# D3D12_SHADER_CACHE_SUPPORT_FLAGS enumeration

## Description

Describes the level of support for shader caching in the current graphics driver.

## Constants

### `D3D12_SHADER_CACHE_SUPPORT_NONE:0`

Indicates that the driver does not support shader caching.

### `D3D12_SHADER_CACHE_SUPPORT_SINGLE_PSO:0x1`

Indicates that the driver supports the CachedPSO member of the [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) and [D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc) structures. This is always supported.

### `D3D12_SHADER_CACHE_SUPPORT_LIBRARY:0x2`

Indicates that the driver supports the ID3D12PipelineLibrary interface, which provides application-controlled PSO grouping and caching. This is supported by drivers targetting the Windows 10 Anniversary Update.

### `D3D12_SHADER_CACHE_SUPPORT_AUTOMATIC_INPROC_CACHE:0x4`

Indicates that the driver supports an OS-managed shader cache that stores compiled shaders in memory during the current run of the application.

### `D3D12_SHADER_CACHE_SUPPORT_AUTOMATIC_DISK_CACHE:0x8`

Indicates that the driver supports an OS-managed shader cache that stores compiled shaders on disk to accelerate future runs of the application.

## Remarks

This enum is used by the [D3D_FEATURE_DATA_SHADER_CACHE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_shader_cache) structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)