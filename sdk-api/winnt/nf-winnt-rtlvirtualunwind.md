# RtlVirtualUnwind function

## Description

Retrieves the invocation context of the function that precedes the specified function context.

> [!NOTE]
> This function is not implemented on all processor platforms and the implementation is different on each platform that supports it. The following prototype lists all the potential parameters and their application. Read further for processor-specific function prototypes.

## Parameters

### `HandlerType` [in]

The handler type. This parameter can be one of the following values.

This parameter is only present on x64.

| Value | Meaning |
| --- | --- |
| **UNW_FLAG_NHANDLER**<br><br>0x0 | The function has no handler. |
| **UNW_FLAG_EHANDLER**<br><br>0x1 | The function has an exception handler that should be called. |
| **UNW_FLAG_UHANDLER**<br><br>0x2 | The function has a termination handler that should be called when unwinding an exception. |
| **UNW_FLAG_CHAININFO**<br><br>0x4 | The **FunctionEntry** member is the contents of a previous function table entry. |

### `ImageBase` [in]

The base address of the module to which the function belongs.

### `ControlPc` [in]

The virtual address where control left the specified function.

### `FunctionEntry` [in]

The address of the function table entry for the specified function. To obtain the function table entry, call the [RtlLookupFunctionEntry](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-rtllookupfunctionentry) function.

### `ContextRecord` [in, out]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-arm64_nt_context) structure that represents the context of the previous frame.

### `HandlerData` [out]

The location of the PC. If this parameter is 0, the PC is in the prologue, epilogue, or a null frame region of the function. If this parameter is 1, the PC is in the body of the function.

This parameter is not present on x64.

### `EstablisherFrame` [out]

A pointer to a **FRAME_POINTERS** structure that receives the establisher frame pointer value. The real frame pointer is defined only if *InFunction* is `1`.

This parameter is of type **PULONG64** on x64.

### `ContextPointers` [in, out, optional]

An optional pointer to a context pointers structure.

## Return value

This function returns a pointer to an **EXCEPTION_ROUTINE** callback function.

## Remarks

The complete list of epilogue markers for x64 is as follows:

- ret
- ret *n*
- rep ret
- jmp *imm8* | *imm32* where the target is outside the function being unwound
- jmp qword ptr *imm32*
- rex.w jmp *reg*

## See also

[CONTEXT](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-arm64_nt_context)

[EXCEPTION_RECORD](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-exception_record)

[RtlLookupFunctionEntry](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-rtllookupfunctionentry)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)