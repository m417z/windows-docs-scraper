# ClusterResourceTypeGetEnumCount function

## Description

Returns the number of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) associated with a [resource_type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) enumeration handle. The **PCLUSAPI_CLUSTER_RESOURCE_TYPE_GET_ENUM_COUNT** type defines a pointer to this function.

## Parameters

### `hResTypeEnum` [in]

Handle to a resource type enumeration. This handle is obtained from [ClusterResourceTypeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeopenenum). A valid handle is required. This parameter cannot be **NULL**.

## Return value

**ClusterResourceTypeGetEnumCount** returns the number of objects associated with the enumeration handle.