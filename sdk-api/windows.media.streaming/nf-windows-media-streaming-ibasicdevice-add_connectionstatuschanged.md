# IBasicDevice::streaming

## Description

Registers an event handler for the [ConnectionStatusChanged](https://learn.microsoft.com/windows/desktop/mediastreaming/connectionstatuschanged) event.

## Parameters

### `handler` [in]

A [ConnectionStatusHandler](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828836(v=vs.85)) event handler function.

### `token` [out, retval]

Reference to a token that can be used to unregister the event handler.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To unregister the event handler that was registered by this method, pass the *token* value to the [remove_ConnectionStatusChanged](https://learn.microsoft.com/windows/desktop/mediastreaming/ibasicdevice-remove-connectionstatuschanged) method.

## See also

[IBasicDevice](https://learn.microsoft.com/windows/desktop/mediastreaming/ibasicdevice)