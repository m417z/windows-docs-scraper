# IPortableDeviceContent::Properties

## Description

The **Properties** method retrieves the interface that is required to get or set properties on an object on the device.

## Parameters

### `ppProperties` [out]

Address of a variable that receives a pointer to an [IPortableDeviceProperties](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceproperties) interface that is used to get or set object properties. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## Remarks

The retrieved interface is not specific to a particular object on the device; it is specific only to the device. You must specify the ID of the object you want when requesting or setting properties.

#### Examples

For an example of how to use this method, see [Setting Properties for a Single Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-a-single-object).

## See also

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)

[Retrieving Content-Object Properties](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-content-object-properties)

[Retrieving Properties for Multiple Objects](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-properties-for-multiple-objects)

[Retrieving the Rendering Capabilities Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-rendering-capabilities-supported-by-a-device)

[Setting Properties for Multiple Objects](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-multiple-objects)

[Setting Properties for a Single Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/setting-properties-for-a-single-object)

[Transferring Content from the Device to a PC](https://learn.microsoft.com/windows/desktop/wpd_sdk/transferring-content-from-the-device-to-a-pc)

[Writing Content-Object Properties](https://learn.microsoft.com/windows/desktop/wpd_sdk/writing-content-object-properties)