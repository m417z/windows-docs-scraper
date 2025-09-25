# IPortableDeviceService::Close

## Description

The **Close** method releases the connection to the service.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

Applications typically won't call this method, as the Windows Portable Devices (WPD) API automatically calls it when the last reference to a service is removed.

When an application does call this method, the WPD API releases the service connection, so that any WPD objects attached to the service will return the **E_WPD_SERVICE_NOT_OPEN** error.

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)