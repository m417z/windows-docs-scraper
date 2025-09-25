# IPortableDeviceCapabilities::GetFixedPropertyAttributes

## Description

The **GetFixedPropertyAttributes** method retrieves the standard property attributes for a specified property and format. Standard attributes are those that have the same value for all objects of the same format. For example, one device might not allow users to modify video file names; this device would return **WPD_PROPERTY_ATTRIBUTE_CAN_WRITE** with a value of False for WMV formatted objects. Attributes that can have different values for a format, or optional attributes, are not returned.

## Parameters

### `Format` [in]

A **REFGUID** that specifies the format of the objects of interest. For format **GUID** values, see [Object Formats](https://learn.microsoft.com/windows/desktop/wpd_sdk/object-format-guids).

### `Key` [in]

A **REFPROPERTYKEY** that specifies the property that you want to know the attributes of. Properties defined by Windows Portable Devices are listed in [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes).

### `ppAttributes` [out]

Address of a variable that receives a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that holds the attributes and their values. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You can specify **WPD_OBJECT_FORMAT_ALL** for the *Format* parameter to retrieve the complete set of property attributes.

Attributes describe properties. Example attributes are **WPD_PROPERTY_ATTRIBUTE_CAN_READ** and **WPD_PROPERTY_ATTRIBUTE_CAN_WRITE**. This method does not retrieve resource attributes.

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)

[IPortableDeviceProperties::GetPropertyAttributes](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-getpropertyattributes)