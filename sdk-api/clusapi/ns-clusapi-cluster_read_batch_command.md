# CLUSTER_READ_BATCH_COMMAND structure

## Description

Represents a result for a single command in a read batch.

## Members

### `Command`

The command result status, which can be one of these values.

#### CLUSREG_READ_VALUE (8)

The result structure has content for the requested value. The **dwOptions** member is set to the registry value type.

#### CLUSREG_READ_ERROR (9)

The value was missing, or another error occurred during read. The **dwOptions** member contains the actual error type.

### `dwOptions`

The registry value type or the read error type, depending on the *Command* result.

### `wzSubkeyName`

The name of the key requested in the read command.

### `wzValueName`

The name of the value requested in the read command.

### `lpData`

A pointer to value data.

### `cbData`

The count, in bytes, of the *lpData* value data.

## Remarks

The pointers in the **CLUSTER_READ_BATCH_COMMAND** structure are valid until the read batch result handle is closed by the [ClusterRegCloseReadBatchReply](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatchreply) function.

Errors from read commands are independent from each other.

## See also

[ClusterRegCloseReadBatchReply](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatchreply)

[ClusterRegReadBatchReplyNextCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregreadbatchreplynextcommand)