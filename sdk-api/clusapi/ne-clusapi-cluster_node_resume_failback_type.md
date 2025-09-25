# CLUSTER_NODE_RESUME_FAILBACK_TYPE enumeration

## Description

Specifies the failback type to use when a cluster node in a paused state is resumed by the [ResumeClusterNodeEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-resumeclusternodeex) function.

## Constants

### `DoNotFailbackGroups:0`

Indicates that the failback process is not to be performed on the specified groups.

### `FailbackGroupsImmediately`

Indicates that the groups is to be failed back to the node.

### `FailbackGroupsPerPolicy`

Indicates that the failover policy for each group is to be used.

### `ClusterNodeResumeFailbackTypeCount`

Defines the maximum number of failback types.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[ResumeClusterNodeEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-resumeclusternodeex)