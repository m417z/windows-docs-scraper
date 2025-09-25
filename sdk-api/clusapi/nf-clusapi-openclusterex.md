# OpenClusterEx function

## Description

Opens a connection to a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and returns a handle to it.

## Parameters

### `lpszClusterName` [in, optional]

Specifies one of the following values:

* Pointer to a null-terminated Unicode string containing the name of the cluster or one of the cluster
  [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) expressed as a NetBIOS name, a fully qualified DNS name, or
  an IP address. This produces an RPC cluster handle.
* **NULL**, which produces an LPC handle to the cluster to which the local computer
  belongs.

### `DesiredAccess` [in]

The requested access privileges. This may be any combination of **GENERIC_READ**
(0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED**
(0x02000000). If this value is zero (0) and undefined error may be returned. Using
**GENERIC_ALL** is the same as calling
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

### `GrantedAccess` [out, optional]

Optional parameter that contains the address of a **DWORD** that will receive the
access rights granted. If the *DesiredAccess* parameter is
**MAXIMUM_ALLOWED** (0x02000000) then the **DWORD** pointed to by
this parameter will contain the maximum privileges granted to this user.

## Return value

If the operation was successful, **OpenClusterEx** returns
a cluster handle.

| Return code/value | Description |
| --- | --- |
| **NULL**<br><br>0 | The operation was not successful. For more information about the error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. If the target server does not support the [OpenClusterEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterex) function (for example if the target server is running Windows Server 2008 or earlier) then the **GetLastError** function will return **RPC_S_PROCNUM_OUT_OF_RANGE** (1745). |

## Remarks

A cluster handle is a pointer to an internally defined structure which stores information about the RPC or LPC
connection to the cluster. Any object handles obtained from the cluster handle will be associated with the RPC or
LPC session data stored in the cluster structure. Combining RPC and LPC handles or using handles obtained from
different contexts can cause exceptions or other unpredictable results. For more information, see
[LPC and RPC Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/lpc-and-rpc-handles).

When finished with a cluster handle, it is important to call
[CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster) to ensure that all memory is freed and the
connection is shut down cleanly.