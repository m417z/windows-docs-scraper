# EngSetLastError function

## Description

The **EngSetLastError** function causes GDI to report an error code, which can be retrieved by an application.

## Parameters

### `unnamedParam1` [in]

Specifies the 32-bit error code to set.

## Return value

None

## Remarks

**EngSetLastError** sets the last error code for the calling thread. This function allows a driver to communicate error conditions to an application. To facilitate this communication, a driver should use the Win32 application error codes defined in *winerror.h*.

Only the last error code to be set is retrievable; that is, consecutive calls to **EngSetLastError** will cause the last-error code field to be overwritten.

## See also

[EngGetLastError](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetlasterror)