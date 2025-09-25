# IPortableDeviceContent::Transfer

## Description

The [Transfer](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecontent-move) method retrieves an interface that is used to read from or write to the content data of an existing object resource.

## Parameters

### `ppResources` [out]

Address of a variable that receives a pointer to an [IPortableDeviceResources](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceresources) interface that is used to modify an object's resources. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## Remarks

This method is typically used to read from an existing object.

#### Examples

For an example of how to use this method, see [Adding a Resource to an Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/adding-a-resource-to-an-object).

## See also

[Adding a Resource to an Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/adding-a-resource-to-an-object)

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)