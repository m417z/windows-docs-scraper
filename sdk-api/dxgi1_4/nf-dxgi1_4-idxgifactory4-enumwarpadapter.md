# IDXGIFactory4::EnumWarpAdapter

## Description

Provides an adapter which can be provided to D3D12CreateDevice to use the WARP renderer.

## Parameters

### `riid` [in]

Type: **REFIID**

The globally unique identifier (GUID) of the [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) object referenced by the *ppvAdapter* parameter.

### `ppvAdapter` [out]

Type: **void****

The address of an [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) interface pointer to the adapter.
This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; an error code otherwise.
For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).
See also Direct3D 12 Return Codes.

## Remarks

For more information, see [DXGI 1.4 Improvements](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-1-4-improvements).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIFactory4](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nn-dxgi1_4-idxgifactory4)