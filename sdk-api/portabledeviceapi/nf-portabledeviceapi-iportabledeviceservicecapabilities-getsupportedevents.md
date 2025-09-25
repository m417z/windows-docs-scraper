# IPortableDeviceServiceCapabilities::GetSupportedEvents

## Description

The **GetSupportedEvents** method retrieves the events supported by the service.

## Parameters

### `ppEvents` [out]

The [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that receives the list of events.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)