# ISensor::SetProperties

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Specifies sensor properties.

## Parameters

### `pProperties` [in]

 Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/previous-versions//ms740012(v=vs.85)) interface containing the list of properties and values to set.

### `ppResults` [out]

Address of an **IPortableDeviceValues** interface that receives the list of properties that were successfully set. Each property has an associated **HRESULT** value, which indicates whether setting the property succeeded.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The request to set one or more of the specified properties failed. Inspect *ppResults* to determine which properties, if any, succeeded. |
| **E_POINTER** | NULL was passed in for ppResults. |

## Remarks

This method enables you to specify the values of one or more properties, such as the sensor make, model, and serial number, by making a single call.

Not all properties can be set.

**IPortableDeviceValues** is defined by the Windows Portable Devices API.

#### Examples

For an example of how to set properties, see [Setting and Retrieving Sensor Properties](https://learn.microsoft.com/windows/desktop/SensorsAPI/setting-and-retrieving-sensor-properties).

## See also

[GetProperties](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensor-getproperties)

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)