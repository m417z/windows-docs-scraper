# IPortableDeviceCapabilities::GetFunctionalCategories

## Description

The **GetFunctionalCategories** method retrieves all functional categories supported by the device.

## Parameters

### `ppCategories` [out]

Address of a variable that receives a pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that holds all the functional categories for this device. The values will be **GUID**s of type VT_CLSID in the retrieved **PROPVARIANT** values. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Functional categories describe the types of functions that a device can perform, such as image capture, audio capture, and storage. This method is typically very fast, because the driver usually queries the device only on startup and caches the results.

#### Examples

For an example of how to use this method see [Retrieving the Functional Categories Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-functional-categories-supported-by-a-device).

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)

[Retrieving the Functional Categories Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-functional-categories-supported-by-a-device)