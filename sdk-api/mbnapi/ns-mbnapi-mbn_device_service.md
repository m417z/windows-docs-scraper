# MBN_DEVICE_SERVICE structure

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_DEVICE_SERVICE** structure provides information about a Mobile Broadband device service

## Members

### `deviceServiceID`

A string that represents the unique ID of a Mobile Broadband device service. This matches the Device Service UUID reported by the Mobile Broadband device.

### `dataWriteSupported`

if **TRUE**, this device service supports write on bulk data sessions. Otherwise, **FALSE**.

### `dataReadSupported`

if **TRUE**, this device service supports read on bulk data sessions. Otherwise, **FALSE**.

## See also

[EnumerateDeviceServices](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservicescontext-enumeratedeviceservices)