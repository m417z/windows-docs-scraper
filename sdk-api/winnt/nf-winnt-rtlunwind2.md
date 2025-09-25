# RtlUnwind2 function

## Description

Initiates an unwind of
procedure call frames.

## Parameters

### `TargetFrame` [in, optional]

A pointer to the call frame that is the target of the unwind. If this parameter is
**NULL**, the function performs an exit unwind.

### `TargetIp` [in, optional]

The continuation address of the unwind. This parameter is ignored if *TargetFrame*
is **NULL**.

### `ExceptionRecord` [in, optional]

A pointer to an [EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record)
structure.

### `ReturnValue` [in]

A value to be placed in the integer function return register before continuing execution.

### `ContextRecord` [in]

A pointer to a [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure that stores context
during the unwind operation.

## Return value

This function does not return a value.

## Remarks

The **FRAME_POINTERS** structure is defined as follows:

```cpp
typedef struct _FRAME_POINTERS {
    ULONGLONG MemoryStackFp;
    ULONGLONG BackingStoreFp;
} FRAME_POINTERS, *PFRAME_POINTERS;
```

## See also

[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context)

[EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record)