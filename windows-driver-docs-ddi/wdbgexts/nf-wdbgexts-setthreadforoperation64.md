# SetThreadForOperation64 function

## Description

The **SetThreadForOperation64** function sets the thread to use for the next [StackTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_stacktrace_routine) call.

## Parameters

### `Thread`

Points to the thread object to be used for the next stack trace.

## Remarks

If you are writing 32-bit code, you should use [SetThreadForOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-setthreadforoperation) instead. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details.

For a WdbgExts extension, include Wdbgexts.h. For a DbgEng extension, include Wdbgexts.h before Dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.