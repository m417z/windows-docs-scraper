# IMbnConnectionManager::GetConnections

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets a list of available connections.

## Parameters

### `mbnConnections` [out]

An array of [IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection) interfaces representing connections that are associated with the devices. If this method returns anything other than **S_OK**, then this is **NULL**. Otherwise the calling application must free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The *mbnConnections* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Could not allocate the required memory. |

## See also

[IMbnConnectionManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionmanager)