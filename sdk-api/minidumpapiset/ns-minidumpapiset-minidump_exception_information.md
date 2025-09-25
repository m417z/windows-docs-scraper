# MINIDUMP_EXCEPTION_INFORMATION structure

## Description

Contains the exception information written to the minidump file by the
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump) function.

## Members

### `ThreadId`

The identifier of the thread throwing the exception.

### `ExceptionPointers`

A pointer to an
[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers) structure specifying a computer-independent description of the exception and the processor context at the time of the exception.

### `ClientPointers`

Determines where to get the memory regions pointed to by the **ExceptionPointers** member. Set to **TRUE** if the memory resides in the process being debugged (the target process of the debugger). Otherwise, set to **FALSE** if the memory resides in the address space of the calling program (the debugger process). If you are accessing local memory (in the calling process) you should not set this member to **TRUE**.

## See also

[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers)

[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)