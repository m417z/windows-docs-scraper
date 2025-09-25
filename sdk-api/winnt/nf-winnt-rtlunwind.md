# RtlUnwind function

## Description

Initiates an unwind of procedure call frames.

## Parameters

### `TargetFrame` [in, optional]

A pointer to the call frame that is the target of the unwind. If this parameter is `NULL`, the function performs an exit unwind.

### `TargetIp` [in, optional]

The continuation address of the unwind. This parameter is ignored if *TargetFrame* is `NULL`.

### `ExceptionRecord` [in, optional]

A pointer to an [EXCEPTION_RECORD](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-exception_record) structure.

### `ReturnValue` [in]

A value to be placed in the integer function return register before continuing execution.

## Return value

This function does not return a value.

## See also

[EXCEPTION_RECORD](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-exception_record)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)