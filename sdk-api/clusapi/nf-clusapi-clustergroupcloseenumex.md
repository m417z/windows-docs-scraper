# ClusterGroupCloseEnumEx function

## Description

Closes the enumeration and frees any memory held by the *hGroupEnumEx*
handle. The **PCLUSAPI_CLUSTER_GROUP_CLOSE_ENUM_EX** type defines a pointer to
this function.

## Parameters

### `hGroupEnumEx` [in]

The handle to the enumeration that will be freed.

## Return value

ERROR_SUCCESS is returned when the enumeration handle is freed.

## Remarks

Any additional calls using the *hGroupEnumEx* will fail. Do not use the
*hGroupEnumEx* handle after the
**ClusterGroupCloseEnumEx** function is
called.