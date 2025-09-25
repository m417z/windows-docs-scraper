# CLUSTER_NODE_STATE enumeration

## Description

Describes the state of a cluster node. The
[GetClusterNodeState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodestate) and
[State](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusnode-state) properties use this enumeration.

## Constants

### `ClusterNodeStateUnknown:-1`

The operation was not successful. For more information about the error, call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### `ClusterNodeUp`

The node is physically plugged in, turned on, booted, and capable of executing programs. This value is also
used by the
[SetClusterServiceAccountPassword](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterserviceaccountpassword)
function and [Resume](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusnode-resume) method.

### `ClusterNodeDown`

The node is turned off or not operational.

### `ClusterNodePaused`

The node is running but not participating in cluster operations. This value is also used by the
[PauseClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-pauseclusternode) and
[SetClusterServiceAccountPassword](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterserviceaccountpassword)
functions. This value is also used [Pause](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusnode-pause) method.

### `ClusterNodeJoining`

The node is in the process of joining a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[GetClusterNodeState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodestate)

[Pause Method of the ClusNode Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusnode-pause)

[PauseClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-pauseclusternode)

[SetClusterServiceAccountPassword](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterserviceaccountpassword)

[State Property of the ClusNode Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusnode-state)