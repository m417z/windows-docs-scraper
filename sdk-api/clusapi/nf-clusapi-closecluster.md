# CloseCluster function

## Description

Closes a cluster handle. The **PCLUSAPI_CLOSE_CLUSTER** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to the cluster to close.

## Return value

This function always returns **TRUE**.

## Remarks

Do not close a cluster handle if there are any object handles still in use that were obtained from the cluster
handle. After a cluster handle has been closed, all handles obtained from that handle are invalid.

#### Examples

See [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles).

## See also

[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)