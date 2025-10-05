# ISensor::GetProperty

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves a property value.

## Parameters

### `key` [in]

**REFPROPERTYKEY** specifying the property value to be retrieved.

### `pProperty` [out]

**PROPVARIANT** pointer that receives the property value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The sensor does not support the specified property. The value provided through *pProperty* is **VT_NULL**. |
| **E_POINTER** | NULL was passed in for pProperty. |

## Remarks

To retrieve multiple property values as a collection, call [ISensor::GetProperties](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensor-getproperties).

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)