# IMbnConnectionEvents::OnDisconnectComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that indicates that a disconnection operation has been performed.

## Parameters

### `newConnection` [in]

An [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) interface that represents the connection that has been disconnected.

### `requestID` [in]

The request ID assigned by the Mobile Broadband service to identify the disconnection operation.

### `status` [in]

The operation completion status. This can only be **S_OK**.

## Return value

This method must return **S_OK**.

## Remarks

An application can use [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) to get the current connection state.

## See also

[IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents)