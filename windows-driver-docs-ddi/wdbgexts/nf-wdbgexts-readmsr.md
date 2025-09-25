# ReadMsr function

## Description

The **ReadMsr** function reads the contents of a Model-Specific Register (MSR).

## Parameters

### `MsrReg`

Specifies the ID number of the MSR.

### `MsrValue`

Receives the value of the MSR.

## Remarks

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).