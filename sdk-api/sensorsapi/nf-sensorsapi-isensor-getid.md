# ISensor::GetID

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves the unique identifier of the sensor.

## Parameters

### `pID` [out]

Address of a **SENSOR_ID** that receives the ID.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The sensor driver did not provide a sensor ID. |
| **E_POINTER** | NULL was passed in for pID. |

## Remarks

A **SENSOR_ID** is a **GUID** that uniquely identifies the sensor on the current computer. This ID corresponds to the constant named SENSOR_PROPERTY_PERSISTENT_UNIQUE_ID.

You can use an ID to retrieve a pointer to a particular sensor by calling [ISensorManager::GetSensorByID](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensormanager-getsensorbyid).

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)

[Sensor Constants](https://learn.microsoft.com/windows/desktop/SensorsAPI/about-sensor-constants)