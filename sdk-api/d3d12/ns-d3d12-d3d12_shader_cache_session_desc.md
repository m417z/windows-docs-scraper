## Description

Describes a shader cache session.

## Members

### `Identifier`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

A unique identifier to give to this specific cache. Caches with different identifiers are stored side by side. Caches with the same identifier are shared across all sessions in the same process. Creating a disk cache with the same identifier as an already-existing cache opens that cache, unless the **Version** doesn't matches. In that case, if there are no other sessions open to that cache, it is cleared and re-created. If there are existing sessions, then [ID3D12Device9::CreateShaderCacheSession](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device9-createshadercachesession) returns **DXGI_ERROR_ALREADY_EXISTS**.

### `Mode`

Type: **[D3D12_SHADER_CACHE_MODE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_mode)**

Specifies the kind of cache.

### `Flags`

Type: **[D3D12_SHADER_CACHE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_flags)**

Modifies the behavior of the cache.

### `MaximumInMemoryCacheSizeBytes`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

For in-memory caches, this is the only storage available. For disk caches, all entries that are stored or found are temporarily stored in memory, until evicted by newer entries. This value determines the size of that temporary storage. Defaults to 1KB.

### `MaximumInMemoryCacheEntries`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specifies how many entries can be stored in memory. Defaults to 128.

### `MaximumValueFileSizeBytes`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

For disk caches, controls the maximum file size. Defaults to 128MB.

### `Version`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Can be used to implicitly clear caches when an application or component update is done. If the version doesn't match the version stored in the cache, then it will be wiped and re-created.

## Remarks

## See also

* [ID3D12Device9::CreateShaderCacheSession](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device9-createshadercachesession)
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)