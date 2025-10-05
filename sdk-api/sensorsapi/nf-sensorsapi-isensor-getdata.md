# ISensor::GetData

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves the most recent sensor data report.

## Parameters

### `ppDataReport` [out]

Address of an [ISensorDataReport](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensordatareport) pointer that receives the pointer to the most recent sensor data report.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The sensor driver provided badly formed data. For example, the data was of a type that is not supported. For information about data types of platform-defined data fields, see [Sensor Categories, Types, and Data Fields](https://learn.microsoft.com/windows/desktop/SensorsAPI/sensor-categories--types--and-datafields). |
| **HRESULT_FROM_WIN32(ERROR_NO_DATA)** | The sensor has no data to report. For example, a GPS sensor could be in the process of acquiring a satellite fix. |
| **E_POINTER** | NULL was passed in for ppDataReport. |

## Remarks

For location sensors, you can retrieve data only from sensors for which the user has granted permission.

This method may return data before the driver has set the state to SENSOR_STATE_READY.

#### Examples

For an example of how to retrieve sensor data, see [Retrieving Sensor Data Values](https://learn.microsoft.com/windows/desktop/SensorsAPI/retrieving-sensor-data-fields).

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)

[Managing User Permissions](https://learn.microsoft.com/windows/desktop/SensorsAPI/managing-user-permissions)

[RequestPermissions](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensormanager-requestpermissions)

[Sensor Categories, Types, and Data Fields](https://learn.microsoft.com/windows/desktop/SensorsAPI/sensor-categories--types--and-datafields)