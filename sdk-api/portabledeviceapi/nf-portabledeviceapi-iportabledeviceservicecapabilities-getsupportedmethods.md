# IPortableDeviceServiceCapabilities::GetSupportedMethods

## Description

The **GetSupportedMethods** method retrieves the methods supported by the service.

## Parameters

### `ppMethods` [out]

The [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that receives the list of methods.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)

[Retrieving Supported Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-methods)