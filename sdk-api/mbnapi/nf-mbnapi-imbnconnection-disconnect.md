# IMbnConnection::Disconnect

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Disconnects a data connection.

## Parameters

### `requestID` [out]

A pointer to a unique request ID assigned by the Mobile Broadband service to identify this asynchronous request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The connection has already been disconnected. |

## Remarks

Deactivation will also result in the disconnection of the L2 connection.

This is an asynchronous operation that will return immediately. If this method returns successfully, then the Mobile Broadband service will call the [OnDisconnectComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionevents-ondisconnectcomplete) method of [IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents) when the operation is complete.

Windows 8 and later versions of Windows: A Windows Store app may only use **Disconnect** if the existing MBN connection was initiated by that app using [Connect](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection). **Disconnect** may not be used to disconnect connections that have been made by the user or by the [Windows Connection Manager](https://learn.microsoft.com/windows/desktop/wcm/windows-connection-manager-portal).

## See also

[IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection)