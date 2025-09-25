# ClusterGetEnumCount function

## Description

Returns the
number of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) associated with a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) enumeration handle. The **PCLUSAPI_CLUSTER_GET_ENUM_COUNT** type defines a pointer to this function.

## Parameters

### `hEnum` [in]

Handle to a cluster enumeration. This handle is obtained from
[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum). A valid handle is required. This
parameter cannot be NULL.

## Return value

**ClusterGetEnumCount** returns the number of
objects associated with the enumeration handle.