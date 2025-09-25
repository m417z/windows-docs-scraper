# RtlRaiseException function

## Description

Raises an exception.

## Parameters

### `ExceptionRecord` [in]

Address of an [EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record) structure
that describes the exception, and the parameters of the exception, that is raised. Raising a software exception
captures the machine state of the current thread in a context record. The
**ExceptionAddress** member of the exception record is set to the caller's return
address.

## Return value

This function does not return a value.

## See also

[EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record)