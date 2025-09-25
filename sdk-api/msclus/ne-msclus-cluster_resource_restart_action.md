# CLUSTER_RESOURCE_RESTART_ACTION enumeration

## Description

Used by the [RestartAction](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-restartaction) [resource common property](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-common-properties) to specify the action
to be taken by the [cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) if the
[resource fails](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-failure).

## Constants

### `ClusterResourceDontRestart:0`

Do not restart the resource after a failure.

### `ClusterResourceRestartNoNotify`

Restart the resource after a failure. If the resource exceeds its restart threshold within its restart
period, do not attempt to [failover](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failover) the
[group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) to another
[node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) in the
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `ClusterResourceRestartNotify`

Restart the resource after a failure. If the resource exceeds its restart threshold within its restart
period, attempt to fail over the group to another node in the cluster. This is the default setting.

### `ClusterResourceRestartActionCount`

Defines the maximum value of the
[CLUSTER_RESOURCE_RESTART_ACTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_restart_action) enumeration. It is not a valid value for the
[RestartAction](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-restartaction) property.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[RestartAction](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-restartaction)

[resource common property](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-common-properties)