# ClusterNetworkGetEnumCount function

## Description

Returns the number of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) associated with a
[network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) enumeration handle. The **PCLUSAPI_CLUSTER_NETWORK_GET_ENUM_COUNT** type defines a pointer to this function.

## Parameters

### `hNetworkEnum` [in]

Handle to a network enumeration. This handle is obtained from
[ClusterNetworkOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkopenenum). A valid handle is
required. This parameter cannot be **NULL**.

## Return value

**ClusterNetworkGetEnumCount** returns the
number of objects associated with the enumeration handle.