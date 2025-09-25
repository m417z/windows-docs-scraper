# AddSIDToBoundaryDescriptor function

## Description

Adds a security identifier (SID) to the specified boundary descriptor.

## Parameters

### `BoundaryDescriptor` [in, out]

A handle to the boundary descriptor. The [CreateBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createboundarydescriptora) function returns this handle.

### `RequiredSid` [in]

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **AddSIDToBoundaryDescriptor** function must be called once for each SID to be added to the boundary descriptor.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later.

## See also

[CreateBoundaryDescriptor](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createboundarydescriptora)

[Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces)