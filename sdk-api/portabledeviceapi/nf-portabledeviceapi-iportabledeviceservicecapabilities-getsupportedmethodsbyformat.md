# IPortableDeviceServiceCapabilities::GetSupportedMethodsByFormat

## Description

The **GetSupportedMethodsByFormat** method retrieves the methods supported by the service for the specified format.

## Parameters

### `Format` [in]

The format whose supported methods are retrieved.

### `ppMethods` [out]

The [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that receives the list of methods.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)