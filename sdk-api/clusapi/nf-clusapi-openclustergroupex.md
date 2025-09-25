# OpenClusterGroupEx function

## Description

Opens a failover cluster [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) and returns a handle to
it.

## Parameters

### `hCluster` [in]

Handle to a cluster that includes the group to open.

### `lpszGroupName` [in, optional]

Name of the group to open.

### `dwDesiredAccess` [in]

The requested access privileges. This may be any combination of **GENERIC_READ**
(0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED**
(0x02000000). If this value is zero (0) and undefined error may be returned. Using
**GENERIC_ALL** is the same as calling
[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup).

### `lpdwGrantedAccess` [out, optional]

Optional parameter that contains the address of a **DWORD** that will receive the
access rights granted. If the *DesiredAccess* parameter is
**MAXIMUM_ALLOWED** (0x02000000) then the **DWORD** pointed to by
this parameter will contain the maximum privileges granted to this user.

## Return value

If the operation was successful,
**OpenClusterGroupEx** returns a group handle.

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For more information about the error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. If the target server does not support the [OpenClusterGroupEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroupex) function (for example if the target server is running Windows Server 2008 or earlier) then the **GetLastError** function will return **RPC_S_PROCNUM_OUT_OF_RANGE** (1745). |

## See also

[CloseClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclustergroup)

[Group Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-management-functions)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)