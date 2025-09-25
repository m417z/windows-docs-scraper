# ResUtilGetBinaryValue function

## Description

Returns a binary value from the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

## Parameters

### `hkeyClusterKey` [in]

Key in the cluster database that identifies the location of the value to retrieve.

### `pszValueName` [in]

Pointer to a null-terminated Unicode string containing the name of the value to retrieve.

### `ppbOutValue` [out, optional]

Address of the pointer to the retrieved value.

### `pcbOutValueSize` [out]

Pointer to a **DWORD** in which the size in bytes of the buffer pointed to by *ppbOutValue* is returned.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an error allocating memory for the value. |

## Remarks

The **ResUtilGetBinaryValue** utility function takes care of allocating the necessary memory for the value and then calls the [Cluster API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-api) function [ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue). When you are finished with the allocated memory, you must call the function [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release it.

## See also

[ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue)

[ResUtilGetDwordValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetdwordvalue)

[ResUtilGetExpandSzValue](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-resutilgetexpandszvalue)

[ResUtilGetMultiSzValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-resutilgetmultiszvalue)

[ResUtilGetSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetszvalue)