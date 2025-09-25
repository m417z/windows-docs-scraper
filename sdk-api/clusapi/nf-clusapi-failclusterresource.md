# FailClusterResource function

## Description

Initiates a [resource failure](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-failure). The **PCLUSAPI_FAIL_CLUSTER_RESOURCE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) that is the target of the failure.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The resource identified by *hResource* is treated as inoperable, causing the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) to initiate the same [failover](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failover) process that would result if the resource had actually failed. Applications call the **FailClusterResource** function to test their policies for restarting resources and [groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups).

Do not call **FailClusterResource** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)