# IMbnConnectionEvents::OnConnectStateChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that indicates whether the connection state of the device has changed.

## Parameters

### `newConnection` [in]

An [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) interface that represents the connection on which the state has changed due to a system or network initiated change.

## Return value

This method must return **S_OK**.

## Remarks

An application can use [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) to get the updated connection state.

## See also

[IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents)