# IPortableDeviceResources::Delete

## Description

The **Delete** method deletes one or more resources from the object identified by the *pszObjectID* parameter.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that contains the object ID of the object.

### `pKeys` [in]

Pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that lists which resources to delete. You can find out what resources the object has by calling [GetSupportedResources](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceresources-getsupportedresources).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the arguments was a **NULL** pointer. |

## Remarks

An object can have several resources. For instance, an object may contain image data, thumbnail image data, and audio data.

An application can retrieve a list of supported resources by calling the [GetSupportedResources](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceresources-getsupportedresources) method.

## See also

[IPortableDeviceResources Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceresources)