# OpenClusterNetworkEx function

## Description

Opens a connection to a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) and returns a handle
to it.

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `lpszNetworkName` [in, optional]

Pointer to the name of an existing network.

### `dwDesiredAccess` [in]

The requested access privileges. This may be any combination of **GENERIC_READ**
(0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED**
(0x02000000). If this value is zero (0) and undefined error may be returned. Using
**GENERIC_ALL** is the same as calling
[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork).

### `lpdwGrantedAccess` [out, optional]

Optional parameter that contains the address of a **DWORD** that will receive the
access rights granted. If the *DesiredAccess* parameter is
**MAXIMUM_ALLOWED** (0x02000000) then the **DWORD** pointed to by
this parameter will contain the maximum privileges granted to this user.

## Return value

If the operation was successful,
**OpenClusterNetworkEx** returns a network
handle.

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For more information about the error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. If the target server does not support the [OpenClusterNetworkEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetworkex) function (for example if the target server is running Windows Server 2008 or earlier) then the **GetLastError** function will return **RPC_S_PROCNUM_OUT_OF_RANGE** (1745). |

## See also

[CloseClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternetwork)

[Failover Cluster Network Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-management-functions)

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)