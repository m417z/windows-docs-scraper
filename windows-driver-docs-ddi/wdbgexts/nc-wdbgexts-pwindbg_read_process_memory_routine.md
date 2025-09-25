# PWINDBG_READ_PROCESS_MEMORY_ROUTINE callback function

## Description

The **PWINDBG_READ_PROCESS_MEMORY_ROUTINE** (**ReadMemory**) function works like the Win32 **ReadProcessMemory** function. It reads memory from the process being debugged. The entire area to be read must be accessible, or the operation fails.

## Parameters

### `offset`

Specifies the base address of the memory to be read in the process that is being debugged.

### `lpBuffer`

Points to the buffer to receive the memory read.

### `cb`

Specifies the number of bytes that you want **ReadMemory** to read.

### `lpcbBytesRead`

Receives the actual number of bytes that **ReadMemory** transferred into the buffer. This parameter is optional; if it is **NULL**, it is ignored.

## Return value

If the routine succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).