## Description

Modifies the behavior of caches used internally by Direct3D or by the driver. **ShaderCacheControl** may be used only in developer mode.

## Parameters

### `Kinds`

Type: **[D3D12_SHADER_CACHE_KIND_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_kind_flags)**

The caches to modify. Any one of these caches may or may not exist.

### `Control`

Type: **[D3D12_SHADER_CACHE_CONTROL_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_control_flags)**

The way in which to modify the caches. You can't pass both **DISABLE** and **ENABLE** at the same time; and you must pass at least one flag.

## Return value

## Remarks

## See also
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)