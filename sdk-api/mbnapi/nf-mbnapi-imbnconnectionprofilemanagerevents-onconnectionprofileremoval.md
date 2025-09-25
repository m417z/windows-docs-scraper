# IMbnConnectionProfileManagerEvents::OnConnectionProfileRemoval

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that indicates a connection profile has been removed from the system.

## Parameters

### `oldConnectionProfile` [in]

An [IMbnConnectionProfile](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofile) interface that represents a connection profile that has been removed.

## Return value

This method must return **S_OK**.

## See also

[IMbnConnectionProfileManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionprofilemanagerevents)