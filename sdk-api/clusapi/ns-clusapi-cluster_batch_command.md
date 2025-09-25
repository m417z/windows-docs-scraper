# CLUSTER_BATCH_COMMAND structure

## Description

Represents the order in which current batch command data is sent to the
[ClusterRegBatchReadCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchreadcommand)
function. Values in the
**CLUSTER_BATCH_COMMAND** structure are identical to
parameters passed to the
[ClusterRegBatchAddCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchaddcommand) function. The only
difference is that for **CLUSREG_DELETE_VALUE**, the **dwOptions**,
**lpData**, and **cbData** members are set to the value being
deleted, similar to the **CLUSREG_SET_VALUE** command.

## Members

### `Command`

A command that is supported by this API and taken from the
[CLUSTER_REG_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_reg_command) enumeration. The possible
commands are as follows.

#### CLUSREG_SET_VALUE (1)

Sets a value relative to the last executed **CLUSREG_CREATE_KEY** command or (if not
provided) relative to a key passed into the
[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch) function.

#### CLUSREG_CREATE_KEY (2)

Creates a specified cluster registry key if it does not exist, or opens an existing one.

#### CLUSREG_DELETE_KEY (3)

Deletes a key with all values and nested subkeys. No commands that operate on values can follow
**CLUSREG_DELETE_KEY** until **CLUS_REG_CREATE_KEY** is
added.

#### CLUSREG_DELETE_VALUE (4)

Deletes a value relative to the last executed **CLUSREG_CREATE_KEY** command or (if
not provided) relative to a key passed into the
[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch) function.

#### CLUSREG_VALUE_DELETED (6)

Indicates whether a specific cluster registry value has been deleted or if the data of that cluster
registry value has been changed. This command is returned only through a batch update notification port.

### `dwOptions`

If the **Command** member takes either the
**CLUSREG_SET_VALUE** command or the **CLUSREG_DELETE_VALUE**
command, then this member takes one of the standard
[registry value types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types). If not, then
**Command** is set to 0.

### `wzName`

The name of the value or key relative to the command issued by **Command**.

### `lpData`

A pointer to the data relative to the command issued by **Command**. The value of this
member is **NULL** for all the commands except the
**CLUSREG_SET_VALUE** and **CLUSREG_DELETE_VALUE**
commands.

### `cbData`

The count, in bytes, of the data relative to the command issued by **Command**. The
value of this member is 0 for all the commands except the **CLUSREG_SET_VALUE** and
**CLUSREG_DELETE_VALUE** commands.

## Remarks

The **wzName** and **lpData** pointers are valid until the batch
notification is closed via the
[ClusterRegBatchCloseNotification](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchclosenotification)
function.

## See also

[CLUSTER_REG_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_reg_command)

[ClusterRegBatchAddCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchaddcommand)

[ClusterRegBatchCloseNotification](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchclosenotification)

[ClusterRegBatchReadCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchreadcommand)

[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch)

[Failover Cluster Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-structures)