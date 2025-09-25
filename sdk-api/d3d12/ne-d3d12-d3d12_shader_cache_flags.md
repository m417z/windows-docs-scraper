## Description

Defines constants that specify shader cache flags.

## Constants

### `D3D12_SHADER_CACHE_FLAG_NONE:0`

Specifies no flag.

### `D3D12_SHADER_CACHE_FLAG_DRIVER_VERSIONED:0x1`

Specifies that the cache is implicitly versioned by the driver being used. For multi-GPU systems, a cache created this way is stored side by side for each adapter on which the application runs. The *Version* field in the [D3D12_SHADER_CACHE_SESSION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_cache_session_desc) struct (the cache description) is used as an additional constraint.

### `D3D12_SHADER_CACHE_FLAG_USE_WORKING_DIR:0x2`

By default, caches are stored in temporary storage, and can be cleared by disk cleanup. This constant (not valid for UWP apps) specifies that the cache is instead stored in the current working directory.

## Remarks

## See also

* [D3D12_SHADER_CACHE_SESSION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_cache_session_desc)
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)