# IPortableDeviceResources::GetSupportedResources

## Description

The **GetSupportedResources** method retrieves a list of resources that are supported by a specific object.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that contains the ID of the object.

### `ppKeys` [out]

Address of a variable that receives a pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that holds a collection of **PROPERTYKEY** values specifying resource types supported by this object type. If the object cannot hold resources, this will be an empty collection. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required pointer arguments was **NULL**. |

## Remarks

The list of resources returned by this method includes all resources that the object *can* support. This does not mean that all the listed resources actually have data, but that the object is capable of supporting each listed resource.

## See also

[IPortableDeviceResources Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceresources)