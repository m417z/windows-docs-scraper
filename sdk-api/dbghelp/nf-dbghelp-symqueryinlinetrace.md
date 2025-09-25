# SymQueryInlineTrace function

## Description

Queries an inline trace.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `StartAddress` [in]

The start address.

### `StartContext` [in]

Contains the context of the start of block.

### `StartRetAddress` [in]

Contains the return address of the start of the current block/

### `CurAddress` [in]

Contains the current address.

### `CurContext` [out]

Address of a **DWORD** that receives the current context.

### `CurFrameIndex` [out]

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Either the *StartAddress* or *StartRetAddress* parameters must be within the same function scope as the *CurAddress* parameter. The former indicates a step-over within the same function and the latter indicates a step-over from *StartAddress*.