# EngGetCurrentProcessId function

## Description

The **EngGetCurrentProcessId** function identifies an application's current process.

## Return value

**EngGetCurrentProcessId** returns the 4-byte identifier of the application's process.

## Remarks

Callers of **EngGetCurrentProcessId** should treat the returned ID as a read-only value.

## See also

[EngGetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetcurrentthreadid)

[EngGetProcessHandle](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetprocesshandle)