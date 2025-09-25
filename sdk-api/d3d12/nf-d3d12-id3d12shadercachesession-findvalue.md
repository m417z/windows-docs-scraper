## Description

Looks up an entry in the cache whose key exactly matches the provided key.

Call the function twice. The first time to retrieve the value's size, and the second time to retrieve the data. In-memory temporary storage makes this calling pattern performant.

## Parameters

### `pKey`

Type: \_In\_reads\_bytes\_(KeySize) **const void \***

The key of the entry to look up.

### `KeySize`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the key, in bytes.

### `pValue`

Type: \_Out\_writes\_bytes\_(*pValueSize) **void \***

A pointer to a memory block that receives the cached entry.

### `pValueSize`

Type: \_Inout\_ **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to a **UINT** that receives the size of the cached entry, in bytes.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
| DXGI_ERROR_CACHE_HASH_COLLISION | There's an entry with the same hash as the provided key, but the key doesn't exactly match. |
| DXGI_ERROR_NOT_FOUND | The entry isn't present. |

## Remarks

## See also
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)