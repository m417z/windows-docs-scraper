## Description

Defines constants that specify a kind of shader cache.

## Constants

### `D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_D3D_CACHE_FOR_DRIVER:0x1`

Specifies a cache that's managed by Direct3D 12 to store driver compilations of application shaders.

### `D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_D3D_CONVERSIONS:0x2`

Specifies a cache that's used to store Direct3D 12's conversions of one shader type to another (for example, DXBC shaders to DXIL shaders).

### `D3D12_SHADER_CACHE_KIND_FLAG_IMPLICIT_DRIVER_MANAGED:0x4`

Specifies a cache that's managed by the driver. Operations for this cache are hints.

### `D3D12_SHADER_CACHE_KIND_FLAG_APPLICATION_MANAGED:0x8`

Specifies all shader cache sessions created by the [ID3D12Device9::CreateShaderCacheSession](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device9-createshadercachesession) method. Requests to **CLEAR** with this flag apply to all currently active application cache sessions, as well as on-disk caches created without [D3D12_SHADER_CACHE_FLAG_USE_WORKING_DIR](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_flags).

## Remarks

## See also
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)