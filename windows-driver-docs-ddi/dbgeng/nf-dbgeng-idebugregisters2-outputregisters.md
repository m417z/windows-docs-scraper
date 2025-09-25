# IDebugRegisters2::OutputRegisters

## Description

The **OutputRegisters** method formats and sends the target's [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers) to the clients as output.

## Parameters

### `OutputControl` [in]

Specifies which clients should be sent the output of the formatted registers. See [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx) for possible values.

### `Flags` [in]

Specifies which set of registers to print. This can either be DEBUG_REGISTERS_DEFAULT to print commonly used registers, DEBUG_REGISTERS_ALL to print all the sets of registers, or a combination of the values listed in the following table.

| Value | Description |
| --- | --- |
| DEBUG_REGISTERS_INT32 | Print the 32-bit register set. |
| DEBUG_REGISTERS_INT64 | Print the 64-bit register set. |
| DEBUG_REGISTERS_FLOAT | Print the floating-point register set. |

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The registers are formatted in a way that is specific to the target architecture's register set.

The method [OutputRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-outputregisters2) performs the same task as this method but also allows the register source to be specified.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers). For details on sending output to the clients, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

## See also

[IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)

[OutputRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-outputregisters2)