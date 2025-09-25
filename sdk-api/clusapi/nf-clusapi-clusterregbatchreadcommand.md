# ClusterRegBatchReadCommand function

## Description

Reads a command from a batch notification.

## Parameters

### `hBatchNotification` [in]

A handle to the batch notification.

### `pBatchCommand` [out]

Pointer to a [CLUSTER_BATCH_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_batch_command) structure
that will be filled with information about the command on successful return.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **PCLUSTER_REG_GET_BATCH_NOTIFICATION** type defines a pointer to this
function.

## See also

[CLUSTER_BATCH_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_batch_command)

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)