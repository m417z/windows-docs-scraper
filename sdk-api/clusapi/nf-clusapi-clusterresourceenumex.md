# ClusterResourceEnumEx function

## Description

Enumerates a resource and then returns a pointer to the current dependent resource or node.

## Parameters

### `hResourceEnumEx` [in]

A handle to a resource enumeration that is returned from
the [ClusterResourceOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenumex) function.

### `dwIndex` [in]

The index of the resource or node object to return. This parameter should be zero for the first call to the
**ClusterResourceEnumEx** function and then be
incremented for subsequent calls.

### `pItem` [in, out]

A pointer that receives the returned object.

### `cbItem` [in, out]

On input, the size of the *pItem* parameter.

On output, either the required size in bytes of the buffer if the buffer is too small, or the number of bytes written into the buffer.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation finished successfully, or the *lpszName* parameter is **NULL**. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The buffer to which the *lpszName* parameter points is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating null character. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 (0x103) | There are no more objects to be returned. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | Any other returned error code indicates that the operation failed. |

## See also

[ClusterResourceOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenumex)

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)