## Description

Adds an entry to the cache.

## Parameters

### `pKey`

Type: \_In\_reads\_bytes\_(KeySize) **const void \***

The key of the entry to add.

### `KeySize`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the key, in bytes.

### `pValue`

Type: \_In\_reads\_bytes\_(ValueSize) **void \***

A pointer to a memory block containing the entry to add.

### `ValueSize`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the entry to add, in bytes.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
| DXGI_ERROR_ALREADY_EXISTS | There's an entry with the same key. |
| DXGI_ERROR_CACHE_HASH_COLLISION | There's an entry with the same hash as the provided key, but the key doesn't match. |
| DXGI_ERROR_CACHE_FULL | Adding this entry would cause the cache to become larger than its maximum size. |

## Remarks

## See also
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)