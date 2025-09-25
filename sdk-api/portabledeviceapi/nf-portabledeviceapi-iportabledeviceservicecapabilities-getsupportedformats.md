# IPortableDeviceServiceCapabilities::GetSupportedFormats

## Description

The **GetSupportedFormats** method retrieves the formats supported by the service.

## Parameters

### `ppFormats` [out]

The [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that receives the list of formats.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)

[Retrieving Supported Service Formats](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-formats)