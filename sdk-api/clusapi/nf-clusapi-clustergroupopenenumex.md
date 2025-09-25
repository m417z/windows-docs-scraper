# ClusterGroupOpenEnumEx function

## Description

Opens a handle to the group enumeration.The **PCLUSAPI_CLUSTER_GROUP_OPEN_ENUM_EX** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

The handle to the cluster on which the enumeration will be performed.

### `lpszProperties`

A pointer to a list of names of common properties.

### `cbProperties` [in]

The size, in bytes, of the **lpszProperties** field.

### `lpszRoProperties`

A pointer to a list of names of read-only common properties.

### `cbRoProperties` [in]

The size, in bytes, of the **lpszRoProperties** field.

### `dwFlags` [in]

Reserved for future use. This value must be 0.

## Return value

If the operation is successful, the function returns a handle to the enumeration.

If the operation fails, the function returns **NULL**.

## Remarks

The **ClusterGroupOpenEnumEx** function connects to the cluster service via remote procedure call (RPC) and gathers all of the data to handle the entire enumeration. After the RPC call completes, the data is maintained locally. The **HGROUPENUMEX** handle contains all of the data required to satisfy the enumeration. Additional calls to [ClusterGroupEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupenumex) or [ClusterGroupGetEnumCountEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupgetenumcountex) do not connect to the cluster.