# IPortableDeviceContent::Move

## Description

The **Move** method moves one or more objects from one location on the device to another.

## Parameters

### `pObjectIDs` [in]

Pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that holds one or more null-terminated strings (type VT_LPWSTR) specifying the object IDs of the objects to be moved.

### `pszDestinationFolderObjectID` [in]

Pointer to a null-terminated string that specifies the ID of the destination.

### `ppResults` [in, out]

Optional. On return, this parameter contains a collection of VT_ERROR values indicating the success or failure of the operation. The first element returned in *ppResults* corresponds to the first object in the *pObjectIDs* collection, the second element returned in *ppResults* corresponds to the second object in the *pObjectIDs* collection, and so on. This parameter can be **NULL** if the application is not concerned with the results.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table. If any error value is returned, no objects were deleted on the device.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | One or more objects were deleted, but at least one object could not be deleted. See *ppFailedObjectIDs* to learn which objects were not be deleted. |
| **E_ACCESSDENIED** | The application does not have the rights to move the object. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## Remarks

If the specified device supports move operations on a functional storage, the *pszDestinationFolderObjectID* parameter may specify the identifier for a functional storage.

#### Examples

For an example of how to use this method, see [Moving Content on the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/moving-content-on-the-device).

## See also

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)

[Moving Content on the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/moving-content-on-the-device)