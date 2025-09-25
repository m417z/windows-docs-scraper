# IPortableDeviceContent::Copy

## Description

The **Copy** method copies objects from one location on a device to another.

## Parameters

### `pObjectIDs`

A collection of object identifiers for the objects that this method will copy.

### `pszDestinationFolderObjectID`

An object identifier for the destination folder (or functional storage) into which this method will copy the specified objects.

### `ppResults` [out]

A collection of VT_ERROR values indicating the success or failure of copying a particular element. The first error value corresponds to the first object in the collection of object identifiers, the second to the second element, and so on. This argument can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The copy operation failed for at least one object. |
| **E_ACCESSDENIED** | The application does not have the rights to copy one of the specified objects. |

## Remarks

If the specified device supports copy operations to a functional storage, the *pszDestinationFolderObjectID* parameter may specify the identifier for a functional storage.

## See also

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)