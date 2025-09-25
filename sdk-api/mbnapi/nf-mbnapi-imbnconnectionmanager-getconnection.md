# IMbnConnectionManager::GetConnection

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets a connection.

## Parameters

### `connectionID` [in]

A string containing the connection ID.

### `mbnConnection` [out, retval]

A pointer to an [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) interface that represents the requested connection. If the method returns anything other than S_OK, then this is **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The *mbnConnection* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Could not allocate the required memory. |

## See also

[IMbnConnectionManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionmanager)