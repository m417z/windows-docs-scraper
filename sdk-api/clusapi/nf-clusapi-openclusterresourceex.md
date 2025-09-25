# OpenClusterResourceEx function

## Description

Opens a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) and returns a handle to
it.

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `lpszResourceName` [in, optional]

Pointer to a null-terminated Unicode string containing the name of the resource to be opened.

Resource names are not case sensitive. A resource name must be unique within the cluster. The name is set
when the resource is created and can be changed using the
[SetClusterResourceName](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterresourcename) function.

### `dwDesiredAccess` [in]

The requested access privileges. This may be any combination of **GENERIC_READ**
(0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED**
(0x02000000). If this value is zero (0) and undefined error may be returned. Using
**GENERIC_ALL** is the same as calling
[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource).

### `lpdwGrantedAccess` [out, optional]

Optional parameter that contains the address of a **DWORD** that will receive the
access rights granted. If the *DesiredAccess* parameter is
**MAXIMUM_ALLOWED** (0x02000000) then the **DWORD** pointed to by
this parameter will contain the maximum privileges granted to this user.

## Return value

If the operation was successful,
**OpenClusterResourceEx** returns a handle to the
opened resource.

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For more information about the error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. If the target server does not support the [OpenClusterResourceEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresourceex) function (for example if the target server is running Windows Server 2008 or earlier) then the **GetLastError** function will return **RPC_S_PROCNUM_OUT_OF_RANGE** (1745). |

## See also

[CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource)

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)