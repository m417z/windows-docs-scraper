# ResUtilSetSzValue function

## Description

Sets a string value in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database). The **PRESUTIL_SET_SZ_VALUE** type defines a pointer to this function.

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the string value in the cluster database.

### `pszValueName` [in]

Null-terminated Unicode string containing the name of the value to update.

### `pszNewValue` [in]

Pointer to the new string value.

### `ppszOutString` [in, out, optional]

Pointer to a string pointer that receives a copy of the updated value. If used, callers must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) on **ppszOutValue*.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred while attempting to allocate memory. |

## Remarks

The **ResUtilSetSzValue** utility function allocates memory for the new value and calls the [Cluster API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-api) function [ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue). If necessary, a previous value is deallocated. The new value is copied to the content of *ppszOutValue*.

Be sure to call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) on **ppszOutValue* to avoid memory leaks.

Do not call **ResUtilSetSzValue** from the following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ResUtilSetSzValue** can be safely called from any other resource DLL entry point function or from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue)

[ResUtilSetBinaryValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetbinaryvalue)

[ResUtilSetDwordValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetdwordvalue)

[ResUtilSetExpandSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetexpandszvalue)

[ResUtilSetMultiSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetmultiszvalue)