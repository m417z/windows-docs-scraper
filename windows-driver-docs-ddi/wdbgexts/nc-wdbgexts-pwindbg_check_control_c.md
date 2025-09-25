# PWINDBG_CHECK_CONTROL_C callback function

## Description

The **PWINDBG_CHECK_CONTROL_C** (**CheckControlC**) function checks to see if the user pressed CTRL+C. Use **PWINDBG_CHECK_CONTROL_C** in all loops to allow the user to press CTRL+C to end long processes.

## Return value

If the user has pressed CTRL+C, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

If you are writing a WdbgExts extension, include wdbgexts.h. If you are writing a DbgEng extension that calls this function, include wdbgexts.h before dbgeng.h (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).