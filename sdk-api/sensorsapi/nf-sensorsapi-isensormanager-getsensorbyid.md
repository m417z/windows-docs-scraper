# ISensorManager::GetSensorByID

## Description

Retrieves a pointer to the specified sensor.

## Parameters

### `sensorID` [in]

The ID of the sensor to retrieve.

### `ppSensor` [out]

Address of an [ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor) interface pointer that receives a pointer to the requested sensor. Will be **NULL** if the requested sensor cannot be found.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The sensor manager found more than one sensor with the same ID. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | No sensor is available for the specified ID. |
| **E_POINTER** | NULL was passed in for ppSensor. |

## See also

[ISensorManager](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensormanager)

[Retrieving a Sensor Object](https://learn.microsoft.com/windows/desktop/SensorsAPI/retrieving-a-sensor)