# ResUtilSetDwordValue function

## Description

Sets a numeric value in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database). The **PRESUTIL_SET_DWORD_VALUE** type defines a pointer to this function.

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the numeric value in the cluster database.

### `pszValueName` [in]

A null-terminated Unicode string containing the name of the value to update.

### `dwNewValue` [in]

New **DWORD** value.

### `pdwOutValue` [in, out]

Optional. Pointer to where the updated value should be copied.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **ResUtilSetDwordValue** utility function updates the cluster database by calling the [Cluster API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-api) function [ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue).

Do not call **ResUtilSetDwordValue** from the following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ResUtilSetDwordValue** can be safely called from any other resource DLL entry point function or from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ClusterRegSetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregsetvalue)

[ResUtilSetBinaryValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetbinaryvalue)

[ResUtilSetExpandSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetexpandszvalue)

[ResUtilSetMultiSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetmultiszvalue)

[ResUtilSetSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetszvalue)