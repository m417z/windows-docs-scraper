# OpenClusterNetInterfaceEx function

## Description

Opens a handle to a
[network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces).

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `lpszInterfaceName` [in, optional]

Pointer to a null-terminated Unicode string containing the name of the network interface to open.

### `dwDesiredAccess` [in]

The requested access privileges. This may be any combination of **GENERIC_READ**
(0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED**
(0x02000000). If this value is zero (0) and undefined error may be returned. Using
**GENERIC_ALL** is the same as calling
[OpenClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterface).

### `lpdwGrantedAccess` [out, optional]

Optional parameter that contains the address of a **DWORD** that will receive the
access rights granted. If the *DesiredAccess* parameter is
**MAXIMUM_ALLOWED** (0x02000000) then the **DWORD** pointed to by
this parameter will contain the maximum privileges granted to this user.

## Return value

If the operation was successful,
**OpenClusterNetInterfaceEx** returns an open
handle to the specified network interface.

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For more information about the error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. If the target server does not support the [OpenClusterNetInterfaceEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterfaceex) function (for example if the target server is running Windows Server 2008 or earlier) then the **GetLastError** function will return **RPC_S_PROCNUM_OUT_OF_RANGE** (1745). |

## See also

[CloseClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternetinterface)

[Network Interface Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interface-management-functions)

[OpenClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterface)