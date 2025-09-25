# PWINDBG_WRITE_PROCESS_MEMORY_ROUTINE callback function

## Description

The **PWINDBG_WRITE_PROCESS_MEMORY_ROUTINE** (**WriteMemory**) function works like the Win32 **WriteProcessMemory** routine. It writes memory to the process being debugged. The entire area to be written must be accessible, or the operation fails.

## Parameters

### `offset`

Specifies the base address of the memory to be written in the process that is being debugged.

### `lpBuffer`

Points to the buffer that contains the data to be written.

### `cb`

Specifies the number of bytes that **WriteMemory** should write.

### `lpcbBytesWritten`

Receives the actual number of bytes that **WriteMemory** transferred from the buffer. This parameter is optional; if it is **NULL**, it is ignored.

## Return value

If the routine succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

For a WdbgExts extension, include wdbgexts.h. For a DbgEng extension, include wdbgexts.h before dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.