# ISensorManager::SetEventSink

## Description

Specifies the interface through which to receive sensor manager event notifications.

## Parameters

### `pEvents` [in]

Pointer to the [ISensorManagerEvents](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensormanagerevents) callback interface that receives the event notifications. Set to **NULL** to stop receiving event notifications.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ISensorManager](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensormanager)