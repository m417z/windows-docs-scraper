# CLUS_MAINTENANCE_MODE_INFO structure

## Description

Enables or disables maintenance mode on a cluster node.

## Members

### `InMaintenance`

Set to **TRUE** to enable or **FALSE** to disable maintenance
mode for the identified resource.

When queried, a resource will return **True** or **False** to
indicate the current maintenance mode state of the resource.

## Remarks

When using [ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) to enable
or disable maintenance mode on a specified resource, the calling routine can specify a larger buffer with addition
resource-specific data by including it immediately after the
**CLUS_MAINTENANCE_MODE_INFO** structure. This
data then becomes private to the resource as it cannot be retrieved by the calling program using the
[CLUSCTL_RESOURCE_QUERY_MAINTENANCE_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-query-maintenance-mode)
control code.

## See also

[CLUSCTL_RESOURCE_QUERY_MAINTENANCE_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-query-maintenance-mode)

[CLUSCTL_RESOURCE_SET_MAINTENANCE_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-maintenance-mode)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)