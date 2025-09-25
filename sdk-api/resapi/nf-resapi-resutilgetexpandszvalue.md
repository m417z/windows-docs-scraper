# ResUtilGetExpandSzValue function

## Description

[This function is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2003. This function is not exported
from ResUtils.dll and programs or DLLs that statically link to it will not load.]

Returns a [expandable string](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/e-gly) value from the
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the expandable string value in the cluster database.

### `pszValueName` [in]

Pointer to a null-terminated Unicode string containing the name of the value to retrieve.

### `bExpand` [in]

If **TRUE**, the function expands the string before returning. If
**FALSE**, the string is returned in an expandable form.

## Return value

If the operations succeeds, the function returns a null-terminated Unicode string containing a copy of the
specified value.

If the operation fails, the function returns **NULL**. For more information, see
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When you are finished with the memory allocated for the value returned by the
**ResUtilGetExpandSzValue** utility function, you
must call the function [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release it.

## See also

[ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue)

[ResUtilGetBinaryValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetbinaryvalue)

[ResUtilGetDwordValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetdwordvalue)

[ResUtilGetMultiSzValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-resutilgetmultiszvalue)

[ResUtilGetSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetszvalue)