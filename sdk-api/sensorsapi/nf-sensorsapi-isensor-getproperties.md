# ISensor::GetProperties

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves multiple sensor properties.

## Parameters

### `pKeys` [in]

Pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/previous-versions//ms739549(v=vs.85)) interface containing the **PROPERTYKEY** collection for the property values being requested. Set to **NULL** to retrieve all supported properties.

### `ppProperties` [out]

Address of an [IPortableDeviceValues](https://learn.microsoft.com/previous-versions//ms740012(v=vs.85)) pointer that receives the pointer to the requested property values.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The sensor driver does not support at least one of the specified properties. Each unsupported property **PROPVARIANT** returned through the [IPortableDeviceValues](https://learn.microsoft.com/previous-versions//ms740012(v=vs.85)) interface will have its error value set to **HRESULT_FROM_WIN32 (ERROR_NOT_FOUND)**. |
| **E_POINTER** | NULL was passed in for ppProperties. |

## Remarks

This method enables you to retrieve the values of multiple properties, such as the sensor make, model, and serial number, by making a single call. To retrieve a single property, call [ISensor::GetProperty](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensor-getproperty).

The **IPortableDeviceKeyCollection** and **IPortableDeviceValues** interfaces are defined by the Windows Portable Devices API.

#### Examples

For an example of how to retrieve properties from a sensor, see [Setting and Retrieving Sensor Properties](https://learn.microsoft.com/windows/desktop/SensorsAPI/setting-and-retrieving-sensor-properties).

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)

[Sensor Properties](https://learn.microsoft.com/windows/desktop/SensorsAPI/sensor-properties)

[SetProperties](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensor-setproperties)