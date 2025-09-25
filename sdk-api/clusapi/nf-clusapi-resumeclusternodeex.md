# ResumeClusterNodeEx function

## Description

Initiates the specified failback operation, and then requests that a paused node resumes cluster activity.

## Parameters

### `hNode` [in]

The handle to the paused node.

### `eResumeFailbackType` [in]

The type of failback operation to use when cluster activity resumes. The available failback types are specified in the [CLUSTER_NODE_RESUME_FAILBACK_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_node_resume_failback_type) enumeration.

### `dwResumeFlagsReserved` [in]

This parameter is reserved for future use.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[CLUSTER_NODE_RESUME_FAILBACK_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_node_resume_failback_type)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)