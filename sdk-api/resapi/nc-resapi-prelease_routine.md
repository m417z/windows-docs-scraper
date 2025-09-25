# PRELEASE_ROUTINE callback function

## Description

Releases the
[quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) from arbitration. The
**PCLOSE_ROUTINE** type defines a pointer to this function.

## Parameters

### `Resource` [in]

Resource identifier for the quorum resource to be released.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The quorum resource was successfully released and is no longer being defended. |
| **[Error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The quorum resource was not successfully released. |

## Remarks

The *Release* entry-point function is implemented for quorum
resources only. A quorum resource might have to be released when the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) is shut down or when the quorum resource
has to be physically moved to a different [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) in the cluster.

**Note** All disk resources must explicitly call their own
*Release* in their implementation of the
[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) callback, since one is not made by the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service)
[Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor).

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)