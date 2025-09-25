# IPortableDeviceProperties::Delete

## Description

The **Delete** method deletes specified properties from a specified object on a device.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that specifies the ID of the object whose properties you will delete. To specify the device, use **WPD_DEVICE_OBJECT_ID**.

### `pKeys` [in]

Pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that specifies which properties to delete. For a list of properties defined by Windows Portable Devices, see [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | One or more property values could not be deleted. |
| **E_POINTER** | The required pointer argument was **NULL**. |

## Remarks

Properties can be deleted only if their WPD_PROPERTY_ATTRIBUTE_CAN_DELETE attribute is True. This attribute can be retrieved by calling [GetPropertyAttributes](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-getpropertyattributes).

The driver has no way to indicate partial success; that is, if only some properties could be deleted, the driver will return **S_FALSE**, but this method does not indicate which properties were successfully deleted. The only way to learn which properties were deleted is to request all properties by calling [IPortableDeviceProperties::GetValues](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-getvalues).

## See also

[IPortableDeviceProperties Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceproperties)