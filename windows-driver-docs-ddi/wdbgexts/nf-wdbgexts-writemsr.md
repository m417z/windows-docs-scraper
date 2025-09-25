# WriteMsr function

## Description

The **WriteMsr** function writes to a Model-Specific Register (MSR).

## Parameters

### `MsrReg` [in]

Specifies the ID number of the MSR.

### `MsrValue` [in]

Specifies the new value of the MSR.

## Remarks

For a WdbgExts extension, include wdbgexts.h. For a DbgEng extension, include wdbgexts.h before dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.