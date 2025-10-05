# ISensor::GetCategory

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves the identifier of the sensor category.

## Parameters

### `pSensorCategory` [out]

Address of a **SENSOR_CATEGORY_ID** that receives the sensor category ID.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The sensor driver did not provide a category value. The **PROPVARIANT** returned will have its error value set to **HRESULT_FROM_WIN32 ( ERROR_NOT_FOUND)**. |
| **E_POINTER** | NULL was passed in for pSensorCategory. |

## Remarks

A **SENSOR_CATEGORY_ID** is a **GUID** that uniquely identifies the sensor category.

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)

[Sensor Categories, Types, and Data Fields](https://learn.microsoft.com/windows/desktop/SensorsAPI/sensor-categories--types--and-datafields)