# EXCEPTION_POINTERS structure

## Description

Contains an exception record with a machine-independent description of an exception and a context record with a machine-dependent description of the processor context at the time of the exception.

## Members

### `ExceptionRecord`

A pointer to an
[EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record) structure that contains a machine-independent description of the exception.

### `ContextRecord`

A pointer to a
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-context) structure that contains a processor-specific description of the state of the processor at the time of the exception.

## See also

[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context)

[EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record)

[GetExceptionInformation](https://learn.microsoft.com/windows/desktop/Debug/getexceptioninformation)