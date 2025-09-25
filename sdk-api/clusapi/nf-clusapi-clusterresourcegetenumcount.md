# ClusterResourceGetEnumCount function

## Description

Returns the number of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) associated with a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) enumeration handle. The **PCLUSAPI_CLUSTER_RESOURCE_GET_ENUM_COUNT** type defines a pointer to this function.

## Parameters

### `hResEnum` [in]

Handle to a resource enumeration. This handle is obtained from [ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum). A valid handle is required. This parameter cannot be **NULL**.

## Return value

**ClusterResourceGetEnumCount** returns the number of objects associated with the enumeration handle.