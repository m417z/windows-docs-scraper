# IMbnDeviceServicesEvents::OnEventNotification

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method signaling a device service state change event from the Mobile Broadband device.

## Parameters

### `deviceService` [in]

The [IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice) object for which the event notification was received.

### `eventID` [in]

An identifier for the event.

### `deviceServiceData` [in]

A byte array containing the data returned by underlying device.

## Return value

The method must return the following value.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

The *deviceServiceData* byte array contains the byte-by-byte copy of data returned by the device. The Mobile Broadband service will free the memory after the function call returns. If an application wants to use this data then it should copy the contents in its own memory.

## See also

[IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents)