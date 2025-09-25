# ISensorEvents::OnStateChanged

## Description

Provides a notification that a sensor state has changed.

## Parameters

### `pSensor` [in]

Pointer to the [ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor) interface of the sensor that raised the event.

### `state` [in]

[SensorState](https://learn.microsoft.com/windows/win32/api/sensorsapi/ne-sensorsapi-sensorstate) containing the new state.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ISensorEvents](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorevents)