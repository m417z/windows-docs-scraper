# ISensorManagerEvents::OnSensorEnter

## Description

Provides notification when a sensor device is connected.

## Parameters

### `pSensor` [in]

A pointer to the [ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor) interface of the sensor that was connected.

### `state` [in]

[SensorState](https://learn.microsoft.com/windows/win32/api/sensorsapi/ne-sensorsapi-sensorstate) indicating the current state of the sensor.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To know when a sensor is disconnected, subscribe to the [ISensorEvents::OnLeave](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensorevents-onleave) event.

## See also

[ISensorManagerEvents](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensormanagerevents)