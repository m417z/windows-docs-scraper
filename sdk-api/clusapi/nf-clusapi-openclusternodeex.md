# OpenClusterNodeEx function

## Description

Opens a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) and returns a handle to it.

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) returned from the
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster) or
[OpenClusterEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterex) functions.

### `lpszNodeName` [in, optional]

Pointer to the NetBIOS name of an existing node. If the DNS name of the node is used, the
**OpenClusterNodeEx** function will fail and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return
**ERROR_CLUSTER_NODE_NOT_FOUND**.

### `dwDesiredAccess` [in]

The requested access privileges. This may be any combination of **GENERIC_READ**
(0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED**
(0x02000000). If this value is zero (0) and undefined error may be returned. Using
**GENERIC_ALL** is the same as calling
[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode).

### `lpdwGrantedAccess` [out, optional]

Optional parameter that contains the address of a **DWORD** that will receive the
access rights granted. If the *DesiredAccess* parameter is
**MAXIMUM_ALLOWED** (0x02000000) then the **DWORD** pointed to by
this parameter will contain the maximum privileges granted to this user.

## Return value

If the operation was successful,
**OpenClusterNodeEx** returns a node handle.

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For more information about the error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. If the target server does not support the [OpenClusterNodeEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternodeex) function (for example if the target server is running Windows Server 2008 or earlier) then the **GetLastError** function will return **RPC_S_PROCNUM_OUT_OF_RANGE** (1745). |

## See also

[CloseClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternode)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterex)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)