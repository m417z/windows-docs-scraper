# ISystemMediaTransportControlsInterop::GetForWindow

## Description

Gets an instance of the [ISystemMediaTransportControls](https://learn.microsoft.com/previous-versions/windows/desktop/mediatransport/isystemmediatransportcontrols) interface for the specified window.

## Parameters

### `appWindow`

The top-level app window for which the [ISystemMediaTransportControls](https://learn.microsoft.com/previous-versions/windows/desktop/mediatransport/isystemmediatransportcontrols) interface is retrieved.

### `riid`

A reference to the IID of the interface to retrieve.

### `mediaTransportControl` [out]

Receives the [ISystemMediaTransportControls](https://learn.microsoft.com/previous-versions/windows/desktop/mediatransport/isystemmediatransportcontrols) that corresponds to the *appWindow* window.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

The *appWindow* parameter must refer to a top-level window that belongs to the calling process.

## See also

[ISystemMediaTransportControlsInterop](https://learn.microsoft.com/windows/win32/api/systemmediatransportcontrolsinterop/nn-systemmediatransportcontrolsinterop-isystemmediatransportcontrolsinterop)