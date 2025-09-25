# IMbnDeviceService::OpenDataSession

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Open a data session to the device service on a Mobile Broadband device.

## Parameters

### `requestID` [out]

A unique request ID assigned by the Mobile Broadband service to identify this request.

## Return value

The method can return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_ACCESSDENIED** | This device service command is not allowed for calling process privileges. |
| **HRESULT_FROM_WIN32(ERROR_TOO_MANY_SESS)** | The device service has reached the maximum number of sessions it can support |
| **Other** | An error was encountered when executing this method. |

## Remarks

**OpenDataSession** allows an application to open a data session to the mobile broadband device service.

This is an asynchronous operation and **OpenDataSession** will return immediately. On completion of the operation, the Mobile Broadband service will call the [OnOpenDataSessionComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservicesevents-onopendatasessioncomplete) method of the [IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents) interface.

## See also

[IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice)