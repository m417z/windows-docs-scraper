# CLUS_FLAGS enumeration

## Description

Identifies the resource or group as a
[core resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/core-resources).

## Constants

### `CLUS_FLAG_CORE:0x1`

Identifies [core resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/core-resources) or the cluster group that
contains core resources. The
[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) function with the
[CLUSCTL_RESOURCE_GET_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-flags) control
code can retrieve the flags that are set for a resource.

## See also

[CLUSCTL_RESOURCE_GET_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-flags)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)