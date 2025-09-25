# EngGetLastError function

## Description

The **EngGetLastError** function returns the last error code logged by GDI for the calling thread.

## Return value

The return value is the last error code set by **EngSetLastError**.

## Remarks

**EngGetLastError** facilitates communication of GDI and/or driver error conditions to an application.

## See also

[EngSetLastError](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsetlasterror)