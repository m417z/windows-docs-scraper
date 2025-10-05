# ISensorManager::GetSensorsByCategory

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves a collection containing all sensors associated with the specified category.

## Parameters

### `sensorCategory` [in]

ID of the sensor category to retrieve.

### `ppSensorsFound` [out]

Address of an [ISensorCollection](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorcollection) interface pointer that receives a pointer to the sensor collection requested.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | No sensors are available for the specified category. |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL was passed in for ppSensorsFound. |

## See also

[ISensorManager](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensormanager)

[Retrieving a Sensor Object](https://learn.microsoft.com/windows/desktop/SensorsAPI/retrieving-a-sensor)