# ClusterGroupGetEnumCountEx function

## Description

Returns the number of elements in the enumeration.The **PCLUSAPI_CLUSTER_GROUP_GET_ENUM_COUNT_EX** type defines a pointer to this function.

## Parameters

### `hGroupEnumEx` [in]

The handle to the enumeration from which the number of entries will be returned.

## Return value

The number of items in the enumeration.

## Remarks

The **ClusterGroupGetEnumCountEx** function doesn't connect to the cluster, because *hGroupEnumEx* handle already contains the enumeration data.