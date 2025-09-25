# IDebugRegisters::GetNumberRegisters

## Description

The **GetNumberRegisters** method returns the number of [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers) on the target computer.

## Parameters

### `Number` [out]

Receives the number of registers on the target's computer.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).