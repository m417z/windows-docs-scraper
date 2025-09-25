# ResUtilGetMultiSzValue function

## Description

Returns a multiple string value
from the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the multiple string value in the cluster database.

### `pszValueName` [in]

Pointer to a null-terminated Unicode string containing the name of the value to retrieve.

### `ppszOutValue` [out, optional]

Address of the pointer to the retrieved value.

### `pcbOutValueSize` [out]

Pointer to a **DWORD** in which the size in bytes of the buffer pointed to by
*ppszOutValue* is returned.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error
code.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

When you are finished with the memory allocated for the value returned by the
**ResUtilGetMultiSzValue** utility function, you must call the function
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release it.

## See also

[ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue)

[ResUtilGetBinaryValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetbinaryvalue)

[ResUtilGetDwordValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetdwordvalue)

[ResUtilGetExpandSzValue](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-resutilgetexpandszvalue)

[ResUtilGetSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetszvalue)