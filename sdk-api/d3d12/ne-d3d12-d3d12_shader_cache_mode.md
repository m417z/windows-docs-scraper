## Description

Defines constants that specify a shader cache's mode.

## Constants

### `D3D12_SHADER_CACHE_MODE_MEMORY:0`

Specifies that there's no backing file for this cache. All stores are discarded when the session object is destroyed.

### `D3D12_SHADER_CACHE_MODE_DISK`

Specifies that the session is backed by files on disk that persist from run to run unless cleared. For ways to clear a disk cache, see [ID3D12ShaderCacheSession::SetDeleteOnDestroy](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12shadercachesession-setdeleteondestroy).

## Remarks

## See also

* [ID3D12ShaderCacheSession::SetDeleteOnDestroy](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12shadercachesession-setdeleteondestroy)
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)