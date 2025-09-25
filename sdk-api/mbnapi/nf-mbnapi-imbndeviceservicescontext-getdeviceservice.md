# IMbnDeviceServicesContext::GetDeviceService

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the [IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice) object that can be used for communicating with a device service on the Mobile Broadband device.

## Parameters

### `deviceServiceID` [in]

The [deviceServiceID](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservice-get_deviceserviceid) of the Mobile Broadband device.

### `mbnDeviceService` [out, retval]

The [IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice) object.

## Return value

The method can return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **Other** | An error was encountered when executing this method. |

## Remarks

**GetDeviceService** may return an [IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice) object that already has a command or data session open. The calling process can check if the device service is already open.

## See also

[IMbnDeviceServicesContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicescontext)