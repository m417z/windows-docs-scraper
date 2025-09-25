# IPortableDeviceProperties::SetValues

## Description

The **SetValues** method adds or modifies one or more properties on a specified object on a device.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that contains the object ID of the object to modify. To specify the device, use WPD_DEVICE_OBJECT_ID.

### `pValues` [in]

Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that contains one or more property/value pairs to set. Existing values will be overwritten.

### `ppResults` [out]

Address of a variable that receives a pointer to an **IPortableDeviceValues** interface that contains a collection of property/HRESULT values. Each value (type VT_ERROR) describes the success or failure of the property set attempt. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | All specified property values were updated. |
| **S_FALSE** | One or more properties could not be modified. Those that could not will have an **HRESULT** of type VT_ERROR in the retrieved *ppResults* parameter. |

## Remarks

To delete a property, call [IPortableDeviceProperties::Delete](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-delete). A property can be deleted only if its WPD_PROPERTY_ATTRIBUTE_CAN_WRITE attribute is True. This attribute can be retrieved by calling [GetPropertyAttributes](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-getpropertyattributes).

#### Examples

For an example of how to use this method, see [Setting Properties for a Single Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-a-single-object).

## See also

[IPortableDeviceProperties Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceproperties)

[IPortableDeviceProperties::Delete](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-delete)

[IPortableDeviceProperties::GetValues](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-getvalues)

[Setting Properties for a Single Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-a-single-object)

[Writing Content-Object Properties](https://learn.microsoft.com/windows/desktop/wpd_sdk/writing-content-object-properties)