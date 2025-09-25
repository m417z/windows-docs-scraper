# IMbnInterfaceEvents::OnEmergencyModeChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate that the emergency mode has changed.

## Parameters

### `newInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents the device whose emergency mode has changed.

## Return value

This method must return **S_OK**.

## Remarks

An application can call the [InEmergencyMode](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-inemergencymode) method of the passed [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) to get the new emergency mode of the device.

## See also

[IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents)