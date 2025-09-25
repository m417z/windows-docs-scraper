# IMbnDeviceServicesEvents::OnWriteDataComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method indicating that a device service session **Write** request has completed.

## Parameters

### `deviceService` [in]

The [IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice) session object on which the **Write** was requested.

### `status` [in]

A status code that indicates the outcome of the operation.

### `requestID` [in]

The request ID that was assigned by the Mobile Broadband service to the **Write** request.

## Return value

The method must return the following value.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## See also

[IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents)