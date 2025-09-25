# IPortableDevice::Capabilities

## Description

The **Capabilities** method retrieves an interface used to query the capabilities of a portable device.

## Parameters

### `ppCapabilities` [out]

Address of a variable that receives a pointer to an [IPortableDeviceCapabilities](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities) interface that can describe the device's capabilities. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppCapabilities* argument was a **NULL** pointer. |

## See also

[IPortableDevice Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice)

[Retrieving the Functional Categories Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-functional-categories-supported-by-a-device)

[Retrieving the Rendering Capabilities Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-rendering-capabilities-supported-by-a-device)