# CLUSTER_GROUP_AUTOFAILBACK_TYPE enumeration

## Description

Used by the
[AutoFailbackType](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-autofailbacktype) group
[common property](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/common-properties) to specify whether the group should be
failed back to the [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) identified as its preferred owner when that
node comes back online following a [failover](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failover).

## Constants

### `ClusterGroupPreventFailback:0`

Prevents [failback](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failback).

### `ClusterGroupAllowFailback`

Allows failback (requires a preferred owners list for the group).

### `ClusterGroupFailbackTypeCount`

Defines a maximum group property value. It is not supported by the
[AutoFailbackType](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-autofailbacktype) group property.

## See also

[AutoFailbackType](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-autofailbacktype)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[common property](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/common-properties)