# IPortableDevice::Content

## Description

The **Content** method retrieves an interface that you can use to access objects on a device.

## Parameters

### `ppContent` [out]

Address of a variable that receives a pointer to an [IPortableDeviceContent](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent) interface that is used to access the content on a device. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppContent* argument was a NULL pointer. |

## See also

[Adding a Resource to an Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/adding-a-resource-to-an-object)

[Enumerating Content](https://learn.microsoft.com/windows/desktop/wpd_sdk/enumerating-content)

[IPortableDevice Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice)

[Moving Content on the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/moving-content-on-the-device)

[Retrieving Properties for Multiple Objects](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-properties-for-multiple-objects)

[Retrieving an Object Identifier from a Persistent Unique Identifier](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-an-object-identifier-from-a-persistent-unique-identifier)

[Retrieving the Rendering Capabilities Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-rendering-capabilities-supported-by-a-device)

[Setting Properties for Multiple Objects](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-multiple-objects)

[Setting Properties for a Single Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-a-single-object)