# PWINDBG_STACKTRACE_ROUTINE callback function

## Description

The **PWINDBG_STACKTRACE_ROUTINE** (**StackTrace**) function retrieves a stack trace for the process being debugged. Returns the number of frames read into the buffer pointed to by *StackFrames*.

## Parameters

### `FramePointer` [in]

Specifies the frame pointer. If no specific value is desired, this should simply be set to zero.

### `StackPointer` [in]

Specifies the stack pointer. If no specific value is desired, this should simply be set to zero.

### `ProgramCounter` [in]

Specifies the instruction pointer. If no specific value is desired, this should simply be set to zero.

### `StackFrames` [out]

Receives the stack information. *StackFrames* must be a pointer to a buffer that is large enough to hold the number of stack frames specified by *Frames*. The stack frames are stored in the following data structure:

```
typedef struct _tagEXTSTACKTRACE {
    ULONG       FramePointer;
    ULONG       ProgramCounter;
    ULONG       ReturnAddress;
    ULONG       Args[4];
} EXTSTACKTRACE, *PEXTSTACKTRACE;
```

### `Frames` [in]

Specifies the maximum number of frames that will fit into the buffer.

## Return value

The actual number of frames written to the buffer pointed to by *StackFrames*.

## Remarks

For a WdbgExts extension, include Wdbgexts.h. For

a DbgEng extension, include Wdbgexts.h before

Dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for

details.