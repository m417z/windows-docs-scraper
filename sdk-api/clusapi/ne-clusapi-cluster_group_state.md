# CLUSTER_GROUP_STATE enumeration

## Description

Enumerates the possible states of a
[group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups).

## Constants

### `ClusterGroupStateUnknown:-1`

The state of the group is unknown.

### `ClusterGroupOnline:206`

All of the resources in the group are [online](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/o-gly).

### `ClusterGroupOffline`

All of the resources in the group are [offline](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/o-gly) or
there are no resources in the group.

### `ClusterGroupFailed`

At least one [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in the group has failed.

### `ClusterGroupPartialOnline`

At least one resource in the group is online. No resources are
[pending](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/p-gly) or
[failed](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/f-gly).

### `ClusterGroupPending`

At least one resource in the group is in a pending state. There are no failed resources.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[GetClusterGroupState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclustergroupstate)

[State Property of the ClusResGroup Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusresgroup-state)