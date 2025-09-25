## Description

When all cache session objects corresponding to a given cache are destroyed, the cache is cleared.

See **Remarks** for the ways in which a disk cache can be cleared.

## Remarks

A disk cache can be cleared in one of the following ways.

* Explicitly, by calling **SetDeleteOnDestroy** on the session object, and then releasing the session.
* Explicitly, in developer mode, by calling [ID3D12Device9::ShaderCacheControl](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device9-shadercachecontrol) with [D3D12_SHADER_CACHE_KIND_FLAG_APPLICATION_MANAGED](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_kind_flags).
* Implicitly, by creating a session object with a version that doesn't match the version used to create it.
* Externally, by the disk cleanup utility enumerating it and clearing it. This won't happen for caches created with the [D3D12_SHADER_CACHE_FLAG_USE_WORKING_DIR](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_flags) flag.
* Manually, by deleting the files (`*.idx`, `*.val`, and `*.lock`) stored on disk for [D3D12_SHADER_CACHE_FLAG_USE_WORKING_DIR](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_flags) caches. Your application shouldn't attempt to do this for caches stored outside of the working directory.

## See also
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)