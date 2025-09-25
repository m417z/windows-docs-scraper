# ClusterGroupGetEnumCount function

## Description

Returns the number of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) associated with a
[group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) enumeration handle. The **PCLUSAPI_CLUSTER_GROUP_GET_ENUM_COUNT** type defines a pointer to this function.

## Parameters

### `hGroupEnum` [in]

Handle to a group enumeration. This handle is obtained from
[ClusterGroupOpenEnum](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-clustergroupopenenum). A valid handle is
required. This parameter cannot be **NULL**.

## Return value

**ClusterGroupGetEnumCount** returns the
number of objects associated with the enumeration handle.