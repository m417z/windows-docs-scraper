# IDeviceController::streaming

## Description

Unregisters an event handler for the [DeviceArrival](https://learn.microsoft.com/windows/desktop/mediastreaming/devicearrival) event.

## Parameters

### `token` [in]

A reference to a token obtained from the [add_DeviceArrival](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828903(v=vs.85)) method when the event handler was registered.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IDeviceController](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828901(v=vs.85))