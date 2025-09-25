# IDebugRegisters2::GetNumberPseudoRegisters

## Description

The **GetNumberPseudoRegisters** method returns the number of pseudo-registers that are maintained by the debugger engine.

## Parameters

### `Number` [out]

Receives the number of pseudo-registers that are maintained by the debugger engine.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Not all of the pseudo-registers are available in all debugging sessions or at all times in a particular session.

The valid indices for pseudo-registers are between zero and the number of pseudo-registers, minus one.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).