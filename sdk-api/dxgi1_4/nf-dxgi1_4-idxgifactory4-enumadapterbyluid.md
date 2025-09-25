# IDXGIFactory4::EnumAdapterByLuid

## Description

Outputs the [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) for the specified LUID.

## Parameters

### `AdapterLuid` [in]

Type: **[LUID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549708(v=vs.85))**

A unique value that identifies the adapter.
See [LUID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549708(v=vs.85)) for a definition of the structure.
**LUID** is defined in dxgi.h.

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

For Direct3D 12, it's no longer possible to backtrack from a device to the [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) that was used to create it.
**IDXGIFactory4::EnumAdapterByLuid** enables an app to retrieve information about the adapter where a D3D12 device was created.
**IDXGIFactory4::EnumAdapterByLuid** is designed to be paired with [ID3D12Device::GetAdapterLuid](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getadapterluid).
For more information, see [DXGI 1.4 Improvements](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-1-4-improvements).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIFactory4](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nn-dxgi1_4-idxgifactory4)