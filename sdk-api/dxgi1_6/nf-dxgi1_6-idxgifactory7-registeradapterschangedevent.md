# IDXGIFactory7::RegisterAdaptersChangedEvent

## Description

Registers to receive notification of changes whenever the adapter enumeration state changes.

## Parameters

### `hEvent` [in]

A handle to the event object.

### `pdwCookie` [in, out]

A key value for the registered event.

## Return value

Returns **S_OK** if successful; an error code otherwise.

## See also

[IDXGIFactory7](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nn-dxgi1_6-idxgifactory7)

[UnregisterAdaptersChangedEvent](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nf-dxgi1_6-idxgifactory7-unregisteradapterschangedevent)