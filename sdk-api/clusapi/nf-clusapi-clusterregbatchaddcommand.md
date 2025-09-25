# ClusterRegBatchAddCommand function

## Description

Adds a command to a batch that will be executed on a cluster registry key. Additional calls
to the function will yield additional commands added to the batch. The batch was created by the
[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch) function and will be
either executed or ignored by the
[ClusterRegCloseBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosebatch) function.

## Parameters

### `hRegBatch` [in]

The handle of the batch to which a command will be added.

### `dwCommand` [in]

A command supported by this API that is taken from the
[CLUSTER_REG_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_reg_command) enumeration. The possible
commands are as follows.

#### CLUSREG_SET_VALUE (1)

Sets a value relative to the last executed **CLUSREG_CREATE_KEY** command or (if
not provided) relative to a key passed into the
[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch) function.

#### CLUSREG_CREATE_KEY (2)

Creates a specified cluster registry key if it does not exist, or opens an existing one.

#### CLUSREG_DELETE_KEY (3)

Deletes a key with all values and nested subkeys. No commands that operate on values can follow
**CLUSREG_DELETE_KEY** until **CLUSREG_CREATE_KEY** is
added.

#### CLUSREG_DELETE_VALUE (4)

Deletes a value relative to the last executed **CLUSREG_CREATE_KEY** command or
(if not provided) relative to a key passed into the
[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch) function.

### `wzName` [in, optional]

The name of the value or key relative to the command issued by the *dwCommand*
parameter.

### `dwOptions` [in]

If *dwCommand* takes the **CLUSREG_SET_VALUE** command, then
this parameter takes one of the standard
[registry value types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types). If not, then
*dwCommand* is set to 0.

### `lpData` [in, optional]

A pointer to the data relative to the command issued by *dwCommand*. The value of
this parameter is **NULL** for all but the **CLUSREG_SET_VALUE**
command.

### `cbData` [in]

The count, in bytes, of the data relative to the command issued by *dwCommand*. The
value of this parameter is 0 for all but the **CLUSREG_SET_VALUE** command.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_INVALID_FUNCTION**<br><br>1 | Incorrect function. This value is returned if *dwCommand* takes any command other than the commands described in the previous section. |
| **ERROR_INVALID_HANDLE**<br><br>6 | The handle is not valid. This value is returned if the *hRegBatch* parameter is **NULL**. |
| **ERROR_OUTOFMEMORY**<br><br>14 (0xE) | Not enough storage is available to complete this operation. |
| **ERROR_GEN_FAILURE**<br><br>31 (0x1F) | A device attached to the system is not functioning. |
| **ERROR_INVALID_PARAMETER**<br><br>87 (0x57) | The parameter is incorrect. This value will be returned if the cluster registry key that the batch is attempting to execute commands on is not the current key. |

## Remarks

The **PCLUSTER_REG_BATCH_ADD_COMMAND** type defines a pointer to this function.

## See also

[CLUSTER_REG_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_reg_command)

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegCloseBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosebatch)

[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch)

[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types)