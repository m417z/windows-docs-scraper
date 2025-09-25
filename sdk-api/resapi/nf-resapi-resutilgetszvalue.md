# ResUtilGetSzValue function

## Description

Returns a string value from the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the value in the cluster database.

### `pszValueName` [in]

A null-terminated Unicode string containing the name of the value to retrieve.

## Return value

If the operation succeeds,
the function returns a pointer to a buffer containing the string value.

If the operation fails,
the function returns **NULL**. For more information, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ResUtilGetSzValue** utility function allocates the necessary memory for the string parameter value before calling the [Cluster API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-api) function [ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue) to access the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database). When you are finished with this memory, you must call the function [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release it.

**ResUtilGetSzValue** also supports expandable and multiple string formats.

## See also

[ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue)

[ResUtilGetBinaryValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetbinaryvalue)

[ResUtilGetDwordValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetdwordvalue)

[ResUtilGetExpandSzValue](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-resutilgetexpandszvalue)

[ResUtilGetMultiSzValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-resutilgetmultiszvalue)