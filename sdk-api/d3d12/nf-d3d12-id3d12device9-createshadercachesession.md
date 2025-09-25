## Description

Creates an object that grants access to a shader cache, potentially opening an existing cache or creating a new one.

## Parameters

### `pDesc`

Type: \_In\_ **const [D3D12_SHADER_CACHE_SESSION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_cache_session_desc)\***

A **D3D12_SHADER_CACHE_SESSION_DESC** structure describing the shader cache session to create.

### `riid`

Type: **[REFIID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/bbde795f-5398-42d8-9f59-3613da03c318)**

The globally unique identifier (GUID) for the shader cache session interface.

### `ppvSession`

Type: \_COM\_Outptr\_opt\_ **void\*\***

A pointer to a memory block that receives a pointer to the [ID3D12ShaderCacheSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12shadercachesession) interface for the shader cache session.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
| DXGI_ERROR_ALREADY_EXISTS | You tried to create a cache with an existing identifier. See [D3D12_SHADER_CACHE_SESSION_DESC::Identifier](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_cache_session_desc). |

## Remarks

## See also
* [D3D12 shader cache APIs](https://microsoft.github.io/DirectX-Specs/d3d/ShaderCache.html)