# IPortableDeviceService::Cancel

## Description

The **Cancel** method cancels a pending operation on this interface.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

This method cancels all pending operations on the current device handle, which corresponds to a session associated with an [IPortableDeviceService](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice) interface. The Windows Portable Devices (WPD) API does not support targeted cancellation of specific operations.

If your application invokes the WPD API from multiple threads, each thread should create a new instance of the [IPortableDeviceService](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice) interface. Doing this ensures that any cancel operation affects only the I/O for the affected thread.

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)