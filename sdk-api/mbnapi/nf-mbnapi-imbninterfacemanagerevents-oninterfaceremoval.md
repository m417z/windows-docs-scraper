# IMbnInterfaceManagerEvents::OnInterfaceRemoval

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that signals that a device has been removed from the system.

## Parameters

### `oldInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents the device that was removed.

## Return value

This method must return **S_OK**.

## See also

[IMbnInterfaceManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfacemanagerevents)