# ISensorDataReport::GetSensorValue

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves a single data field value from the data report.

## Parameters

### `pKey` [in]

**REFPROPERTYKEY** indicating the data field to retrieve.

### `pValue` [out]

Address of a **PROPVARIANT** that receives the data field value.

## Return value

This method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The data field was not found. |
| **E_POINTER** | NULL was passed in for pValue. |

## Remarks

Platform-defined data field **PROPERTYKEY**s are defined in Sensors.h.

#### Examples

For an example of how to retrieve a sensor data field value, see [Retrieving Sensor Data Values](https://learn.microsoft.com/windows/desktop/SensorsAPI/retrieving-sensor-data-fields).

## See also

[ISensorDataReport](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensordatareport)