# ISensorEvents::OnDataUpdated

## Description

Provides sensor event data.

## Parameters

### `pSensor` [in]

Pointer to the [ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor) interface of the sensor that raised the event.

### `pNewData` [in]

Pointer to the [ISensorDataReport](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensordatareport) interface that contains the event data.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ISensorEvents](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorevents)