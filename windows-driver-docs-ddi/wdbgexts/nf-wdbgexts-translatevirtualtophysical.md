# TranslateVirtualToPhysical function

## Description

The **TranslateVirtualToPhysical** function translates a virtual memory address into a physical memory address.

## Parameters

### `Virtual`

Specifies the virtual memory address to translate.

### `Physical`

Receives the physical memory address.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

This function is only available in kernel-mode debugging.

If you are writing a WdbgExts extension, include wdbgexts.h. If you are writing a DbgEng extension that calls this function, include wdbgexts.h before dbgeng.h (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.)