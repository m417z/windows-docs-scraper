# EngGetCurrentThreadId function

## Description

The **EngGetCurrentThreadId** function identifies an application's current thread.

## Return value

**EngGetCurrentThreadId** returns the 4-byte identifier of the application's thread.

## Remarks

Callers of **EngGetCurrentThreadId** should treat the returned ID as a read-only value.

## See also

[EngGetCurrentProcessId](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetcurrentprocessid)

[EngGetProcessHandle](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetprocesshandle)