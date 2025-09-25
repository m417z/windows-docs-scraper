# GetClusterQuorumResource function

## Description

Returns the name of a cluster's [quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource). The **PCLUSAPI_GET_CLUSTER_QUORUM_RESOURCE** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to an existing [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `lpszResourceName` [out]

Pointer to a null-terminated Unicode string containing the name of the cluster's quorum resource. The name is read from the quorum resource's [Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-name) common property. Do not pass **NULL** for this parameter.

### `lpcchResourceName` [in, out]

Pointer to the size of the *lpszResourceName* buffer as a count of characters. On input, specify the maximum number of characters the buffer can hold, including the terminating **NULL**. On output, specifies the number of characters in the resulting name, excluding the terminating **NULL**.

### `lpszDeviceName` [out]

Pointer to a null-terminated Unicode string containing the path to the location of the quorum log files maintained by the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service). Do not pass **NULL** for this parameter.

### `lpcchDeviceName` [in, out]

Pointer to the size of the *lpszDeviceName* buffer as a count of characters. On input, specify the maximum number of characters the buffer can hold, including the terminating **NULL**. On output, specifies the number of characters in the resulting name, excluding the terminating **NULL**.

### `lpdwMaxQuorumLogSize` [out]

Pointer to the maximum size (in bytes) of the log being maintained by the quorum resource. Do not pass **NULL** for this parameter.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is one of the possible values.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The *lpszResourceName* or the *lpszDeviceName* buffer is not big enough to hold the result. The *lpcchResourceName* and *lpcchDeviceName* parameters return the number of characters in the result, excluding the terminating **NULL**. |

## Remarks

Note that *lpcchName* refers to a count of characters and not a count of bytes, and that the returned size does not include the terminating **NULL** in the count. For more information on sizing buffers, see [Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

## See also

[Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-name)

[SetClusterQuorumResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterquorumresource)