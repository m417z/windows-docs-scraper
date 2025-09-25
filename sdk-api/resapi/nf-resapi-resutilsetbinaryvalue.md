# ResUtilSetBinaryValue function

## Description

Sets a binary value in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the binary value in the cluster database.

### `pszValueName` [in]

A null-terminated Unicode string containing the name of the value to update.

### `pbNewValue` [in]

Pointer to the new binary value.

### `cbNewValueSize` [in]

Size of the new binary value.

### `ppbOutValue` [in, out, optional]

Address of a pointer to the new binary value.

### `pcbOutValueSize` [in, out]

Pointer to a **DWORD** in which the size in bytes of the value pointed to by *ppbOutValue* is returned.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

The **ResUtilSetBinaryValue** utility function allocates memory for the *ppbOutValue* pointer using the function [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc), calls the [Cluster API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-api) function [ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue), and then copies the new value to this buffer. If the pointer is not **NULL**, **ResUtilSetBinaryValue** also deallocates it. As callers of this function, you are responsible for deallocating the buffer using the function [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

Do not call **ResUtilSetBinaryValue** from the following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ResUtilSetBinaryValue** can be safely called from any other resource DLL entry point function or from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue)

[ResUtilSetDwordValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetdwordvalue)

[ResUtilSetExpandSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetexpandszvalue)

[ResUtilSetMultiSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetmultiszvalue)

[ResUtilSetSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetszvalue)