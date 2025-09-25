# CLUSTER_REG_COMMAND enumeration

## Description

Enumerates the possible cluster registry commands that a local node will perform when attempting to join a cluster. It is used by the [CLUSTER_BATCH_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_batch_command) and [CLUSTER_READ_BATCH_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_read_batch_command) structures.

## Constants

### `CLUSREG_COMMAND_NONE:0`

This constant is not a valid command. It and the **CLUSREG_LAST_COMMAND** constant act as brackets that contain the valid commands.

### `CLUSREG_SET_VALUE:1`

This command sets a value relative to the last executed **CLUSREG_CREATE_KEY** command or (if not provided) relative to a key passed into the [ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch) function.

### `CLUSREG_CREATE_KEY`

This command will create a specified cluster registry key if it does not exist, or opens an existing one.

### `CLUSREG_DELETE_KEY`

This command will delete a key with all values and nested subkeys. No commands that operate on values can follow **CLUSREG_DELETE_KEY** until **CLUSREG_CREATE_KEY** is added.

### `CLUSREG_DELETE_VALUE`

This command deletes a value relative to the last executed **CLUSREG_CREATE_KEY** command or (if not provided) relative to a key passed into the [ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch) function.

### `CLUSREG_SET_KEY_SECURITY`

This command is reserved for future use.

### `CLUSREG_VALUE_DELETED`

This command is returned only through a batch update notification port. It indicates whether a specific cluster registry value has been deleted or whether the data of that cluster registry value has been changed.

### `CLUSREG_READ_KEY`

### `CLUSREG_READ_VALUE`

This command indicates that content was read successfully for the requested value.

### `CLUSREG_READ_ERROR`

This command indicates that a value was missing or another error occurred during read.

### `CLUSREG_CONTROL_COMMAND`

A control command.

**Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2012 R2.

### `CLUSREG_CONDITION_EXISTS`

A condition that indicates that a value exists.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2016.

### `CLUSREG_CONDITION_NOT_EXISTS`

A condition that indicates that a value does not exist.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2016.

### `CLUSREG_CONDITION_IS_EQUAL`

A condition that indicates that a value is equal to another.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2016.

### `CLUSREG_CONDITION_IS_NOT_EQUAL`

A condition that indicates that a value is not equal to another.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2016.

### `CLUSREG_CONDITION_IS_GREATER_THAN`

A condition that indicates that a value is greater than another.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2016.

### `CLUSREG_CONDITION_IS_LESS_THAN`

A condition that indicates that a value is less than another.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2016.

### `CLUSREG_CONDITION_KEY_EXISTS`

A condition that indicates that a key exists.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2016.

### `CLUSREG_CONDITION_KEY_NOT_EXISTS`

### `CLUSREG_LAST_COMMAND`

This constant is not a valid command. It and the **CLUSREG_COMMAND_NONE** constant act as brackets that contain the valid commands.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** The value of this constant is lower before Windows Server 2016.

#### - CLUSREG_CONDITION_IS_KEY_NOT_EXISTS

A condition that indicates that a key does not exist.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available before Windows Server 2016.

## Remarks

The **CLUSREG_VALUE_DELETED** command precedes every **CLUSREG_SET_VALUE** and **CLUSREG_DELETE_VALUE** command in the returned notification data, if the value had existing data.

## See also

[CLUSTER_BATCH_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_batch_command)

[CLUSTER_READ_BATCH_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_read_batch_command)

[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch)

[ClusterRegCreateReadBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatereadbatch)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)