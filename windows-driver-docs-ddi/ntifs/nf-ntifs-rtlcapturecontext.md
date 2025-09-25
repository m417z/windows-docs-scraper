# RtlCaptureContext function

## Description

The **RtlCaptureContext** function retrieves a context record in the context of the caller.

## Parameters

### `ContextRecord` [out]

A pointer to a [**CONTEXT**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-context) structure.

## Return value

This function does not return a value.

## Remarks

The captured **ContextRecord** contains processor-specific register data.

For kernel-mode code, the [**CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-context) structure is defined in *Ntddk.h*. For more information, see the [**CONTEXT**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-arm64_nt_context) structure topic in the SDK documentation.

## See also

[**CONTEXT**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-arm64_nt_context)