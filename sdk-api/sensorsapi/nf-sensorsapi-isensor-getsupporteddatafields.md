# ISensor::GetSupportedDataFields

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves a set of **PROPERTYKEY**s that represent the data fields the sensor can provide.

## Parameters

### `ppDataFields` [out]

Address of the [IPortableDeviceKeyCollection](https://learn.microsoft.com/previous-versions//ms739549(v=vs.85)) pointer that receives the list of supported data fields.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL was passed in for ppDataFields. |

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)