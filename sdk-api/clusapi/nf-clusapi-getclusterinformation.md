# GetClusterInformation function

## Description

Retrieves a [cluster's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) name and version. The **PCLUSAPI_GET_CLUSTER_INFORMATION** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a cluster.

### `lpszClusterName` [out]

Pointer to a null-terminated Unicode string containing the name of the cluster identified by
*hCluster*.

### `lpcchClusterName` [in, out]

Pointer to the size of the *lpszClusterName* buffer as a count of characters. On
input, specify the maximum number of characters the buffer can hold, including the terminating
**NULL**. On output, specifies the number of characters in the resulting name, excluding
the terminating **NULL**.

### `lpClusterInfo` [out, optional]

Either **NULL** or a pointer to a
[CLUSTERVERSIONINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusterversioninfo) structure describing the version
of the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service). When
*lpClusterInfo* is not **NULL**, the
**dwVersionInfoSize** member of this structure should be set as follows:
`lpClusterInfo->dwVersionInfoSize = sizeof(CLUSTERVERSIONINFO);`

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is one of the
possible values.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The buffer pointed to by *lpszClusterName* is not big enough to hold the result. The *lpcchClusterName* parameter returns the number of characters in the result, excluding the terminating **NULL**. |

## Remarks

Note that *lpcchClusterName* refers to a count of characters and not a count of bytes,
and that the returned size does not include the terminating **NULL** in the count. For more
information on sizing buffers, see
[Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

## See also

[CLUSTERVERSIONINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusterversioninfo)