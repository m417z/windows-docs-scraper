# IPortableDeviceContent::Delete

## Description

The **Delete** method deletes one or more objects from the device.

## Parameters

### `dwOptions` [in]

One of the [DELETE_OBJECT_OPTIONS](https://learn.microsoft.com/windows/desktop/wpd_sdk/delete-object-options) enumerators.

### `pObjectIDs` [in]

Pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that holds one or more null-terminated strings (type VT_LPWSTR) specifying the object IDs of the objects to delete.

### `ppResults` [in, out]

Optional. On return, this parameter contains a collection of VT_ERROR values indicating the success or failure of the operation. The first element returned in *ppResults* corresponds to the first object in the *pObjectIDs* collection, the second element returned in *ppResults* corresponds to the second object in the *pObjectIDs* collection, and so on. This parameter can be **NULL** if the application is not concerned with the results.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table. If any error value is returned, no objects were deleted on the device.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | At least one object could not be deleted. The *ppResults* parameter, if specified, contains the per-object error code. |
| **E_XXXXXXXX** | The driver did not delete any objects. |
| **E_INVALIDARG** | An invalid value was specified for *dwOptions*. |
| **E_ACCESSDENIED** | The application does not have permission to delete the object. |
| **HRESULT_FROM_WIN32(ERROR_DIR_NOT_EMPTY)** | The specified folder or directory could not be deleted because it was not empty. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_OPERATION)** | The application specified PORTABLE_DEVICE_DELETE_NO_RECURSION, and the object has children. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The object could not be deleted because it does not exist on the device. |

## Remarks

To see if recursive deletion is supported, call [IPortableDeviceCapabilities::GetCommandOptions](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecapabilities-getcommandoptions). If the retrieved [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface contains a property value called WPD_OPTION_OBJECT_MANAGEMENT_RECURSIVE_DELETE_SUPPORTED with a *boolVal* value of True, the device supports recursive deletion.

The following table lists the possible return codes that may appear in the collection at which *ppResults* points.

#### Examples

For an example of how to use this method, see [Deleting Content from the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/deleting-content-from-the-device).

## See also

[Deleting Content from the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/deleting-content-from-the-device)

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)