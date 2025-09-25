# IBasicDevice::streaming

## Description

Unregisters an event handler for the [ConnectionStatusChanged](https://learn.microsoft.com/windows/desktop/mediastreaming/connectionstatuschanged) event.

## Parameters

### `token` [in]

A reference to a token obtained from the [add_ConnectionStatusChanged](https://learn.microsoft.com/windows/desktop/mediastreaming/ibasicdevice-add-connectionstatuschanged) method when the event handler was registered.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IBasicDevice](https://learn.microsoft.com/windows/desktop/mediastreaming/ibasicdevice)