# ISensorManager::GetSensorsByType

## Description

Retrieves a collection containing all sensors associated with the specified type.

## Parameters

### `sensorType` [in]

ID of the type of sensors to retrieve.

### `ppSensorsFound` [out]

Address of an [ISensorCollection](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorcollection) interface pointer that receives the pointer to the sensor collection requested.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | No sensors are available for the specified type. |
| **E_POINTER** | NULL was passed in for ppSensorsFound. |

## See also

[ISensorManager](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensormanager)

[Retrieving a Sensor Object](https://learn.microsoft.com/windows/desktop/SensorsAPI/retrieving-a-sensor)