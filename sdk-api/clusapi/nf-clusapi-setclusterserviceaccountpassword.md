# SetClusterServiceAccountPassword function

## Description

[This function is available for use in the operating systems specified in the
Requirements section. Support for this function was removed in Windows Server 2008 and this function does
nothing and returns **ERROR_CALL_NOT_IMPLEMENTED**.]

Changes the password for the Cluster service user account on all available cluster
nodes. The **PCLUSAPI_SET_CLUSTER_SERVICE_ACCOUNT_PASSWORD** type defines a pointer to this function.

## Parameters

### `lpszClusterName` [in]

**NULL**-terminated Unicode string specifying the name of the cluster.

### `lpszNewPassword` [in]

**NULL**-terminated Unicode string specifying the new password for the Cluster service
user account.

### `dwFlags` [in, optional]

Optional bitfield of values enumerated from the
[CLUSTER_SET_PASSWORD_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc512182(v=vs.85)) enumeration
containing flags that describe how the password update is to be applied to the cluster.

By default (*dwFlags* = 0), the function will not proceed unless all cluster nodes
are available.

#### CLUSTER_SET_PASSWORD_IGNORE_DOWN_NODES (1 (0x1))

Causes the
**SetClusterServiceAccountPassword**
function to proceed even if all nodes are not available. The function will attempt to change the password on
as many nodes as it can, but any nodes not in the **ClusterNodeUp** or
**ClusterNodePaused** states (see
[GetClusterNodeState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodestate)) will not be updated.

### `lpReturnStatusBuffer` [out]

Pointer to an output buffer that receives an array of
[CLUSTER_SET_PASSWORD_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-cluster_set_password_status) structures
describing the result of the password update for each cluster node. If this parameter is not
**NULL** and the buffer is not large enough to hold the resulting data, the function
returns **ERROR_MORE_DATA** and sets *lpcbReturnStatusBufferSize*
to the required size for the output buffer. If this parameter is **NULL**, no password
update will be performed; the function will set *lpcbReturnStatusBufferSize* to the
required buffer size and return **ERROR_SUCCESS**.

### `lpcbReturnStatusBufferSize` [in, out]

On input, pointer to a value specifying the size (in bytes) of the output buffer. On output, pointer to a
value specifying the actual size (in bytes) of the resulting data. The output size is always specified, even if
*lpReturnStatusBuffer* is **NULL**. This parameter cannot be
**NULL**.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error
codes.

| Return code/value | Description |
| --- | --- |
| **ERROR_ALL_NODES_NOT_AVAILABLE**<br><br>5037 (0x13AD) | Some nodes in the cluster are unavailable (that is, not in the **ClusterNodeStateUp** or **ClusterNodeStatePaused** states) and the **CLUSTER_SET_PASSWORD_IGNORE_DOWN_NODES** flag is not set. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The output buffer pointed to by *lpReturnStatusBuffer* was not large enough to hold the resulting data. |

## Remarks

By default, the
**SetClusterServiceAccountPassword**
function does nothing unless all nodes in the cluster are available (that is, in the
**ClusterNodeStateUp** or **ClusterNodeStatePaused** states). You
can use the **CLUSTER_SET_PASSWORD_IGNORE_DOWN_NODES** flag to override this behavior,
but note that any node that fails to update the password will be unable to join the cluster until the password is
manually updated on that node.

If the new password is the same as the old password on a node, the password update is not applied to that node
and **ERROR_SUCCESS** is returned.

This function does not update the password stored by the domain controllers for the Cluster service user
account.

Do not call
**SetClusterServiceAccountPassword**
from a resource DLL.

## See also

[CLUSTER_SET_PASSWORD_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc512182(v=vs.85))

[CLUSTER_SET_PASSWORD_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-cluster_set_password_status)

[Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)