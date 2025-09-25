# RESDLL_CONTEXT_OPERATION_TYPE enumeration

## Description

Specifies the various types of context operations for the [GET_OPERATION_CONTEXT_PARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-get_operation_context_params) structure.

## Constants

### `ResdllContextOperationTypeFailback`

A group fail back.

### `ResdllContextOperationTypeDrain`

A node drain.

### `ResdllContextOperationTypeDrainFailure`

A node drain failure.

### `ResdllContextOperationTypeEmbeddedFailure`

An embedded failure.

### `ResdllContextOperationTypePreemption`

A preemption failure.

### `ResdllContextOperationTypeNetworkDisconnect`

A network connection failure.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

### `ResdllContextOperationTypeNetworkDisconnectMoveRetry`

A network connection was disconnected and it is being re-established.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)