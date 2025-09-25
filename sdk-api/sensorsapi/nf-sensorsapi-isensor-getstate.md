# ISensor::GetState

## Description

Retrieves the current operational state of the sensor.

## Parameters

### `pState` [out]

Address of a [SensorState](https://learn.microsoft.com/windows/win32/api/sensorsapi/ne-sensorsapi-sensorstate) variable that receives the current state.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The sensor driver did not provide a state value. The value provided through *pState* is not valid. |
| **E_POINTER** | NULL was passed in for pState. |

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)