# IHWEventHandler::HandleEvent

## Description

Handles AutoPlay device events for which there is no content of the type the application is registered to handle.

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

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The event types are not C/C++ language constants; they are literal text strings.

## See also

[IHWEventHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ihweventhandler)

[IHWEventHandler::HandleEventWithContent](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-ihweventhandler-handleeventwithcontent)