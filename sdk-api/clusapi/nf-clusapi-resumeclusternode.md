# ResumeClusterNode function

## Description

Requests that a paused [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) resume its [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) activity. The **PCLUSAPI_RESUME_CLUSTER_NODE** type defines a pointer to this function.

## Parameters

### `hNode` [in]

Handle to the paused node.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)

[PauseClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-pauseclusternode)