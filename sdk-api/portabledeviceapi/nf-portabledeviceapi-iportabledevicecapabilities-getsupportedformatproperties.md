# IPortableDeviceCapabilities::GetSupportedFormatProperties

## Description

The **GetSupportedFormatProperties** method retrieves the properties supported by objects of a specified format on the device.

## Parameters

### `Format` [in]

A **REFGUID** that specifies the format of the object. For a list of formats that are defined by Windows Portable Devices, see [Object Formats](https://learn.microsoft.com/windows/desktop/wpd_sdk/object-format-guids).

### `ppKeys` [out]

Address of a variable that receives a pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that contains the supported properties for the specified format. For a list of properties defined by Windows Portable Devices, see [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes). The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You can specify **WPD_OBJECT_FORMAT_ALL** for the *Format* parameter to retrieve the complete set of property attributes.

If an object does not have a value assigned to a specific property, or if the property was deleted, a device might not report the property at all when enumerating its properties. Another device might report the property, but with an empty string or a value of zero. In order to avoid this inconsistency, you can call this method to learn all the properties you can set on a specific object.

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)

[IPortableDeviceCapabilities::GetSupportedFormats](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecapabilities-getsupportedformats)