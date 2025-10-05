# ISensor::SupportsDataField

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Indicates whether the sensor supports the specified data field.

## Parameters

### `key` [in]

**REFPROPERTYKEY** value specifying the data field to search for.

### `pIsSupported` [out]

Address of a **VARIANT_BOOL** that receives a value indicating whether the sensor supports the data field.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL was passed in for pIsSupported. |

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)