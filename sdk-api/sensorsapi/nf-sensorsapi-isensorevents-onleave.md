# ISensorEvents::OnLeave

## Description

Provides notification that a sensor device is no longer connected.

## Parameters

### `ID` [in]

The ID of the sensor.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To know when a sensor enters, subscribe to the [ISensorManagerEvents::OnSensorEnter](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensormanagerevents-onsensorenter) event.

#### Examples

For an example of how to receive sensor events, see [Using Sensor API Events](https://learn.microsoft.com/windows/desktop/SensorsAPI/using-sensor-api-events).

## See also

[ISensorEvents](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorevents)