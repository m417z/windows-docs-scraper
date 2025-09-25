# IPortableDeviceServiceCapabilities::Cancel

## Description

The **Cancel** method cancels a pending operation.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

This method cancels all pending operations on the current service handle, which corresponds to a session associated with an [IPortableDeviceService](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice) interface. The Windows Portable Devices (WPD) API does not support targeted cancellation of specific operations.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)