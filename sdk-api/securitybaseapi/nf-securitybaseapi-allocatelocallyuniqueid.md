# AllocateLocallyUniqueId function

## Description

The **AllocateLocallyUniqueId** function allocates a locally unique identifier ([LUID](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly)).

## Parameters

### `Luid` [out]

A pointer to a [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) structure that receives the allocated LUID.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The allocated [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) is unique to the local system only, and uniqueness is guaranteed only until the system is next restarted.

The allocated [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) is guaranteed to be nonzero if this function succeeds.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[LookupPrivilegeValue](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupprivilegevaluea)