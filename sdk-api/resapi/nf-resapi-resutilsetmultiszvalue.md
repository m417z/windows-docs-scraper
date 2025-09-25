# ResUtilSetMultiSzValue function

## Description

Sets a multiple string value in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database). The **PRESUTIL_SET_MULTI_SZ_VALUE** type defines a pointer to this function.

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the multiple string value in the cluster database.

### `pszValueName` [in]

Null-terminated Unicode string containing the name of the value to update.

### `pszNewValue` [in]

Pointer to the new multiple string value.

### `cbNewValueSize` [in]

Size of the new value.

### `ppszOutValue` [out, optional]

Pointer to a string pointer that receives a copy of the updated value. If used, callers must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) on **ppszOutValue*.

### `pcbOutValueSize` [in, out, optional]

Pointer that receives the size of the new value.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred while attempting to allocate memory. |

## Remarks

The **ResUtilSetMultiSzValue** utility function allocates memory for the new value and calls the [Cluster API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-api) function [ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue).

A multiple string value is a large string containing smaller, contiguous, null-terminated Unicode strings and ending with an extra null character after the last string.

Be sure to call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) on **ppszOutValue* to avoid memory leaks.

Do not call **ResUtilSetMultiSzValue** from the following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ResUtilSetMultiSzValue** can be safely called from any other resource DLL entry point function or from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue)

[ResUtilSetBinaryValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetbinaryvalue)

[ResUtilSetDwordValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetdwordvalue)

[ResUtilSetExpandSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetexpandszvalue)

[ResUtilSetSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetszvalue)