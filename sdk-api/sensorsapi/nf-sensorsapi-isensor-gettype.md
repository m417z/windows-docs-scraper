# ISensor::GetType

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves the sensor type ID.

## Parameters

### `pSensorType` [out]

Address of a **SENSOR_TYPE_ID** that receives the sensor type ID.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The sensor driver did not provide a sensor type value. The **PROPVARIANT** returned will have its error value set to **HRESULT_FROM_WIN32 ( ERROR_NOT_FOUND)**. |
| **E_POINTER** | NULL was passed in for pSensorType. |

## Remarks

Sensor types are more specific groupings than sensor categories.
Sensor type IDs are **GUID**s that are defined in Sensors.h.

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)

[Sensor Categories, Types, and Data Fields](https://learn.microsoft.com/windows/desktop/SensorsAPI/sensor-categories--types--and-datafields)