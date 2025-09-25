# IMbnConnectionManagerEvents::OnConnectionArrival

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that indicates a new connection was added to the system.

## Parameters

### `newConnection` [in]

An [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) interface that represents the device added to the system.

## Return value

This method must return **S_OK**.

## See also

[IMbnConnectionManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionmanagerevents)