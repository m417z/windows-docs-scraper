# IPortableDeviceProperties::GetPropertyAttributes

## Description

The **GetPropertyAttributes** method retrieves attributes of a specified object property on a device.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that contains the object ID of the object to query. To specify the device, use **WPD_DEVICE_OBJECT_ID**.

### `Key` [in]

A **REFPROPERTYKEY** that specifies the property to query for. You can retrieve a list of supported properties by calling [GetSupportedProperties](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-getsupportedproperties). For a list of properties that are defined by Windows Portable Devices, see [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes).

### `ppAttributes` [out]

Address of a variable that receives a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that holds the retrieved property attributes. These are PROPERTYKEY/value pairs, where the **PROPERTYKEY** is the property, and the value data type depends on the specific property. The caller must release this interface when it is done with it. Attributes defined by Windows Portable Devices can be found on the [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes) page.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded, and all attributes were retrieved successfully. |
| **S_FALSE** | Only some attribute values could be retrieved. Others could not, and will contain an **HRESULT** value of type VT_ERROR. |
| **E_POINTER** | A required pointer argument was **NULL**. |

## Remarks

Property attributes describe a property's access rights, valid values, and other information. For example, a property can have a WPD_PROPERTY_ATTRIBUTE_CAN_DELETE value set to False to prevent deletion, and have a range of valid values stored as individual entries.

#### Examples

For an example of how to use this method, see [Setting Properties for a Single Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-a-single-object).

## See also

[IPortableDeviceProperties Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceproperties)

[Setting Properties for a Single Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-a-single-object)

[Writing Content-Object Properties](https://learn.microsoft.com/windows/desktop/wpd_sdk/writing-content-object-properties)