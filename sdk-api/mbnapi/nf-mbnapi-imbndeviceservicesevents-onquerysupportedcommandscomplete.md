# IMbnDeviceServicesEvents::OnQuerySupportedCommandsComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method indicating that a query for the messages supported on a device service has completed.

## Parameters

### `deviceService` [in]

The [IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice) object on which the query was requested.

### `commandIDList` [in]

An array that contains the list of command IDs supported by the device service. This field is valid only if the status is **S_OK**.

### `status` [in]

A status code that indicates the outcome of the operation.

### `requestID` [in]

The request ID that was assigned by the Mobile Broadband service to the query operation request.

## Return value

The method must return the following value.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

The Mobile Broadband service will free the memory for *commandIDList* after the function call returns. If an application wants to use this data then it should copy the contents in its own memory.

## See also

[IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents)