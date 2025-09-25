# IHWEventHandler2::HandleEventWithHWND

## Description

Handles AutoPlay device events that contain content types that the application is not registered to handle. This method provides a handle to the owner window so that UI can be displayed if the process requires elevated privileges.

## Parameters

### `pszDeviceID` [in]

Type: **LPCWSTR**

A pointer to a string buffer that contains the device ID.

### `pszAltDeviceID` [in]

Type: **LPCWSTR**

A pointer to a string buffer that contains the alternate device ID. The alternate device ID is more human-readable than the primary device ID.

### `pszEventType` [in]

Type: **LPCWSTR**

A pointer to a string buffer that contains the event type. The event types include DeviceArrival, DeviceRemoval, MediaArrival, and MediaRemoval.

### `hwndOwner` [in]

Type: **HWND**

A handle to the AutoPlay dialog that was displayed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a handler is invoked and requires immediate privilege elevation in a new process, it requires an active parent window handle to display its consent UI. [IHWEventHandler::HandleEvent](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-ihweventhandler-handleevent) cannot give a handle, so only a blinking taskbar appears. **IHWEventHandler2::HandleEventWithHWND** provides the HWND and enables the UI to be displayed.

Note that if the handler was launched by default instead of by direct user action, the HWND is not active and the dialog is not shown in the foreground.

The event types are not C/C++ language constants; they are literal text strings.