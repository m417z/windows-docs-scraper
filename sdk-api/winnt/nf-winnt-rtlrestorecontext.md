# RtlRestoreContext function

## Description

Restores the context of the caller to the specified context record.

## Parameters

### `ContextRecord` [in]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure.

### `ExceptionRecord` [in]

A pointer to an [EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record) structure. This parameter is optional and should typically be **NULL**.

An exception record is used primarily with long jump and C++ catch-throw support. If the **ExceptionCode** member is STATUS_LONGJUMP, the **ExceptionInformation** member contains a pointer to a jump buffer. **RtlRestoreContext** will copy the non-volatile state from the jump buffer in to the context record before the context record is restored.

If the **ExceptionCode** member is STATUS_UNWIND_CONSOLIDATE, the **ExceptionInformation** member contains a pointer to a callback function, such as a catch handler. **RtlRestoreContext** consolidates the call frames between its frame and the frame specified in the context record before calling the callback function. This hides frames from any exception handling that might occur in the callback function. The difference between this and a typical unwind is that the data on the stack is still present, so frame data such as a throw object is still available. The callback function returns a new program counter to update in the context record, which is then used in a normal restore context.

## Return value

This function does not return a value.

## Syntax

```cpp
NTSYSAPI VOID __cdecl RtlRestoreContext(
  PCONTEXT          ContextRecord,
  _EXCEPTION_RECORD *ExceptionRecord
);
```

## See also

[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context)

[RtlCaptureContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-rtlcapturecontext)