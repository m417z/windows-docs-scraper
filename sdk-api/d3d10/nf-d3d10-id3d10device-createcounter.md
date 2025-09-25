# ID3D10Device::CreateCounter

## Description

Create a counter object for measuring GPU performance.

## Parameters

### `pCounterDesc` [in]

Type: **const [D3D10_COUNTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_counter_desc)***

Pointer to a counter description (see [D3D10_COUNTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_counter_desc)).

### `ppCounter` [out]

Type: **[ID3D10Counter](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10counter)****

Address of a pointer to a counter (see [ID3D10Counter Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10counter)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it will return S_OK. If it fails, possible return values are: S_FALSE, E_OUTOFMEMORY, DXGI_ERROR_UNSUPPORTED, DXGI_ERROR_NONEXCLUSIVE, or E_INVALIDARG.

DXGI_ERROR_UNSUPPORTED is returned whenever the application requests to create a well-known counter, but the current device does not support it.

DXGI_ERROR_NONEXCLUSIVE indicates that another device object is currently using the counters, so they cannot be used by this device at the moment.

E_INVALIDARG is returned whenever an out-of-range well-known or device-dependent counter is requested, or when the simulataneously active counters have been exhausted.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)