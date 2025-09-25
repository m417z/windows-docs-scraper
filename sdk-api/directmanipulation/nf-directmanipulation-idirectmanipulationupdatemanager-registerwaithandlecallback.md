# IDirectManipulationUpdateManager::RegisterWaitHandleCallback

## Description

Registers a callback that is triggered by a handle.

## Parameters

### `handle` [in]

The event handle that triggers the callback.

### `eventHandler` [in]

The event handler to call when the event is fired.

### `cookie` [out]

The unique ID of the event callback instance.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirectManipulationUpdateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationupdatemanager)