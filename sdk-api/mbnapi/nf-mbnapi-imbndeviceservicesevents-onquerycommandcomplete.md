# IMbnDeviceServicesEvents::OnQueryCommandComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method indicating that a device service **QUERY** request has completed.

## Parameters

### `deviceService` [in]

The [IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice) object on which the operation was requested.

### `responseID` [in]

A identifier for the response.

### `deviceServiceData` [in]

A byte array containing the data returned by the device. If the response is fragmented across multiple indications, this only contains the information for one fragment. This field is valid only if the status is **S_OK**.

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

The *deviceServiceData* byte array contains the byte-by-byte copy of data returned by the device. The Mobile Broadband service will free the memory after the function call returns. If an application wants to use this data then it should copy the contents in its own memory.

## See also

[IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents)