# IDXGIDevice::GetAdapter

## Description

Returns the adapter for the specified device.

## Parameters

### `pAdapter` [out]

Type: **[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)****

The address of an [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) interface pointer to the adapter. This parameter must not be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) that indicates failure. If the *pAdapter* parameter is **NULL** this method returns E_INVALIDARG.

## Remarks

If the **GetAdapter** method succeeds, the reference count on the adapter interface will be incremented. To avoid a memory leak, be sure to release the interface when you are finished using it.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)